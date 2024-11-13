#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int	n, ans = 1e9;
int	dist[16][16];
int	dp[16][1 << 16];
queue<pair<int, int>> q;

void	print_data(int num)
{
	for (int i = n - 1; i >= 0; i--)
		cout << (num & (1 << i)) / (1 << i);
}

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	cin >> n;
	fill(&dp[0][0], &dp[16][0], -1);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> dist[i][j];
	}
	dp[0][1] = 0;
	for (int i = 1; i < (1 << n); i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ((i & (1 << j)) == 0 && dist[dp[][i].second][j])
			{
				dp[j][i | (1 << j)] = min(dp[j][i | (1 << j)], dp[k][i] + dist[k][j]);
			}
		}
	}
	cout << ans << '\n';
	return (0);
}
// n -> 0000000000000000 ~ 1111111111111111
// 