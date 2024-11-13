#include <iostream>
#include <sstream>
#include <stack>

using namespace std;

int M[20][6];
int	ans[5] = {0, };
int minimum = 20000000;
int MAX;
int	list[20] = {0, };
int	forcnt = 0;

void	solver(int n)
{
	for(int i = n; i < MAX + 1; i++)
	{
		forcnt++;
		if (MAX + 1 == n)
			return ;
		if (M[i][5] == 0)
		{
			ans[0] += M[i][0];
			ans[1] += M[i][1];
			ans[2] += M[i][2];
			ans[3] += M[i][3];
			ans[4] += M[i][4];
			M[i][5] = 1;
			if (ans[0] >= M[0][0] && ans[1] >= M[0][1] && ans[2] >= M[0][2] && ans[3] >= M[0][3])
			{
				if (min(minimum, ans[4]) == ans[4] && minimum != ans[4])
				{
					minimum = min(minimum, ans[4]);
					for (int j = 1; j < 20; j++)
					{
						list[j] = M[j][5];
					}
				}
			}
			else
				solver(i + 1);
			ans[0] -= M[i][0];
			ans[1] -= M[i][1];
			ans[2] -= M[i][2];
			ans[3] -= M[i][3];
			ans[4] -= M[i][4];
			M[i][5] = 0;
		}
	}
}

int	main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(0);
	int n;
	cin >> n;
	MAX = n;
	cin >> M[0][0];
	cin >> M[0][1];
	cin >> M[0][2];
	cin >> M[0][3];
	for (int i = 1; i < n + 1; i++)
	{
		cin >> M[i][0];
		cin >> M[i][1];
		cin >> M[i][2];
		cin >> M[i][3];
		cin >> M[i][4];
		M[i][5] = 0;
	}
	solver(1);
	if (minimum == 20000000)
	{
		std::cout << "-1\n";
		return 0;
	}
	std::cout << minimum << '\n';
	int	cnt = 0;
	for (int i = 1; i < 20; i++)
	{
		if (list[i])
			cnt++;
	}
	for (int i = 0; i < 20; i++)
	{
		if (list[i])
		{
			std::cout << i;
			cnt--;
		}
		if (list[i] && cnt > 0)
			std::cout << " ";
	}
	std::cout << '\n';
}