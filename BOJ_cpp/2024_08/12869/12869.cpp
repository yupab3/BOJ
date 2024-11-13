#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

#define	iiii	tuple<int, int, int, int>
int	visit[82][82][82];

int			trgt[3];
queue<iiii>	q;
int			ans = 1e9;
int			da[6] = {-1, -1, -3, -3, -9, -9};
int			db[6] = {-3, -9, -1, -9, -1, -3};
int			dc[6] = {-9, -3, -9, -1, -3, -1};

void	bfs()
{
	while(q.size())
	{
		auto [a, b, c, cnt] = q.front();
		q.pop();
		if (visit[a][b][c]) continue ;
		visit[a][b][c] = true;
		for (int i = 0; i < 6; i++)
		{
			int	na = a + da[i];
			int	nb = b + db[i];
			int	nc = c + dc[i];
			if (na < 0) na = 0;
			if (nb < 0) nb = 0;
			if (nc < 0) nc = 0;
			if (na == 0 && nb == 0 && nc == 0)
			{
				ans = min(ans, cnt + 1);
				continue;
			}
			q.push({na, nb, nc, cnt + 1});
		}
	}
}

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int	n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> trgt[i];
	q.push({trgt[2], trgt[1], trgt[0], 0});
	bfs();
	cout << ans << '\n';
}

// #include <iostream>

// using namespace std;

// int	dp[82][82][82];
// int	trgt[3];

// int	main()
// {
// 	ios::sync_with_stdio(false);
// 	cin.tie(NULL);cout.tie(NULL);

// 	int	n;
// 	cin >> n;
// 	fill (&dp[0][0][0], &dp[81][81][82], 1e9);
// 	dp[0][0][0] = 0;
// 	for (int i = 0; i < n; i++)
// 		cin >> trgt[i];
// 	for (int i = 0; i <= trgt[2]; i++)
// 	{
// 		for (int j = 0; j <= trgt[1]; j++)
// 		{
// 			for (int k = 0; k <= trgt[0]; k++)
// 			{
// 				dp[i + 9][j + 3][k + 1] = min(dp[i][j][k] + 1, dp[i + 9][j + 3][k + 1]);
// 				dp[i + 9][j + 1][k + 3] = min(dp[i][j][k] + 1, dp[i + 9][j + 1][k + 3]);
// 				dp[i + 3][j + 9][k + 1] = min(dp[i][j][k] + 1, dp[i + 3][j + 9][k + 1]);
// 				dp[i + 3][j + 1][k + 9] = min(dp[i][j][k] + 1, dp[i + 3][j + 1][k + 9]);
// 				dp[i + 1][j + 9][k + 3] = min(dp[i][j][k] + 1, dp[i + 1][j + 9][k + 3]);
// 				dp[i + 1][j + 3][k + 9] = min(dp[i][j][k] + 1, dp[i + 1][j + 3][k + 9]);
// 			}
// 		}
// 	}
// 	int	ans = 1e9;
// 	for (int i = trgt[2]; i <= 60; i++)
// 	{
// 		for (int j = trgt[1]; j <= 60; j++)
// 		{
// 			for (int k = trgt[0]; k <= 60; k++)
// 			{
// 				ans = min(ans, dp[i][j][k]);
// 			}
// 		}
// 	}
// 	cout << ans << '\n';
// 	return (0);
// }