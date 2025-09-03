#include <iostream>
#include <algorithm>
#include <tuple>
#include <queue>

using namespace std;

int n, tx, ty, tcost, sharksize = 2, cnt = 0, ans;
int board[22][22];
bool    vis[22][22];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
queue<tuple<int, int, int>>   q;

bool    checkFish() {
    bool    check = false;
    while (q.size()) {
        auto [cx, cy, cost] = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx < 1 || n < nx || ny < 1 || n < ny) continue ;
            if (board[nx][ny] > sharksize || vis[nx][ny]) continue ;
            vis[nx][ny] = true ;
            q.push({nx, ny, cost + 1});
            if (board[nx][ny] < sharksize && board[nx][ny] != 0) check = true ;
        }
    }
    return check ;
}

void    checkTrgt(int nx, int ny, int cost, int &dist) {
    if (board[nx][ny] < sharksize && board[nx][ny] != 0) {
        if (cost + 1 < dist) {
            tx = nx;
            ty = ny;
            dist = cost + 1;
        }
        else if (cost + 1 == dist) {
            if (nx < tx) {
                tx = nx;
                ty = ny;
            }
            else if (nx == tx) ty = min(ty, ny);
        }
    }
}

void    bfs() {
    int dist = 10000;
    while (q.size()) {
        auto [cx, cy, cost] = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx < 1 || n < nx || ny < 1 || n < ny) continue ;
            if (board[nx][ny] > sharksize || vis[nx][ny]) continue ;
            vis[nx][ny] = true ;
            q.push({nx, ny, cost + 1});
            checkTrgt(nx, ny, cost, dist);
        }
    }
    if (dist != 100) ans += dist;
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> board[i][j];
            if (board[i][j] == 9) {
                q.push({i, j, 0});
                tx = i;
                ty = j;
            }
        }
    }
    while (checkFish()) {
        q.push({tx, ty, 0});
        board[tx][ty] = 0;
        fill(&vis[0][0], &vis[0][0] + 22 * 22, 0);
        vis[tx][ty] = true ;
        bfs();
        if (++cnt == sharksize) {
            ++sharksize;
            cnt = 0;
        }
        board[tx][ty] = 9;
        q.push({tx, ty, 0});
        fill(&vis[0][0], &vis[0][0] + 22 * 22, 0);
        vis[tx][ty] = true ;
        // cout << "t : (" << tx << ", " << ty << ")\n";
    }
    cout << ans << '\n';
}