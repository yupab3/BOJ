#include <iostream>

using namespace std;

long dp[32];

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    cin >> n;
    dp[1] = 1;
    dp[2] = 3;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + (dp[i - 2]<<1);
    }
    long gap = 0;
    if (n % 2)
        gap = dp[n>>1];
    else
        gap = dp[(n>>1) + 1];
    if (n < 3) cout << dp[n] << '\n';
    else cout << ((gap + dp[n])>>1) << '\n';
}