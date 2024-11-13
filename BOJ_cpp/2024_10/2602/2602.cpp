#include <iostream>
#include <string>

using namespace std;

int	dp[2][21][102];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	string a, b, c;
	cin >> a >> b >> c;
	for (int i = 0; i < b.size(); i++)
	{
		if (a[0] == b[i])
			dp[0][0][i]++;
		if (a[0] == c[i])
			dp[1][0][i]++;
	}
	for (int i = 1; i < a.size(); i++)
	{
		for (int j = 0; j < b.size(); j++)
		{
			if (a[i] == b[j])
			{
				for (int k = j - 1; k >= 0; k--)
				{
					if (a[i - 1] == c[k])
						dp[0][i][j] += dp[1][i - 1][k];
				}
			}
			if (a[i] == c[j])
			{
				for (int k = j - 1; k >= 0; k--)
				{
					if (a[i - 1] == b[k])
						dp[1][i][j] += dp[0][i - 1][k];
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < b.size(); i++)
	{
		if (a[a.size() - 1] == b[i])
			ans += dp[0][a.size() - 1][i];
		if (a[a.size() - 1] == c[i])
			ans += dp[1][a.size() - 1][i];
	}
	cout << ans << '\n';
	return (0);
}