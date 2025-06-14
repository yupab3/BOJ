#include <iostream>
#include <algorithm>

using namespace std;

int n, p, q;
bool vis[12];
long rate[12][12];
long board[12];

void    dfs(long trgt, long mul) {
    vis[trgt] = true;
    for (int i = 0; i <= 9; i++) {
        if (rate[trgt][i]) {
            if (vis[i]) continue ;
            dfs(i, mul);
        }
    }
    board[trgt] *= mul;
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> n;
    long a, b, p, q;
    fill(board, board + 11, 1);
    for (int i = 1; i < n; i++) {
        cin >> a >> b >> p >> q;
        long div = 2;
        while (div <= 9) {
            if (p % div == 0 && q % div == 0) {
                p /= div;
                q /= div;
                continue ;
            }
            div++;
        }
        p *= board[b];
        q *= board[a];
        fill(vis, vis + 11, false);
        dfs(a, p);
        fill(vis, vis + 11, false);
        dfs(b, q);
        rate[a][b] = 1;
        rate[b][a] = 1;
    }
    long div = 2;
    while (div <= 9) {
        bool flag = false;
        for (int i = 0; i < n; i++) {
            if (board[i] % div) flag = true;
        }
        if (flag) div++;
        else {
            for (int i = 0; i < n; i++) {
                board[i] /= div;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << board[i];
        if (i != n - 1) cout << ' ';
    }
}