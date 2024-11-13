#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int	board[52][52];
int	rot[8][3];
bool	visit[8];
int	n, m, k;
int	ans = 1e9;

void	rotate(int cur)
{
	int min_x = rot[cur][0] - rot[cur][2];
	int max_x = rot[cur][0] + rot[cur][2];
	int min_y = rot[cur][1] - rot[cur][2];
	int max_y = rot[cur][1] + rot[cur][2];
	while ((max_x - min_x) > 0 && (max_y - min_y) > 0)
	{
		int tmp = board[min_x][min_y];
		int i = min_x, j = min_y;
		for (; i < max_x; i++)
			board[i][j] = board[i + 1][j];
		for (; j < max_y; j++)
			board[i][j] = board[i][j + 1];
		for (; i > min_x; i--)
			board[i][j] = board[i - 1][j];
		for (; j > min_y + 1; j--)
			board[i][j] = board[i][j - 1];
		board[i][j] = tmp;
		min_x += 1;
		min_y += 1;
		max_x -= 1;
		max_y -= 1;
	}
}

void	re_rotate(int cur)
{
	int min_x = rot[cur][0] - rot[cur][2];
	int max_x = rot[cur][0] + rot[cur][2];
	int min_y = rot[cur][1] - rot[cur][2];
	int max_y = rot[cur][1] + rot[cur][2];
	while ((max_x - min_x) > 0 && (max_y - min_y) > 0)
	{
		int tmp = board[min_x][min_y];
		int i = min_x, j = min_y;
		for (; j < max_y; j++)
			board[i][j] = board[i][j + 1];
		for (; i < max_x; i++)
			board[i][j] = board[i + 1][j];
		for (; j > min_y; j--)
			board[i][j] = board[i][j - 1];
		for (; i > min_x + 1; i--)
			board[i][j] = board[i - 1][j];
		board[i][j] = tmp;
		min_x += 1;
		min_y += 1;
		max_x -= 1;
		max_y -= 1;
	}
}

int	check_min()
{
	int	res = 1e9;
	for (int i = 1; i <= n; i++)
	{
		int sum = 0;
		for (int j = 1; j <= m; j++)
			sum += board[i][j];
		res = min(res, sum);
	}
	return res;
}

void	dfs(int cur)
{
	if (cur == k)
	{
		ans = min(ans, check_min());
		return ;
	}
	for (int i = 1; i <= k; i++)
	{
		if (visit[i]) continue ;
		visit[i] = 1;
		rotate(i);
		dfs(cur + 1);
		re_rotate(i);
		visit[i] = 0;
	}
}

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			cin >> board[i][j];
	}
	for (int i = 1; i <= k; i++)
	{
		for (int j = 0; j < 3; j++)
			cin >> rot[i][j];
	}
	dfs(0);
	cout << ans << '\n';
	return (0);
}