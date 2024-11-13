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
	int						nx, ny;
	int						n, m;
	int						x, y;
	queue<pair<int, int> >	Q;
	pair<int, int>			cur;

	x = 0;
	cin >> n >> m;
	char	board[n][m];
	int	    vis[n][m];
	while (x < n)
	{
		y = 0;
		while (y < m)
		{
			cin >> board[x][y];
            board[x][y] -= 48;
			vis[x][y] = -1;
			y++;
		}
		x++;
	}
    x = 0;
    Q.push({0,0});
    vis[0][0] = 1;
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
            if (vis[nx][ny] != -1 || board[nx][ny] != 1)
            {
                continue;
            }
            vis[nx][ny] = vis[cur.first][cur.second] + 1;
            Q.push({nx,ny});
        }
    }
	cout << vis[n - 1][m - 1] << '\n';
}