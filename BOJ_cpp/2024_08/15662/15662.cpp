#include <iostream>
#include <string>

using namespace std;

bool	gear[1002][8];
int	t, k;

void	spin(int target, int direction)
{
	int tmp;
	if (direction == -1)
	{
		tmp = gear[target][0];
		for (int i = 0; i < 7; i++)
			gear[target][i] = gear[target][i + 1];
		gear[target][7] = tmp;
	}
	else
	{
		tmp = gear[target][7];
		for (int i = 7; i > 0; i--)
			gear[target][i] = gear[target][i - 1];
		gear[target][0] = tmp;
	} 
}

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	string str;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		cin >> str;
		for (int j = 0; j < 8; j++)
			gear[i][j] = str[j] - 48;
	}
	cin >> k;
	int target, direction;
	int left, right;
	while (k--)
	{
		cin >> target >> direction;
		left = target - 1;
		right = target;
		while (left)
		{
			if (gear[left][2] != gear[left + 1][6])
			{
				direction *= -1;
				left--;
				continue ;
			}
			else
			{
				left++;
				break ;
			}
		}
		if (!left) ++left;
		while (right++)
		{
			if (right > t)
			{
				right--;
				break ;
			}
			if (gear[right][6] != gear[right - 1][2])
				continue ;
			else
			{
				right--;
				break ;
			}
		}
		// cout << left << " ~ " << right << '\n';
		for (int i = left; i <= right; i++)
		{
			spin(i, direction);
			direction *= -1;
		}
	}
	int	ans = 0;
	while(t)
	{
		if (gear[t][0]) ans++;
		t--;
	}
	cout << ans << '\n';
	return (0);
}
// 위쪽 톱니 : 2
// 왼쪽 : 6, 오른쪽 : 2