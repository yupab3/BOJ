#include <iostream>

using namespace std;

int n;
int slum[22][22];

void	check_drug_addicts(int x, int y, int d1, int d2)
{
	int score[7] = {0, };
	for (int r = 1; r < x + d1; r++)
	{
		for (int c = 1; c <= y; c++)
			score[1] += slum[r][c];
	}
	for (int r = 1; r <= x + d1; r++)
	{
		for (int c = y + 1; c <= n; c++)
			score[2] += slum[r][c];
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
			cin >> slum[i][j];
	}
	for (int d1 = 1; d1 < n; d1++)
	{
		for (int d2 = 1; d2 < n; d2++)
		{
			for (int x = 1; x <= n; x++)
			{
				for (int y = 1; y <= n; y++)
				{
					if (0 < y - d1 && y + d2 <= n && x + d1 + d2 <= n)
						check_drug_addicts(x, y, d1, d2);
				}
			}
		}
	}
}