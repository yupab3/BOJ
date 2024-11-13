#include <iostream>

using namespace std;

int	n, k, st;
int	dp[1002][1002];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	cin >> n;
	cin >> k;
	for (int i = 0; i <= 1000; i++)
	{
		dp[i][0] = 1;
		dp[i][1] = i;
	}
	for (int i = 2; i < n; i++)
	{
		for (int j = 2; j <= k; j++)
			dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % 1000000003;
	}
	cout << (dp[n - 3][k - 1] + dp[n - 1][k]) % 1000000003;
	return (0);
}