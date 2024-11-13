#include <iostream>
#include <map>


const int mod = 1000000;

using namespace std;
int	main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(0);
	int	n;
	cin >> n;
	int dp[1002][2][3];
	dp[1][0][0] = 1;
	dp[1][0][1] = 1;
	dp[1][0][2] = 0;
	dp[1][1][0] = 1;
	dp[1][1][1] = 0;
	dp[1][1][2] = 0;
	for (int i = 2; i <= n; i++)
	{
		dp[i][0][0] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2]) % mod;
		dp[i][0][1] = dp[i - 1][0][0];
		dp[i][0][2] = dp[i - 1][0][1];
		dp[i][1][0] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2] + dp[i - 1][1][0] + dp[i - 1][1][1] + dp[i - 1][1][2]) % mod;
		dp[i][1][1] = dp[i - 1][1][0];
		dp[i][1][2] = dp[i - 1][1][1];
		
	}
	int ans = 0;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			ans += dp[n][i][j];
			if (ans >= mod)
			{
				ans %= mod;
			}
		}
	}
	cout << ans << '\n';
}
