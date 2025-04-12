#include <iostream>
#include <cstring>

using namespace std;


int m, n;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    while(1) {
        cin >> m >> n;
        if (m == 0 && n == 0) break;
        int board[m + 2][n + 2];
        memset(board, 0, sizeof(int) * (m + 2) * (n + 2));
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
                cin >> board[i][j];
        }
        int ans = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++)
            {
                if (j != 1) board[i][j] = max(board[i][j - 1], board[i][j] + board[i][j - 2]);
            }
            if (i != 1) board[i][n] = max(board[i - 1][n], board[i][n] + board[i - 2][n]);
            ans = max(ans, board[i][n]);
        }
        cout << ans << '\n';
    }
}