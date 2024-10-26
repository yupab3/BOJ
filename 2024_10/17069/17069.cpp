#include <iostream>

using namespace std;

int		board[34][34];
long	dp[34][34][3];
int		n;

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cin >> board[i][j];
	}
	dp[1][2][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 3; j <= n; j++)
		{
			if (!board[i][j])
				dp[i][j][0] += dp[i][j - 1][0] + dp[i][j - 1][1];
			if (!board[i][j] && !board[i][j - 1] && !board[i - 1][j])
				dp[i][j][1] += dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
			if (!board[i][j])
				dp[i][j][2] += dp[i - 1][j][1] + dp[i - 1][j][2];
		}
	}
	// for (int i = 1; i <= n; i++)
	// {
	// 	for (int j = 1; j <= n; j++)
	// 		cout << dp[i][j][0] << ' ';
	// 	cout << '\n';
	// }
	// for (int i = 1; i <= n; i++)
	// {
	// 	for (int j = 1; j <= n; j++)
	// 		cout << dp[i][j][1] << ' ';
	// 	cout << '\n';
	// }
	// for (int i = 1; i <= n; i++)
	// {
	// 	for (int j = 1; j <= n; j++)
	// 		cout << dp[i][j][2] << ' ';
	// 	cout << '\n';
	// }
	cout << dp[n][n][0] + dp[n][n][1] + dp[n][n][2] << '\n';
	return (0);
}