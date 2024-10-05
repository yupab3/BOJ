#include <iostream>

using namespace std;

#define ii	pair<int, int>

int	n, k;
ssize_t	a[2][102];
ssize_t	b[2][102];
ssize_t	dp[102][100002];
// 0 -> 도보 선택
// 1 -> 자전거 선택
int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= 1; j++)
		{
			int time, donation;
			cin >> time >> donation;
			if (j == 0)
			{
				a[0][i] = time;
				a[1][i] = donation;
			}
			else
			{
				b[0][i] = time;
				b[1][i] = donation;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= k; j++)
		{
			dp[i][j] = -2147483648;
			if (a[0][i] <= j)
				dp[i][j] = max(dp[i][j], dp[i - 1][j - a[0][i]] + a[1][i]);
			if (b[0][i] <= j)
				dp[i][j] = max(dp[i][j], dp[i - 1][j - b[0][i]] + b[1][i]);
		}
		// for (int i = 1; i <= n; i++)
		// {
		// 	for (int j = 1; j <= k; j++)
		// 	{
		// 		cout << dp[i][j] << ' ';
		// 	}
		// 	cout << '\n';
		// }
	}
	cout << dp[n][k] << '\n';
	return (0);
}