#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int	n, m, answer = -1, depth;
int	board[11][11];

void	rec(int x, int y, int dx, int dy, int cur)
{
	int tmp = static_cast<int>(sqrt(cur) + 0.5);
		if(tmp*tmp == cur)
			answer = max(answer, cur);
	// cout << x << ", " << y << " {" << dx << ", " << dy << " >> " << cur << "}\n";
	if (x + dx < 1 || n < x + dx || y + dy < 1 || m < y + dy)
		return ;
	x += dx;
	y += dy;
	rec(x, y, dx, dy, cur * 10 + board[x][y]);
}

int	main()
{
	ios::sync_with_stdio();
	cin.tie(NULL);cout.tie(NULL);

	cin >> n >> m;
	string str;
	for (int i = 1; i <= n; i++)
	{
		cin >> str;
		for (int j = 1; j <= m; j++)
			board[i][j] = str[j - 1] - 48;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			for (int k = 1 - n; k < n; k++)
			{
				for (int l = 1 - m; l < m; l++)
				{
					if (k == 0 && l == 0)
					{
						int tmp = static_cast<int>(sqrt(board[i][j]) + 0.5);
						if(tmp*tmp == board[i][j])
							answer = max(answer, board[i][j]);
					}
					else
						rec(i, j, k, l, board[i][j]);
				}
			}
		}
	}
	cout << answer << '\n';
	return (0);
}