#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <map>
#include <queue>

#define ii pair<int, int>
#define	iii	tuple<int, int, int>

using namespace std;

int	dx[4] = {-1, 1, 0, 0};
int	dy[4] = {0, 0, -1, 1};
int	board[302][302] = {0, };
int	d[302][302];
priority_queue<iii>	q;
map<ii, vector<ii> >	node;
int	sx, sy, ex, ey, tx, ty, ans = 0;

void	sol()
{
	while (!q.empty())
	{
		auto [dis, cx, cy] = q.top();
		dis *= -1;
		q.pop();
		if (dis > d[cx][cy]) continue;
		for (auto next : node[{cx, cy}])
		{
			int	nx = next.first;
			int	ny = next.second;
			if (d[nx][ny] <= d[cx][cy] + board[nx][ny]) continue;
			d[nx][ny] = d[cx][cy] + board[nx][ny];
			q.push({-d[nx][ny], nx, ny}); 
			// cout << nx << ", " << ny << '\n';
		}
	}
}

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int	n, m;
	cin >> n >> m;
	cin >> sx >> sy >> ex >> ey;
	tx = ex;
	ty = ey;
	board[sx][sy] = 0;
	board[ex][ey] = 1;
	for (int i = 0; i < 302; i++)
		fill(d[i], d[i]+301, 1000000);
	d[sx][sy] = 0;
	q.push({d[sx][sy], sx, sy});
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			char	tmp;
			cin >> tmp;
			if (tmp == '1' || tmp == '0')
				board[i][j] = tmp - 48;
		}
	}
	// cout << "sx " << sx << "ex " << ex << "sy " << sy << "ey " << ey << '\n';
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				int	nx = i + dx[k];
				int	ny = j + dy[k];
				if (nx < 1 || n < nx || ny < 1 || m < ny) continue;
				node[{i, j}].push_back({nx, ny});
			}
		}
	}
	// for (int i = sx; i <= ex; i++)
	// {
	// 	for (int j = sy; j <= ey; j++)
	// 	{
	// 		cout << "---- " << i << " fuck up suck ur dick --- " << j << "\n";
	// 		for (auto next : node[{i, j}])
	// 			cout << next.first << ", " << next.second << '\n';
	// 	}
	// }
	sol();
	cout << d[tx][ty] << '\n';
}
