#include <iostream>

using namespace std;

int	n, ans = 2e9;
int d[12][12];
int	visit[12];

void	dfs(int cnt, int st, int cur, int cost)
{
	if (cnt == n)
	{
		if (d[cur][st])
			ans = min(ans, cost + d[cur][st]);
		return ;
	}
	for (int i = 1; i <= n; i++)
	{
		if (visit[i]) continue ;
		if (!d[cur][i]) continue ;
		visit[i] = 1;
		dfs(cnt + 1, st, i, cost + d[cur][i]);
		visit[i] = 0;
	}
}

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cin >> d[i][j];
	}
	for (int i = 1; i <= n; i++)
	{
		visit[i] = 1;
		dfs(1, i, i, 0);
		visit[i] = 0;
	}
	cout << ans << '\n';
	return (0);
}