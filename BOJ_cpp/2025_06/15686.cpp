#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int     n, m;
int     dx[4] = {-1, 1, 0, 0};
int     dy[4] = {0, 0, -1, 1};
int     board[15][52][52];
int     dist[52][52];
int     ans = 1e9;
bool    vis[52][52];
queue<pair<int, int>>   q;
vector<pair<int, int>>  home;
vector<pair<int, int>>  store;

void    bfs(int idx) {
    while(q.size()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx < 1 || n < nx || ny < 1 || n < ny) continue ;
            if (vis[nx][ny]) continue ;
            vis[nx][ny] = true;
            board[idx][nx][ny] = board[idx][cx][cy] + 1;
            q.push({nx, ny});
        }
    }
}

void    dfs(int idx, int cnt) {
    if (cnt == m) {
        int tmp = 0;
        for (int i = 0; i < home.size(); ++i)
            tmp += dist[home[i].first][home[i].second];
        ans = min(tmp, ans);
        return ;
    }
    int bf[52][52];
    for (int i = idx; i < store.size(); ++i) {
        for (int j = 0; j < home.size(); ++j) {
            bf[home[j].first][home[j].second] = dist[home[j].first][home[j].second];
            dist[home[j].first][home[j].second] = min(board[i][home[j].first][home[j].second], dist[home[j].first][home[j].second]);
        }
        dfs(i + 1, cnt + 1);
        for (int j = 0; j < home.size(); ++j)
            dist[home[j].first][home[j].second] = bf[home[j].first][home[j].second];
    }
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> n >> m;
    int input;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> input;
            if (input == 2) store.push_back({i, j});
            if (input == 1) home.push_back({i, j});
        }
    }
    for (int i = 0; i < store.size(); ++i) {
        fill(&vis[0][0], &vis[0][0] + 52 * 52, false);
        q.push({store[i].first, store[i].second});
        bfs(i);
    }
    fill(&dist[0][0], &dist[0][0] + 52 * 52, 1e9);
    dfs(0, 0);
    cout << ans << '\n';
}