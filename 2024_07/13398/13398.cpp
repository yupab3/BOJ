#include <iostream>

using namespace std;

int	dp[2][100005];

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int n, num, negative = 0;
	cin >> n;
	int ans = -2000000000;
	cin >> dp[0][1];
	dp[1][1] = dp[0][1];
	ans = max(dp[1][1], ans);
	for (int i = 2; i <= n; i++)
	{
		cin >> dp[0][i];
		dp[1][i] = dp[0][i];
		dp[0][i] = max(dp[0][i - 1] + dp[0][i], dp[0][i]);
		dp[1][i] = max(dp[0][i - 1], dp[1][i - 1] + dp[1][i]);
		ans = max(dp[1][i], ans);
		ans = max(dp[0][i], ans);
	}
	cout << ans << '\n';
}