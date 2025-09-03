#include <iostream>

using namespace std;

// 왼쪽 아래, 왼쪽, 위의 값을 합치는 dp
// 구멍인 경우 이동 불가

int     n, m, k;
long    dp[1002][1002];
int     board[1002][1002];

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> n >> m >> k;
    int x, y;
    for (int i = 1; i <= k; ++i) {
        cin >> x >> y;
        board[x][y] = 1;
    }
    dp[1][1] = 1;
    bool odd = true;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == 1 && j == 1) continue ;
            if (board[j][i]) dp[j][i] = 0;
            else if (odd) dp[j][i] = (dp[j][i - 1] + dp[j - 1][i - 1] + dp[j - 1][i]) % 1000000007;
            else dp[j][i] = (dp[j][i - 1] + dp[j + 1][i - 1] + dp[j - 1][i]) % 1000000007;
        }
        odd = !odd;
    }
    // for (int i = 1; i <= n; ++i) {
    //     for (int j = 1; j <= m; ++j) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    cout << dp[n][m] << '\n';
}