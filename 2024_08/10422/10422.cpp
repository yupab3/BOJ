#include <iostream>

using namespace std;

int t;
size_t	dp[5002];

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	cin >> t;
	dp[0] = 1;
	dp[2] = 1;
	for (int j = 4; j <= 5000; j += 2)
	{
		for (int k = 0; k <= j - 2; k += 2)
		{
			int tmp = j - 2;
			dp[j] += dp[tmp - k] * dp[k];
			dp[j] %= 1000000007;
		}
	}
	for (int i = 0; i < t; i++)
	{
		int tmp;
		cin >> tmp;
		cout << dp[tmp] << '\n';
	}
	return (0);
}
