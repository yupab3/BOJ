#include <iostream>
#include <string>
#include <queue>
#include <tuple>

using namespace std;

#define	iiii	tuple<int, int, int, int>
#define ii		pair<int, int>

int n, m, ans = 2e9 + 5, gar = 2e9 + 5;
char	board[52][52];
ii		visit[52][52];
int		dx[4] = {-1, 1, 0, 0};
int		dy[4] = {0, 0, -1, 1};
queue<iiii>	q;

bool	chk_garbage(int nx, int ny)
{
	bool	res = false;
	if (nx > 1)
	{
		if (board[nx - 1][ny] == 'g')
			res = true;
	}
	if (nx < n)
	{
		if (board[nx + 1][ny] == 'g')
			res = true;
	}
	if (ny > 1)
	{
		if (board[nx][ny - 1] == 'g')
			res = true;
	}
	if (ny < m)
	{
		if (board[nx][ny + 1] == 'g')
			res = true;
	}
	return res;
}

void	bfs()
{
	while(q.size())
	{
		auto [cx, cy, cost, side] = q.front();
		q.pop();
		if (board[cx][cy] == 'F')
		{
			if (cost == ans)
				gar = min(gar, side);
			else if (cost < ans)
				gar = side;
			ans = min(ans, cost);
			continue ;
		}
		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 1 || n < nx || ny < 1 || m < ny) continue ;
			if (visit[nx][ny].first < cost || (visit[nx][ny].first == cost && board[nx][ny] == 'g')) continue ;
			// cout << "c: (" << cx << ", " << cy << ") -> " << "n: (" << nx << ", " << ny << "), visit[nx][ny]: (" << visit[nx][ny].first << ", " << visit[nx][ny].second << ")\n";
			if (board[nx][ny] == 'g')
			{
				if (visit[nx][ny].first == cost + 1 && visit[nx][ny].second <= side) continue ;
				visit[nx][ny].first = cost + 1;
				visit[nx][ny].second = side;
			}
			else if (board[nx][ny] == '.')
			{
				if (cost < visit[nx][ny].first)
				{
					visit[nx][ny].second = chk_garbage(nx, ny) + side;
					visit[nx][ny].first = cost;
				}
				else if (chk_garbage(nx, ny) + side < visit[nx][ny].second)
					visit[nx][ny].second = chk_garbage(nx, ny) + side;
				else
					continue ;
			}
			else
			{
				if (visit[nx][ny].first == cost && visit[nx][ny].second <= side) continue ;
				visit[nx][ny].first = cost;
				visit[nx][ny].second = side;
			}
			q.push({nx, ny, visit[nx][ny].first, visit[nx][ny].second});
		}
	}
}

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	cin >> n >> m;
	int	sx, sy;
	for (int i = 1; i <= n; i++)
	{
		string	str;
		cin >> str;
		for (int j = 0; j < m; j++)
		{
			board[i][j + 1] = str[j];
			if (str[j] == 'S')
			{
				sx = i;
				sy = j + 1;
			}
			visit[i][j + 1] = {1e9 + 5, 1e9 + 5};
		}
	}
	visit[sx][sy] = {0, 0};
	q.push({sx, sy, 0, 0});
	bfs();
	
	cout << ans << ' ' << gar << '\n';
	return (0);
}