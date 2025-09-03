#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

// 상어간 거리 구하기 모든 N에서 다 돌리면서 하기, 8방향
// 최대 거리 찾기

int n, m, ans;
int board[52][52];
int cost[52][52];
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
queue<pair<int, int>> q;

void    bfs() {
    while (q.size()) {
        auto [cx, cy] = q.front();
        q.pop();
        for (int i = 0; i < 8; ++i) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx < 1 || nx > n || ny < 1 || ny > m) continue ;
            if (cost[nx][ny] <= cost[cx][cy] + 1) continue ;
            cost[nx][ny] = min(cost[nx][ny], cost[cx][cy] + 1);
            q.push({nx, ny});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> n >> m;
    fill(&cost[0][0], &cost[0][0] + 52 * 52, 1e9);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> board[i][j];
            if (board[i][j]) {
                cost[i][j] = 0;
                q.push({i, j});
                bfs();
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j)
            ans = max(ans, cost[i][j]);
    }
    cout << ans << '\n';
    return 0;
}