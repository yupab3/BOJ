#include <iostream>
#include <vector>

using namespace std;

long    l, n;
long    ans = 0;
int     dir = 3;
long    moveToDeath;
long    dx[4] = {0, 0, -1, 1};
long    dy[4] = {1, -1, 0, 0};
long    cx = 0, cy = 0, nx, ny;
vector<pair<long, long>> snake;

// 뱀의 위치를 벡터로 저장한 뒤
// 이동할 떄 모든 벡터를 순회하며 선분을 하나씩 확인해서 지나는지 확인
// 최악의 경우 10^3 * 10^3

int turnLeft(int dir) {
    if (dir == 3) return 0;
    if (dir == 0) return 2;
    if (dir == 2) return 1;
    return 3;
}

int turnRight(int dir) {
    if (dir == 3) return 1;
    if (dir == 1) return 2;
    if (dir == 2) return 0;
    return 3;
}

bool    checkHorizon(long p1x, long p1y, long p2x, long p2y) {
    long smallpy = min(p1y, p2y);
    long bigpy = max(p1y, p2y);
    if (smallpy <= ny && ny <= bigpy) {
        long smallpx = min(p1x, p2x);
        long bigpx = max(p1x, p2x);
        // cout << "p1 : (" << p1x << ", " << p1y << "), p2 : (" << p2x << ", " << p2y << ")\n";
        if (cx < smallpx && smallpx <= nx) {
            moveToDeath = min(smallpx - cx, moveToDeath);
            // cout << "End with Horizon if\n";
            return true;
        }
        else if (nx <= bigpx && bigpx < cx) {
            moveToDeath = min(cx - bigpx, moveToDeath);
            // cout << "End with Horizon else if\n";
            return true;
        }
    }
    return false;
}

bool    checkVertical(long p1x, long p1y, long p2x, long p2y) {
    long smallpx = min(p1x, p2x);
    long bigpx = max(p1x, p2x);
    if (smallpx <= nx && nx <= bigpx) {
        long smallpy = min(p1y, p2y);
        long bigpy = max(p1y, p2y);
        // cout << "p1 : (" << p1x << ", " << p1y << "), p2 : (" << p2x << ", " << p2y << ")\n";
        if (cy < smallpy && smallpy <= ny) {
            moveToDeath = min(smallpy - cy, moveToDeath);
            // cout << "End with Vertical if\n";
            return true;
        }
        else if (ny <= bigpy && bigpy < cy) {
            moveToDeath = min(cy - bigpy, moveToDeath);
            // cout << "End with Vertical else if\n";
            return true;
        }
    }
    return false;
}

bool    checkSnakeDead() {
    bool    dead = false;
    for (int i = 1; i < snake.size(); i++) {
        long     p1x = snake[i - 1].first;
        long     p1y = snake[i - 1].second;
        long     p2x = snake[i].first;
        long     p2y = snake[i].second;
        if ((dir == 0 || dir == 1) && checkVertical(p1x, p1y, p2x, p2y)) dead = true;
        else if ((dir == 2 || dir == 3) && checkHorizon(p1x, p1y, p2x, p2y))dead = true;
    }
    if (!dead) {
        if (nx < -l || l < nx || ny < -l || l < ny) {
        if (dir == 0) moveToDeath = min(moveToDeath, l - cy + 1);
        else if (dir == 1) moveToDeath = min(moveToDeath, cy + l + 1);
        else if (dir == 2) moveToDeath = min(moveToDeath, cx + l + 1);
        else moveToDeath = min(moveToDeath, l - cx + 1);
        // cout << "End with out of range\n";
        return true;
    }
    }
    return dead;
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> l >> n;
    long    dist;
    char    turn;
    bool    finished = false;
    snake.push_back({0, 0});
    for (int i = 1; i <= n; i++) {
        cin >> dist >> turn;
        if (finished) continue ;
        nx = cx + dx[dir] * dist;
        ny = cy + dy[dir] * dist;
        // cout << "(" << cx << ", " << cy << ") -> (" << nx << ", " << ny << ")\n";
        moveToDeath = 1e9 + 2;
        if (checkSnakeDead()) {
            ans += moveToDeath;
            finished = true;
        }
        else ans += dist;
        // cout << "ans : " << ans << '\n';
        snake.push_back({nx, ny});
        cx = nx;
        cy = ny;
        if (turn == 'L') dir = turnLeft(dir);
        else dir = turnRight(dir);
    }
    if (!finished) {
        // cout << "in\n";
        nx = cx + dx[dir] * 2 * (l + 1);
        ny = cy + dy[dir] * 2 * (l + 1);
        // cout << "(" << cx << ", " << cy << ") -> (" << nx << ", " << ny << ")\n";
        moveToDeath = 1e9 + 2;
        if (checkSnakeDead()) {
            // cout << ans << ", " << moveToDeath << '\n';
            ans += moveToDeath;
            finished = true;
        }
    }
    cout << ans << '\n';
}