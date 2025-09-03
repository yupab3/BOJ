#include <iostream>

using namespace std;

int n, k;
int dp[2000002];

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> n >> k;
    fill(dp, dp + 1000002, 1e9);
    dp[1] = 1;
    for (int i = 1; i <= n; ++i) {
        dp[i + 1] = min(dp[i] + 1, dp[i + 1]);
        dp[i + i / 2] = min(dp[i] + 1, dp[i + i / 2]);
    }
    if (dp[n] <= k) cout << "minigimbob\n";
    else cout << "water\n";
    return 0;
}