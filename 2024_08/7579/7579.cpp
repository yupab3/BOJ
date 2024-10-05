#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define ii pair<int, int>

size_t		dp[102][10002];
vector<ii>	apps;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	size_t	n, m, mem, cost;
	cin >> n >> m;
	apps.push_back({0, 0});
	for (int i = 1; i <= n; i++)
	{
		cin >> mem;
		apps.push_back({mem, 0});
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> cost;
		apps[i].second = cost;
	}
	// for (int i = 1; i <= n; i++)
	// {
	// 	cout << apps[i].first << ", " << apps[i].second << ' ';
	// }
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= 10000; j++)
		{
			if (j >= apps[i].second)
				dp[i][j] = max(dp[i - 1][j - apps[i].second] + apps[i].first, dp[i - 1][j]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	// for (int i = 1; i <= n; i++)
	// {
	// 	cout << i << ":  "; 
	// 	for (int j = 1; j <= 10000; j++)
	// 	{
	// 		cout << dp[i][j] << ' ';
	// 	}
	// 	cout << '\n';
	// }
	int	ans = 1e9 + 5;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= 10000; j++)
		{
			if (dp[i][j] >= m)
				ans = min(ans, j);
		}
	}
	cout << ans << '\n';
	return (0);
}

// bytes는 더하면서 진행 1 선택 0 선택x
// 