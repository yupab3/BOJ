#include <iostream>

using namespace std;

int	dp[300002];
int	db[1002];
int ans = 1000000;
int n;

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	cin >> n;
	fill(&dp[0], &dp[300002], 1000000);
	for (int i = 1; i <= 121; i++)
		db[i] = db[i - 1] + i;
	for (int i = 1; i <= 121; i++)
		db[i] += db[i - 1];
	// for (int i = 121; i >= 1; i--)
	// {
	// 	int d = 1;
	// 	while (db[i] * d <= 300000 && dp[db[i] * d] == 1000000)
	// 	{
	// 		dp[db[i] * d] = d;
	// 		d++;
	// 	}
	// }
	// for (int i = 1; i <= 121; i++)
	// {
	// 	int d = 1;
	// 	while (db[i] * d <= 300000)
	// 	{
	// 		dp[db[i] * d] = d;
	// 		d++;
	// 	}
	// }
	for (int j = 1; j <= 300000; j++)
	{
		int i = 1;
		while (db[i] <= j)
		{
			dp[j] = min(dp[j], dp[j - db[i]] + 1);
			i++;
		}
	}
	cout << dp[n] << '\n';
	return (0);
}