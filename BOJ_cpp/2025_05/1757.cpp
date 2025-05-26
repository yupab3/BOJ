#include <iostream>

using namespace std;

int n, m;
int d[10002];
int dp[10002][502];

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> d[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + d[i]);
			if (i - j > 0) dp[i][0] = max(dp[i][0], max(dp[i - 1][0], dp[i - j][j]));
		}
	}
	cout << dp[n][0] << '\n';
}
// dp[0] = 0
// dp[1] = 0
// dp[2] = max(dp[2], d[0])
// dp[3] = max(dp[3], d[1]), max(dp[3], d[0]);