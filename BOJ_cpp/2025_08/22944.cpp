#include <iostream>
#include <tuple>
#include <queue>

using namespace std;

int n, h, d, k, ans = 1e9;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int board[502][502];
int vis[12][502][502];
queue<tuple<int, int, int, int, int, int>> q; // <x, y, cHp, uHp, uCnt, move>

void    bfs() {
    while (q.size()) {
        auto [cx, cy, cHp, uHp, uCnt, move] = q.front();
        if (board[cx][cy] == 'E') {
            ans = min(ans, move);
            break ;
        }
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            int nCHp = cHp;
            int nUHp = uHp;
            int nUCnt = uCnt;
            if (nx < 1 || n < nx || ny < 1 || n < ny) continue ;
            // cout << "bf : cur : (" << cx << ", " << cy << "), next : (" << nx << ", " << ny << "), cHp : " << nCHp << ", uHp : " << nUHp << ", uCnt : " << nUCnt << ", move : " << move << "\n";
            if (vis[nUCnt][nx][ny]) continue ;
            else if (board[nx][ny] == 'U') {
                nUHp = d;
                ++nUCnt;
                if (nUCnt > k) continue ;
            }
            if (board[nx][ny] != 'E') {
                if (nUHp > 0) --nUHp;
                else --nCHp;
                if (nCHp == 0) continue ;
            }
            vis[nUCnt][nx][ny] = true ;
            // cout << "af : cur : (" << cx << ", " << cy << "), next : (" << nx << ", " << ny << "), cHp : " << nCHp << ", uHp : " << nUHp << ", uCnt : " << nUCnt << ", move : " << move + 1 << "\n";
            q.push({nx, ny, nCHp, nUHp, nUCnt, move + 1});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> n >> h >> d;
    int x, y, ex, ey;
    string input;
    for (int i = 1; i <= n; ++i) {
        cin >> input;
        for (int j = 1; j <= n; ++j) {
            board[i][j] = input[j - 1];
            if (board[i][j] == 'S') {
                q.push({i, j, h, 0, 0, 0});
                vis[0][i][j] = true ;
            }
            if (board[i][j] == 'U') ++k;
            if (board[i][j] == 'E') {
                ex = i;
                ey = j;
            }
        }
    }
    bfs();
    if (ans == 1e9) ans = -1;
    cout << ans << '\n';
}