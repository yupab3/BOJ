#include <iostream>
#include <queue>

using namespace std;

#define ii pair<int, int>

queue<ii>	same_q;
queue<ii>	other_q;
int	n, m, ans;
int	board[102][72];
int	visit[102][72];
int	dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int	dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

void	bfs()
{
	while(other_q.size())
	{
		auto [ocx, ocy] = other_q.front(); other_q.pop();
		if (visit[ocx][ocy]) continue ;
		// cout << "start x: " << ocx << ", y: " << ocy << '\n';
		same_q.push({ocx, ocy});
		visit[ocx][ocy] = 1;
		int success = 1;
		while(same_q.size())
		{
			auto [cx, cy] = same_q.front(); same_q.pop();
			for (int i = 0; i < 8; i++)
			{
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				if (nx < 1 || ny < 1 || n < nx || m < ny) continue ;
				if (board[nx][ny] > board[cx][cy]) success = 0;
				if (visit[nx][ny]) continue ;
				if (board[nx][ny] == board[cx][cy])
				{
					visit[nx][ny] = 1;
					same_q.push({nx, ny});
				}
				else
				{
					other_q.push({nx, ny});
				}
			}
		}
		if (success) ans++;
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
	other_q.push({1, 1});
	bfs();
	cout << ans << '\n';
	return (0);
}