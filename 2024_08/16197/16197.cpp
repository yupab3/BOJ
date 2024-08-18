#include <iostream>
#include <tuple>
#include <queue>

#define	aabb	tuple<int, int, int, int, int>

using namespace std;

int			n, m, ans = 1e9 + 10;
int			visit[22][22][22][22];
char		board[22][22];
int			dx[4] = {-1, 1, 0, 0};
int			dy[4] = {0, 0, -1, 1};
queue<aabb>	q;

void	bfs()
{
	while (q.size())
	{
		auto [ca_x, ca_y, cb_x, cb_y, cost] = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int	na_x = ca_x + dx[i];
			int	na_y = ca_y + dy[i];
			int	nb_x = cb_x + dx[i];
			int	nb_y = cb_y + dy[i];
			if (board[na_x][na_y] == 0 && board[nb_x][nb_y] == 0) continue ;
			if (visit[na_x][na_y][nb_x][nb_y]) continue ;
			if (board[na_x][na_y] == '#' && board[nb_x][nb_y] == '#') continue ;
			if (board[na_x][na_y] == '#' && nb_x == ca_x && nb_y == ca_y) continue ;
			if (board[nb_x][nb_y] == '#' && na_x == cb_x && na_y == cb_y) continue ;
			visit[na_x][na_y][nb_x][nb_y] = 1;
			if (board[na_x][na_y] == 0 || board[nb_x][nb_y] == 0)
			{
				// cout << "Motherfucker = " << ca_x << ", " << ca_y << " | " << cb_x << ", " << cb_y << " -> " << na_x << ", " << na_y << " | " << nb_x << ", " << nb_y;
				ans = min(ans, cost + 1);
				// cout << " = ans: " << ans << '\n';
				continue ;
			}
			if (board[na_x][na_y] == '#')
			{
				// cout << ca_x << ", " << ca_y << " | " << cb_x << ", " << cb_y << " -> " << ca_x << ", " << ca_y << " | " << nb_x << ", " << nb_y << "\n";
				q.push({ca_x, ca_y, nb_x, nb_y, cost + 1});
			}
			else if (board[nb_x][nb_y] == '#')
			{
				// cout << ca_x << ", " << ca_y << " | " << cb_x << ", " << cb_y << " -> " << na_x << ", " << na_y << " | " << cb_x << ", " << cb_y << "\n";
				q.push({na_x, na_y, cb_x, cb_y, cost + 1});
			}
			else
			{
				// cout << ca_x << ", " << ca_y << " | " << cb_x << ", " << cb_y << " -> " << na_x << ", " << na_y << " | " << nb_x << ", " << nb_y << "\n";
				q.push({na_x, na_y, nb_x, nb_y, cost + 1});
			}
		}
	}
}

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	cin >> n >> m;
	int	a_x = -1, a_y = -1, b_x, b_y;
	for (int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 'o' && a_x == -1)
			{
				a_x = i;
				a_y = j;
			}
			else if (board[i][j] == 'o')
			{
				b_x = i;
				b_y = j;
			}
		}
	}
	visit[a_x][a_y][b_x][b_y] = 1;
	// cout << "--- start ---\n" << a_x << ", " << a_y << "   " << b_x << ", " << b_y << '\n';
	q.push({a_x, a_y, b_x, b_y, 0});
	bfs();
	if (ans > 10)
		cout << "-1\n";
	else
		cout << ans << '\n';
	return (0);
}