#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>

using 	namespace std;

int	board[50][5];

int	main()
{
	int	r1, c1, r2, c2, max_num = 0;
	cin >> r1 >> c1 >> r2 >> c2;
	for (int i = r1; i <= r2; i++)
	{
		for (int j = c1; j <= c2; j++)
		{
			int cur_no = max(abs(i), abs(j)) * 2 + 1;
			int cur_sq = pow(cur_no, 2);
			if (abs(i) >= abs(j))
			{
				if (i > 0)
					board[i - r1][j - c1] = cur_sq - abs(i) + j;
				else
					board[i - r1][j - c1] = cur_sq - (cur_no - 1) * 2 - abs(i) - j;
			}
			else
			{
				if (j > 0)
					board[i - r1][j - c1] = cur_sq - (cur_no - 1) * 3 - abs(j) - i;
				else
					board[i - r1][j - c1] = cur_sq - (cur_no - 1) - abs(j) + i;
			}
			max_num = max(board[i - r1][j - c1], max_num);
		}
	}
	int	width_len = 0;
	while (max_num > 0)
	{
		max_num /= 10;
		width_len++;
	}
	for (int i = 0; i <= r2 - r1; i++)
	{
		for (int j = 0; j <= c2 - c1; j++)
		{
			cout.width(width_len);
			cout << board[i][j];
			if (j != c2 - c1) cout << ' ';
		}
		cout << '\n';
	}
	return (0);
}