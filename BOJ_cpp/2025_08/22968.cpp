#include <iostream>

int dp[45];

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    dp[1] = 1;
    for (int i = 1; i <= 43; ++i) {
        if (dp[i] > 1e9) {
            cout << "test\n";
            break ;
        }
        dp[i + 1] += dp[i];
        dp[i + 2] += dp[i];
        cout << "dp[" << i << "] : " << dp[i] << '\n';
    }

    int t;
    cin >> t;
    int trgt, cur;
    for (int i = 1; i <= t; ++i) {
        cin >> trgt;
        cur = 0;
        for (int j = 1; j <= 43; ++j) {
            cur += dp[j];
            if (trgt < cur) {
                cout << j - 1 << '\n';
                break ;
            }
        }
    }
    return 0;
}