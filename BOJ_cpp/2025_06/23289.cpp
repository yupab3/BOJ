#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

int     r, c, k, w;
int     bdx[5][3] = {{0, 0, 0}, {-1, 0, 1}, {-1, 0, 1}, {-1, -1, -1}, {1, 1, 1}};
int     bdy[5][3] = {{0, 0, 0}, {1, 1, 1}, {-1, -1, -1}, {-1, 0, 1}, {-1, 0, 1}};
int     tdx[5] = {0, 0, 0, -1, 1};
int     tdy[5] = {0, 1, -1, 0, 0};
int     temp[22][22];
int     chg[22][22];
bool    wall[22][22][5];
bool    vis[22][22];
queue<pair<int, int>> tq;
queue<tuple<int, int, int, int>> bq;
vector<tuple<int, int, int>> blowers;
vector<pair<int, int>> targets;

// 온풍기에서 바람 전파하는 건 BFS, BFS 내부에서 벽 확인하는 로직 필요
// 벽 확인 로직 1. x, y -> x, y + 1은 둘 사이에 벽 확인 필요
// 벽 확인 로직 2. x, y -> x + 1, y + 1은 x, y와 x + 1, y 사이의 벽과 x + 1, y와 x + 1, y + 1 사이에 벽이 모두 없어야 가능
// 벽 확인 로직 3. x, y -> x - 1, y - 1은 x, y와 x - 1, y 사이의 벽과 x - 1, y와 x - 1, y - 1 사이에 벽이 모두 없어야 가능
// 온풍기가 있는 칸도 다른 온풍기에 의해 온도가 상승할 수 있다.

// 한 번 바람이 불고 나면 온도 조절 시행
// 이때 인접한 칸 사이에 벽이 있으면 조절을 수행하지 않는다.
// 인접한 칸에 각각 차이를 구한 뒤 1/4씩 나눠준다. 모든 칸에 대해 동시에 발생하므로 vis 찍으면서 중복연산 안되도록 계산한 뒤 한 번에 적용.

// 방향값 - 1 : 오, 2 : 왼, 3 : 상, 4 : 하

bool    checkWall(int x, int y, int direction, int idx) {
    if (direction == 1) {
        if (idx == 0 && (wall[x][y][3] || wall[x - 1][y][1])) return true;
        else if (idx == 1 && (wall[x][y][1])) return true;
        else if (idx == 2 && (wall[x][y][4] || wall[x + 1][y][1])) return true;
        return false;
    }
    if (direction == 2) {
        if (idx == 0 && (wall[x][y][3] || wall[x - 1][y][2])) return true;
        else if (idx == 1 && (wall[x][y][2])) return true;
        else if (idx == 2 && (wall[x][y][4] || wall[x + 1][y][2])) return true;
        return false;
    }
    if (direction == 3) {
        if (idx == 0 && (wall[x][y][2] || wall[x][y - 1][3])) return true;
        else if (idx == 1 && (wall[x][y][3])) return true;
        else if (idx == 2 && (wall[x][y][1] || wall[x][y + 1][3])) return true;
        return false;
    }
    if (direction == 4) {
        if (idx == 0 && (wall[x][y][2] || wall[x][y - 1][4])) return true;
        else if (idx == 1 && (wall[x][y][4])) return true;
        else if (idx == 2 && (wall[x][y][1] || wall[x][y + 1][4])) return true;
        return false;
    }
    return false;
}

void    blowBFS() {
    while (bq.size()) {
        auto [cx, cy, direction, val] = bq.front();
        bq.pop();
        for (int i = 0; i < 3; i++) {
            int nx = cx + bdx[direction][i];
            int ny = cy + bdy[direction][i];
            if (nx < 1 || r < nx || ny < 1 || c < ny) continue ;
            if (checkWall(cx, cy, direction, i)) continue ;
            if (vis[nx][ny]) continue ;
            temp[nx][ny] += val - 1;
            vis[nx][ny] = true;
            if (val - 1 == 1) continue ;
            bq.push({nx, ny, direction, val - 1});
        }
    }
}

void    tradeBFS() {
    while (tq.size()) {
        auto [cx, cy] = tq.front();
        tq.pop();
        for (int i = 1; i <= 4; i++) {
            int cnt;
            int nx = cx + tdx[i];
            int ny = cy + tdy[i];
            if (nx < 1 || r < nx || ny < 1 || c < ny) continue ;
            if (!wall[cx][cy][i]) chg[cx][cy] += (temp[nx][ny] - temp[cx][cy]) / 4;
            if (vis[nx][ny]) continue ;
            vis[nx][ny] = true;
            tq.push({nx, ny});
        }
    }
}

void    applyChg() {
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            temp[i][j] += chg[i][j];
            chg[i][j] = 0;
        }
    }
}

bool    checkTargets() {
    bool    result = false;
    for (auto [tx, ty] : targets) {
        if (temp[tx][ty] < k) result = true;
    }
    return result;
}

void    decreaseTemp() {
    for (int i = 1; i <= r; ++i) {
        temp[i][1] = max(0, temp[i][1] - 1);
        temp[i][c] = max(0, temp[i][c] - 1);
    }
    for (int i = 2; i < c; ++i) {
        temp[1][i] = max(0, temp[1][i] - 1);
        temp[r][i] = max(0, temp[r][i] - 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> r >> c >> k;
    int input;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> input; 
            if (input == 1) blowers.push_back({i, j + 1, input});
            else if (input == 2) blowers.push_back({i, j - 1, input});
            else if (input == 3) blowers.push_back({i - 1, j, input});
            else if (input == 4) blowers.push_back({i + 1, j, input});
            else if (input == 5) {
                targets.push_back({i, j});
                continue ;
            }
        }
    }
    cin >> w;
    int x, y, t;
    for (int i = 1; i <= w; i++) {
        cin >> x >> y >> t;
        if (t) {
            wall[x][y][1] = true;
            wall[x][y + 1][2] = true;
        }
        else {
            wall[x][y][3] = true;
            wall[x - 1][y][4] = true;
        }
    }
    int ans = 0;
    while (checkTargets()) {
        for (auto [bx, by, direction] : blowers) {
            bq.push({bx, by, direction, 5});
            temp[bx][by] += 5;
            fill(&vis[0][0], &vis[0][0] + 22 * 22 - 1, false);
            vis[bx][by] = true;
            blowBFS();
        }
        fill(&vis[0][0], &vis[0][0] + 22 * 22 - 1, false);
        tq.push({1, 1});
        vis[1][1] = true;
        tradeBFS();
        applyChg();
        decreaseTemp();
        ++ans;
        if (ans > 100) break ;
    }
    cout << ans << '\n';
}