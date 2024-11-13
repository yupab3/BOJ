#include <iostream>
#include <vector>

using namespace std;

int	board[6][6][10];
int	smell[6][6];
int	dup[6][6][10];
int	bkup[6][6][10];
int sdx[6] = {0, -1, 0, 1, 0, 0};
int sdy[6] = {0, 0, -1, 0, 1, 0};
int mdx[10] = {0, 0, -1, -1, -1, 0, 1, 1, 1, 0};
int mdy[10] = {0, -1, -1, 0, 1, 1, 1, 0, -1, 0};
int	m, s, sx, sy, dir, maxsum, bestdir;

void	dfs(int cur_sx, int cur_sy, int count, int sum)
{
	if (!count)
	{
		if (sum == maxsum && bestdir > dir)
			bestdir = dir;
		else if (maxsum < sum)
		{
			maxsum = sum;
			bestdir = dir;
		}
		return ;
	}
	for (int i = 1; i <= 4; i++)
	{
		int snx = cur_sx + sdx[i];
		int sny = cur_sy + sdy[i];
		if (snx < 1 || 4 < snx || sny < 1 || 4 < sny) continue ;
		dir = dir * 10 + i;
		int	ate = false;
		for (int k = 1; k <= 8; k++)
		{
			if (board[snx][sny][k] > 0) ate = true;
			sum += board[snx][sny][k];
			board[snx][sny][k] = 0;
		}
		dfs(snx, sny, count - 1, sum);
		if (ate)
		{
			for (int k = 1; k <= 8; k++)
			{
				board[snx][sny][k] = bkup[snx][sny][k];
				sum -= board[snx][sny][k];
			}
		}
		dir = dir / 10;
	}
}

void	flood_fish()
{
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			for (int k = 1; k <= 8; k++)
				dup[i][j][k] = board[i][j][k];
		}
	}
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			for (int k = 1; k <= 8; k++)
			{
				if (dup[i][j][k])
				{
					board[i][j][k] -= dup[i][j][k];
					int t_dir = k;
					while (1)
					{
						if (smell[i + mdx[t_dir]][j + mdy[t_dir]] || i + mdx[t_dir] < 1 || 4 < i + mdx[t_dir] || j + mdy[t_dir] < 1 || 4 < j + mdy[t_dir] || (i + mdx[t_dir] == sx && j + mdy[t_dir] == sy))
							t_dir--;
						else
						{
							board[i + mdx[t_dir]][j + mdy[t_dir]][t_dir] += dup[i][j][k];
							cout << "(" << i << ", " << j << " // k: " << k << ") -> (" << i + mdx[t_dir] << ", " << j + mdy[t_dir] << " // k: " << t_dir << ")\n";
							break ;
						}
						if (t_dir < 1) t_dir = 8;
						if (t_dir == k) 
						{
							board[i][j][k] += dup[i][j][k];
							break ;
						}
					}
				}
			}
		}
	}
}

void	set_smell()
{
	int cur;
	int	_dir = bestdir;
	int div = 100;
	cout << bestdir << '\n';
	while (_dir)
	{
		bool	is_fish = false;
		cur = _dir / div;
		_dir -= cur * div;
		div /= 10;
		sx += sdx[cur];
		sy += sdy[cur];
		cout << sx << ", " << sy << "\n";
		for (int i = 1; i <= 8; i++)
		{
			if (board[sx][sy][i])
			{
				board[sx][sy][i] = 0;
				smell[sx][sy] = 3;
			}
		}
	}
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			if (smell[i][j])
				smell[i][j]--;
		}
	}
}

void	magic()
{
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			for (int k = 1; k <= 8; k++)
				board[i][j][k] += dup[i][j][k];
		}
	}
}

void	print_fish()
{
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			int tmp = 0;
			for (int k = 1; k <= 8; k++)
				tmp += board[i][j][k];
			cout << tmp << " ";
		}
		cout << '\n';
	}
	cout << "\n smell\n";
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			if (smell[i][j]) cout << "S ";
			else cout << "N ";
		}
		cout << '\n';
	}
}

int	main()
{
	cin >> m >> s;

	int	fx, fy, d;
	for (int i = 1; i <= m; i++)
	{
		cin >> fx >> fy >> d;
		board[fx][fy][d]++;
		dup[fx][fy][d]++;
	}
	cin >> sx >> sy;
	for (int i = 1; i <= s; i++)
	{
		cout << "case: " << i << '\n';
		print_fish();
		cout << " ************** \n";
		flood_fish();
		cout << "flood: " << i << '\n';
		print_fish();
		cout << " ************** \n";
		maxsum = 0;
		dir = 0;
		bestdir = 1e9;
		for (int i = 1; i <= 4; i++)
		{
			for (int j = 1; j <= 4; j++)
			{
				for (int k = 1; k <= 8; k++)
					bkup[i][j][k] = board[i][j][k];
			}
		}
		dfs(sx, sy, 3, 0);
		cout << "dfs: " << i << '\n';
		print_fish();
		cout << " ************** \n";
		set_smell();
		magic();
		cout << "magic: " << i << '\n';
		print_fish();
		cout << " ************** \n";
	}
	int ans = 0;
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			for (int k = 1; k <= 8; k++)
				ans += board[i][j][k];
		}
	}
	cout << ans << '\n';
	return (0);
}

// 물고기 M마리, 이동방향은 1, 1 / -1, -1 포함
// 모든 물고기가 먼저 이동, 물고기는 8방향
// 상어가 이동 상어는 4방향, 연속 3칸 이동, 마주치는 모든 물고기 제외시키고 냄새 남김 냄새는 2턴 유지
// 상어가 이동할 물고기가 가장 많은 쪽으로 이동할 수 있는 방법으로 이동한다. 여러가지인 경우 사전순으로 앞서는 녀석으로 한다.
// 사전순 = 상 하 좌 우 순서