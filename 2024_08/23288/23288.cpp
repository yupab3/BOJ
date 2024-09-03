#include <iostream>
#include <queue>

using namespace std;

#define ii pair<int, int>

enum direct{
	EAST,
	SOUTH,
	WEST,
	NORTH
};

queue<ii>	q;
int	dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int	n, m, k;
int	board[22][22];
int	visit[22][22];
int	dice[4][3];
int	x, y, direction;
int tmp;
ssize_t ans;

void	spin_east()
{
	tmp = dice[3][1];
	dice[3][1] = dice[1][2];
	dice[1][2] = dice[1][1];
	dice[1][1] = dice[1][0];
	dice[1][0] = tmp;
	y++;
}

void	spin_west()
{
	tmp = dice[3][1];
	dice[3][1] = dice[1][0];
	dice[1][0] = dice[1][1];
	dice[1][1] = dice[1][2];
	dice[1][2] = tmp;
	y--;
}

void	spin_north()
{
	tmp = dice[3][1];
	dice[3][1] = dice[0][1];
	dice[0][1] = dice[1][1];
	dice[1][1] = dice[2][1];
	dice[2][1] = tmp;
	x--;
}

void	spin_south()
{
	tmp = dice[3][1];
	dice[3][1] = dice[2][1];
	dice[2][1] = dice[1][1];
	dice[1][1] = dice[0][1];
	dice[0][1] = tmp;
	x++;
}

void	init_dice()
{
	dice[0][1] = 2;
	dice[1][0] = 4;
	dice[1][1] = 1;
	dice[1][2] = 3;
	dice[2][1] = 5;
	dice[3][1] = 6;
	x = 1;
	y = 1;
}

void	do_spin()
{
	if (direction == EAST)
		spin_east();
	else if (direction == WEST)
		spin_west();
	else if (direction == SOUTH)
		spin_south();
	else if (direction == NORTH)
		spin_north();
}

void	set_direction()
{
	if (dice[3][1] > board[x][y])
		direction++;
	else if (dice[3][1] < board[x][y])
		direction--;
	if (direction == -1) direction = NORTH;
	else if (direction == 4) direction = EAST;
	if (direction == NORTH && x == 1) direction = SOUTH;
	else if (direction == SOUTH && x == n) direction = NORTH;
	else if (direction == WEST && y == 1) direction = EAST;
	else if (direction == EAST && y == m) direction = WEST;
}

void	bfs()
{
	while (q.size())
	{
		auto [cx, cy] = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 1 || n < nx || ny < 1 || m < ny) continue ;
			if (visit[nx][ny]) continue ;
			if (board[cx][cy] != board[nx][ny]) continue ;
			visit[nx][ny] = 1;
			q.push({nx, ny});
			ans += board[nx][ny];
		}
	}
}

void	printDice()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << dice[i][j];
		}
		cout << '\n';
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
		{
			cin >> board[i][j];
		}
	}
	init_dice();
	while(k--)
	{
		// if (x < 1 || x > n || y < 1 || y > m)
		// 	cout << "cur : " << x << ", " << y << " || direction : " << direction << '\n';
		// printDice();
		do_spin();
		set_direction();
		// if (x < 1 || x > n || y < 1 || y > m)
		// 	cout << "after spin : " << x << ", " << y << " || direction : " << direction << '\n';
		// printDice();
		q.push({x, y});
		fill(&visit[0][0], &visit[21][21], 0);
		visit[x][y] = 1;
		ans += board[x][y];
		bfs();
	}
	cout << ans << '\n';
	return (0);
}