#include <iostream>

using namespace std;

int	dp[10002][10002];

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int	n, money; double m;
	while (cin >> n >> m)
	{
		if (n == 0) break ;
		money = static_cast<int>(m * 100 + 0.0000001);
		int	calorie, cost; double tmp_d;
		for (int i = 1; i <= n; i++)
		{
			cin >> calorie >> tmp_d;
			cost = static_cast<int>(tmp_d * 100 + 0.0000001);
			int	cur_cost = cost;
			for (int j = 1; j < cost; j++)
				dp[i][j] = dp[i - 1][j];
			for (int j = cost; j <= money; j++)
				dp[i][j] = max(dp[i][j - cost] + calorie, dp[i - 1][j]);
		}
		cout << dp[n][money] << '\n';
	}
	return (0);
}