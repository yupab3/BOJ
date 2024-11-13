#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int	main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int						dx[4] = {1, 0, -1, 0};
	int						dy[4] = {0, 1, 0, -1};
	int						count;
	int						max_size;
	int						nx, ny;
	int						n, m;
	int						x, y;
	queue<pair<int, int> >	Q;
	pair<int, int>			cur;

	count = 0;
	max_size = 0;
	x = 0;
	cin >> n >> m;
	int		board[n][m];
	bool	vis[n][m];
	while (x < n)
	{
		y = 0;
		while (y < m)
		{
			cin >> board[x][y];
			vis[x][y] = 0;
			y++;
		}
		x++;
	}
	x = 0;
	while (x < n)
	{
		y = 0;
		while (y < m)
		{
			if (board[x][y] == 1 && vis[x][y] == 0)
			{
				int	cur_size = 1;
				Q.push({x,y});
				vis[x][y] = 1;
				while (!Q.empty())
				{
					cur = Q.front();
					Q.pop();
					for (int dir = 0; dir < 4; dir++)
					{
						nx = cur.first + dx[dir];
						ny = cur.second + dy[dir];
						if (nx < 0 || nx >= n || ny < 0 || ny >= m)
						{
							continue;
						}
						if (vis[nx][ny] || board[nx][ny] != 1)
						{
							continue;
						}
						cur_size++;
						vis[nx][ny] = 1;
						Q.push({nx,ny});
					}
				}
				max_size = max(max_size, cur_size);
				count++;
			}
			y++;
		}
		x++;
	}
	cout << count << '\n' << max_size << '\n';
}