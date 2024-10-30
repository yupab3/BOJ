#include <iostream>

using namespace std;

#define INF 1000000000

long	dp[1000002];

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int n;
	cin >> n;
	dp[2] = 1;
	for (int i = 3; i <= n; i++)
		dp[i] = ((i - 1) * dp[i - 1] + (i - 1) * dp[i - 2]) % INF;
	cout << dp[n];
	return (0);
}