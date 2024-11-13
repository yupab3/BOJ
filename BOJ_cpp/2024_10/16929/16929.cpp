#include <iostream>
#include <queue>

using namespace std;

enum direction
{
	RIGHT,
	DOWN,
	LEFT,
	UP,
	CHKRES
};

#define ii pair<int, int>

queue<ii>	q;
int		n, m, ans, ox, oy;
char	board[52][52];
int		visit[52][52];
int		dx[4] = {-1, 1, 0, 0};
int		dy[4] = {0, 0, -1, 1};

void	dfs(int x, int y, int dir)
{
	if (dir == RIGHT)
	{
		for (int i = y + 1; i <= m; i++)
		{
			if (board[x][y] != board[x][i]) break ;
			dfs(x, i, dir + 1);
		}
	}
	else if (dir == DOWN)
	{
		for (int i = x + 1; i <= n; i++)
		{
			if (board[x][y] != board[i][y]) break ;
			dfs(i, y, dir + 1);
		}
	}
	else if (dir == LEFT)
	{
		for (int i = y - 1; i > 0; i--)
		{
			if (board[x][y] != board[x][i]) break ;
			dfs(x, i, dir + 1);
		}
	}
	else if (dir == UP)
	{
		for (int i = x - 1; i > 0; i--)
		{
			if (board[x][y] != board[i][y]) break ;
			// cout << x << ", " << y << " -> " << i << ", " << y << '\n';
			dfs(i, y, dir + 1);
		}
	}
	else if (dir == CHKRES && board[ox][oy] == board[x][y]) ans = 1;
}

void	bfs()
{
	while(q.size())
	{
		auto [cx, cy] = q.front(); q.pop();
		ox = cx;
		oy = cy;
		dfs(cx, cy, RIGHT);
		if (ans) break ;
		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 1 || ny < 1 || n < nx || m < ny) continue ;
			if (visit[nx][ny]) continue ;
			q.push({nx, ny}); visit[nx][ny] = 1;
		}
	}
}

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			cin >> board[i][j];
	}
	q.push({1, 1});
	visit[1][1] = 1;
	bfs();
	if (ans) cout << "Yes\n";
	else cout << "No\n";
	return (0);
}