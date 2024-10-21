#include <iostream>

using namespace std;

int	board[102][102];
int n, m, r;

void	rotate_board(int option)
{
	int tmp[102];
	if (option == 1)
	{
		for (int i = 1; i <= n / 2; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				tmp[j] = board[i][j];
				board[i][j] = board[n - i + 1][j];
				board[n - i + 1][j] = tmp[j];
			}
		}
	}
	else if (option == 2)
	{
		for (int i = 1; i <= m / 2; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				tmp[j] = board[j][i];
				board[j][i] = board[j][m - i + 1];
				board[j][m - i + 1] = tmp[j];
			}
		}
	}
	else if (option == 3)
	{
		int tmp[102][102];
		for (int k = 1; k <= 3; k++)
		{
			for (int i = 1; i <= m; i++)
			{
				for (int j = 1; j <= n; j++)
					tmp[i][j] = board[j][m - i + 1];
			}
			int tt = n;
			n = m;
			m = tt;
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= m; j++)
					board[i][j] = tmp[i][j];
			}
		}
	}
	else if (option == 4)
	{
		int tmp[102][102];
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
				tmp[i][j] = board[j][m - i + 1];
		}
		int tt = n;
		n = m;
		m = tt;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
				board[i][j] = tmp[i][j];
		}
	}
	else if (option == 5)
	{
		int tmp[102][102];
		for (int i = 1; i <= m / 2; i++)
		{
			for (int j = 1; j <= n / 2; j++)
			{
				tmp[j][i] = board[n / 2 + j][i];
				tmp[n / 2 + j][i] = board[n / 2 + j][m / 2 + i];
				tmp[n / 2 + j][m / 2 + i] = board[j][m / 2 + i];
				tmp[j][m / 2 + i] = board[j][i];
			}
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
				board[i][j] = tmp[i][j];
		}
	}
	else if (option == 6)
	{
		int tmp[102][102];
		for (int i = 1; i <= m / 2; i++)
		{
			for (int j = 1; j <= n / 2; j++)
			{
				tmp[n / 2 + j][i] = board[j][i];
				tmp[n / 2 + j][m / 2 + i] = board[n / 2 + j][i];
				tmp[j][m / 2 + i] = board[n / 2 + j][m / 2 + i];
				tmp[j][i] = board[j][m / 2 + i];
			}
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
				board[i][j] = tmp[i][j];
		}
	}
}

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			cin >> board[i][j];
	}
	while (r--)
	{
		int option;
		cin >> option;
		rotate_board(option);
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cout << board[i][j];
			if (j != m) cout << ' ';
		}
		cout << '\n';
	}
	return (0);
}