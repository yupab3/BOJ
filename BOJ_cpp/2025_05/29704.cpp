#include <iostream>

using namespace std;

int n, t;
int d[1002];
int m[1002];
int dp[1002];

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> n >> t;
    int totalM = 0;
    for (int i = 1; i <= n; i++) {
        cin >> d[i] >> m[i];
        totalM += m[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = t; j > 0; j--) {
            if (j - d[i] < 0) break ;
            dp[j] = max(dp[j], dp[j - d[i]] + m[i]);
        }
    }
    cout << totalM - dp[t] << '\n';
}