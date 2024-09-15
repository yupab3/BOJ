#include <iostream>

using namespace std;

int	main()
{
	int	dp[32] = {0, };
	dp[0] = 1;
	dp[1] = 0;
	dp[2] = 3;
	int n;
	cin >> n;
	if (n % 2 == 1)
	{
		cout << "0\n";
		return (0);
	}
	for (int i = 4; i <= n; i += 2)
	{
		int tmp = 0;
		while (tmp < i)
		{
			tmp += 2;
			dp[i] += dp[i - tmp];
		}
		dp[i] = dp[i - 2] + dp[i] * 2;
	}
	cout << dp[n] << '\n';
	return (0);
}