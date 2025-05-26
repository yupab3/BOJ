#include <iostream>

using namespace std;

// 목표 명수 : C
// 도시의 수 : N
// 목표 : 최소 비용

int n, c, ans = 1e9;
int cost[22];
int p[22];
int dp[100002];

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> c >> n;
    for (int i = 1; i <= n; i++)
        cin >> cost[i] >> p[i];
    for (int i = 1; i <= 100000; i++) {
        for (int j = 1; j <= n; j++) {
            if (i < cost[j]) continue ;
            dp[i] = max(dp[i], dp[i - cost[j]] + p[j]);
            if (dp[i] >= c) {
                cout << i << '\n';
                return 0;
            }
        }
    }
}