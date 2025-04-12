#include <iostream>
#include <unordered_map>

using namespace std;

int     n, m, k;
char    board[12][12];
int     dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int     dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

unordered_map<string, int>    s;
string              trgt;

void dfs(int x, int y, int idx, string &cur) {
    if (idx == trgt.length()) {
        s[cur]++;
        return ;
    }
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 1) nx = n;
        else if (nx > n) nx = 1;
        if (ny < 1) ny = m;
        else if (ny > m) ny = 1;
        if (board[nx][ny] != trgt[idx]) continue ;
        cur.push_back(board[nx][ny]);
        dfs(nx, ny, idx + 1, cur);
        cur.pop_back();
    }
};

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        string tmp;
        cin >> tmp;
        for (int j = 1; j <= m; j++) {
            board[i][j] = tmp[j - 1];
        }
    }
    while (k--) {
        cin >> trgt;
        if (s.find(trgt) == s.end()) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j ++) {
                    if (board[i][j] == trgt[0]){
                        string cur = "";
                        cur.push_back(board[i][j]);
                        dfs(i, j, 1, cur);
                        cur.pop_back();
                    }
                }
            }
        }
        cout << s[trgt] << '\n';
    }
}