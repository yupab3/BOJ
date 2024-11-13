#include <iostream>

using namespace std;

int	main(int argc, char **argv)
{
	ios::sync_with_stdio(0);
	std::cin.tie(0);
	int	t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int	ans = 0;
		int	n, m, k;
		int	dp[2][100005];
		cin >> n >> m >> k;
		for (int j = 0; j < n; j++)
		{
			cin >> dp[0][j];
			dp[1][j] = 0;
		}
		dp[1][0] = dp[0][0];
		for (int j = 1; j < n; j++)
		{
			if (j < m)
				dp[1][j] = dp[1][j - 1] + dp[0][j];
			else
				dp[1][j] = dp[1][j - 1] + dp[0][j] - dp[0][j - m];
		}
		dp[1][0] = dp[1][n - 1] + dp[0][0] - dp[0][n - m];
		for (int j = 1; j < m; j++)
		{
			dp[1][j] = dp[1][j - 1] + dp[0][j] - dp[0][n - m + j];
		}
		for (int j = 0; j < n; j++)
		{
			if (dp[1][j] < k)
				ans++;
		}
		if (n == m)
		{
			if (ans)
				ans = 1;
		}
		std::cout << ans << '\n';
	}
	return (0);
}