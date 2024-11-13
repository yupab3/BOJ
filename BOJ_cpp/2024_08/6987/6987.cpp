#include <iostream>

using namespace std;

int	ans;
int	ddata[7][3];

void	sol(int	left, int right)
{
	if (ans)
		return ;
	if (left == 7)
	{
		ans = 1;
		return ;
	}
	if (right == 7)
		sol(left + 1, left + 2);
	if (ddata[left][0] > 0 && ddata[right][2] > 0)
	{
		ddata[left][0]--;
		ddata[right][2]--;
		sol(left, right + 1);
		ddata[left][0]++;
		ddata[right][2]++;
	}
	if (ddata[left][1] > 0 && ddata[right][1] > 0)
	{
		ddata[left][1]--;
		ddata[right][1]--;
		sol(left, right + 1);
		ddata[left][1]++;
		ddata[right][1]++;
	}
	if (ddata[left][2] > 0 && ddata[right][0] > 0)
	{
		ddata[left][2]--;
		ddata[right][0]--;
		sol(left, right + 1);
		ddata[left][2]++;
		ddata[right][0]++;
	}
}

int	main()
{
	int	chk, sibal;
	for (int i = 1; i <= 4; i++)
	{
		ans = 0;
		sibal = 1;
		for (int j = 1; j <= 6; j++)
		{
			chk = 0;
			for (int k = 0; k <= 2; k++)
			{
				cin >> ddata[j][k];
				chk += ddata[j][k];
			}
			if (chk != 5)
				sibal = 0;
		}
		if (sibal)
			sol(1, 2);
		cout << ans << ' ';
	}
	cout << '\n';
}