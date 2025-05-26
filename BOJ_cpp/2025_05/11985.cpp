#include <iostream>

using namespace std;

long n, m, k;
long dp[20002];
long a[20002];

// K + s × (a − b)
// 1 2 3 4 5 6 7 --- 20000
// c번째 = c - F 번쨰 값과 c - F + 1부터 

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> n >> m >> k;
    for (long i = 1; i <= n; i++) {
        cin >> a[i];
        dp[i] = k * i;
    }
    for (long i = 1; i <= n; i++) {
        long vMin = a[i], vMax = a[i];
        for (long j = 0; j < m; j++) {
            if (i - j == 0) break ;
            vMin = min(vMin, a[i - j]);
            vMax = max(vMax, a[i - j]);

            dp[i] = min(dp[i], k + (j + 1) * (vMax - vMin) + dp[i - j - 1]);
        }
    }
    cout << dp[n] << '\n';
}
