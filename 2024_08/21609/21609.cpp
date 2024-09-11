#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
#include <queue>

using namespace std;

#define ii pair<int, int>

int	n, m, ans, score, bf_rainbow;
int	board[22][22];
int	visit[22][22];
int	dx[4] = {0, 0, 1, -1};
int	dy[4] = {1, -1, 0, 0};
bool	eeee;
queue<ii>	que;
queue<ii>	target;

void	print_arr()
{
	cout << '\n';
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << (char)(board[i][j] == -2 ? ' ' : (char)board[i][j] + '0') << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

void	real_bfs()
{
	auto [ctx, cty] = target.front();
	int	cur_val = board[ctx][cty];
	visit[ctx][cty] = true;
	// cout << "real: " << ctx << ", " << cty << '\n';
	board[ctx][cty] = -2;
	while (target.size())
	{
		auto [cx, cy] = target.front();
		target.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 1 || nx > n || ny < 1 || ny > n) continue ;
			if (visit[nx][ny]) continue ;
			if (board[nx][ny] < 0) continue ;
			if (board[nx][ny] != 0 && board[nx][ny] != cur_val) continue ;
			visit[nx][ny] = true;
			board[nx][ny] = -2;
			target.push({nx, ny});
		}
	}
	ans += score * score;
	score = 0;
}

void	fake_bfs()
{
	int rainbow = 0;
	int cur = 0;
	int	normal_block = 1;
	auto [ctx, cty] = que.front();
	visit[ctx][cty] = true;
	while (que.size())
	{
		auto [cx, cy] = que.front();
		que.pop();
		cur++;
		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 1 || nx > n || ny < 1 || ny > n) continue ;
			if (visit[nx][ny]) continue ;
			if (board[nx][ny] < 0) continue ;
			if (board[nx][ny] != 0 && board[nx][ny] != board[ctx][cty]) continue ;
			if (board[nx][ny] == 0) rainbow++;
			else normal_block++;
			visit[nx][ny] = true;
			que.push({nx, ny});
			// cout << nx << ", " << ny << '\n';
		}
	}
	// cout << ctx << ", " << cty << " >> " << cur << '\n';
	if (normal_block)
	{
		if (target.empty())
		{
			if (cur > 1)
			{
				score = cur;
				bf_rainbow = rainbow;
				target.push({ctx, cty});
			}
		}
		else if (score == cur)
		{
			auto [tx, ty] = target.front();
			if (bf_rainbow < rainbow)
			{
				bf_rainbow = rainbow;
				target.pop();
				target.push({ctx, cty});
			}
			else if (bf_rainbow == rainbow && (ctx > tx || (tx == ctx && cty > ty)))
			{
				target.pop();
				target.push({ctx, cty});
			}
		}
		else if (score < cur)
		{
			bf_rainbow = rainbow;
			score = cur;
			target.pop();
			target.push({ctx, cty});
		}
	}
}

void	gravity()
{
	for (int i = n; i > 0; i--)
	{
		for (int j = 1; j <= n; j++)
		{
			while (board[i][j] == -2)
			{
				int 	idx = i;
				bool	empty = true;
				while (idx > 1)
				{
					if (board[idx][j] == -1) break ;
					if (board[idx - 1][j] != -1)
					{
						board[idx][j] = board[idx - 1][j];
						board[idx - 1][j] = -2;
					}
					if (board[idx][j] != -2) empty = false;
					idx--;
				}
				if (empty) break ;
			}
		}
	}
}

void	rotate_sungyoon()
{
	int	tmp_arr[22][22];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			tmp_arr[i][j] = board[j][n - i + 1];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			board[i][j] = tmp_arr[i][j];
		}
	}
}

void	clear_0()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (board[i][j] == 0)
				visit[i][j] = false;
		}
	}
}

void	autoplay()
{
	memset(&visit[0][0], 0, sizeof(int) * 22 * 22);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (board[i][j] > 0 && visit[i][j] == 0)
			{
				que.push({i, j});
				fake_bfs();
				clear_0();
			}
		}
	}
	memset(&visit[0][0], 0, sizeof(int) * 22 * 22);
	if (!target.empty())
		real_bfs();
	else eeee = true;
}

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> board[i][j];
		}
	}
	while (1)
	{
		autoplay();
		if (eeee) break ;
		gravity();
		rotate_sungyoon();
		gravity();
	}
	cout << ans << '\n';
	return (0);
}
