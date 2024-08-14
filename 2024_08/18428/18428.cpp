#include <iostream>

using namespace std;

int n;
bool	finish = false;
int	board[7][7] = {0, };
int	dx[4] = {1, -1, 0, 0};
int	dy[4] = {0, 0, -1, 1};

void	checker()
{
	int	error = 0;
	for (int i = 1; i <= n; i++)
	{
		if (error)
			break ;
		for (int j = 1; j <= n; j++)
		{
			if (error)
				break ;
			if (board[i][j] == 10)
			{
				int	cx = i, cy = j;
				for (int k = 0; k <= 3; k++)
				{
					int	d = 1;
					while (1)
					{
						int nx = cx + dx[k] * d;
						int ny = cy + dy[k] * d;
						if (nx > n || ny > n || nx < 1 || ny < 1) break ;
						if (board[nx][ny] == 1) break ;
						if (board[nx][ny] == 6)
						{
							error = 1;
							break ;
						}
						d++;
					}
					if (error)
						break ;
				}
			}
		}
	}
	if (!error)
		finish = true;
}

void	sol(int m)
{
	if (finish)
		return ;
	if (m == 0)
	{
		checker();
		return ;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (board[i][j] == 0)
			{
				board[i][j] = 1;
				sol(m - 1);
				board[i][j] = 0;
			}
		}
	}
}

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			char tmp;
			cin >> tmp;
			if (tmp == 'S')
				board[i][j] = 6;
			else if (tmp == 'T')
				board[i][j] = 10;
		}
	}
	sol(3);
	if (finish)
		cout << "YES\n";
	else
		cout << "NO\n";
	return (0);
}

//선생님 T or 학생 S or 장애물 O
//선생님 = 상하좌우 감시 -> O에 막힘