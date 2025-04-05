#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int n, m, a, b, k, x, y, ans = 300000;
int board[502][502];
int v[502][502];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
queue<tuple<int, int, int>> q;

bool    checkLine(int cx, int cy, int dir) {
    if (dir == 1) {
        for (int i =  0; i < b; i++) {
            int tx = cx - 1;
            int ty = cy + i;
            if (tx > n || ty > m || tx < 1 || ty < 1) return false;
            if (board[tx][ty] == 1) return false;
        }
        return true;
    }
    if (dir == 2) {
        for (int i =  0; i < b; i++) {
            int tx = cx + a;
            int ty = cy + i;
            if (tx > n || ty > m || tx < 1 || ty < 1) return false;
            if (board[tx][ty] == 1) return false;
        }
        return true;
    }
    if (dir == 3) {
        for (int i =  0; i < a; i++) {
            int tx = cx + i;
            int ty = cy - 1;
            if (tx > n || ty > m || tx < 1 || ty < 1) return false;
            if (board[tx][ty] == 1) return false;
        }
        return true;
    }
    if (dir == 4) {
        for (int i =  0; i < a; i++) {
            int tx = cx + i;
            int ty = cy + b;
            if (tx > n || ty > m || tx < 1 || ty < 1) return false;
            if (board[tx][ty] == 1) return false;
        }
        return true;
    }
    return false;
}

void    bfs() {
    while (q.size()) {
        auto [cx, cy, cost] = q.front();
        // cout << "cx : " << cx << ", cy : " << cy << ", cost : " << cost << '\n';
        q.pop();
        if (cx == x && cy == y) {
            ans = min(ans, cost);
            continue ;
        }
        // cout << "1\n";
        for (int i = 1; i <= 4; i++) {
            int nx = cx + dx[i - 1];
            int ny = cy + dy[i - 1];
            // cout << "nx ny : " << nx << " " << ny << ", i : " << i << ", 2\n";
            if (v[nx][ny]) continue ;
            if (!checkLine(cx, cy, i)) continue ;
            v[nx][ny] = 1;
            // cout << "Added : nx, ny - " << nx << ", " << ny << '\n';
            q.push({nx, ny, cost + 1});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    cin >> n >> m >> a >> b >> k;
    for (int i = 1; i <= k; i++) {
        cin >> x >> y;
        board[x][y] = 1;
        v[x][y] = 1;
    }
    cin >> x >> y;
    v[x][y] = 1;
    q.push({x, y, 0});
    cin >> x >> y;
    bfs();
    if (ans == 300000) ans = -1;
    cout << ans << '\n';
}
// n, m 사이즈 안에서 하나의 좌표 기준으로 4개 면을 검사하여 이동.
// 이때 검사하는 길이는 a, b에 따라 바뀜.