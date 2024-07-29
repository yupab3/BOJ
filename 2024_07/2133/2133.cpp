#include <iostream>

using namespace std;

int	main()
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	int n;
	int dp[33];
	dp[1] = 0;
	dp[2] = 3;
	dp[3] = 0;
	int z = 2;
	cin >> n;
	for (int i = 4; i <= n; i++)
	{
		if (i % 2 == 1)
		{
			dp[i] = 0;
		}
		else if (i == z * 2)
		{
			dp[i] = dp[i - z] * dp[i - z] + 2;
			z *= 2;
		}
		else
		{
			dp[i] = dp[i - 2] * 3;
		}
	}
	std::cout << dp[n] << '\n';
}