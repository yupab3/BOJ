#include <iostream>
#include <string>

using namespace std;

int	holyshitmotherfucker = 0;
string	str_tmp;

void	sol(int n)
{
	if (holyshitmotherfucker)
		return ;
	if (n == 0)
	{
		cout << str_tmp << '\n';
		holyshitmotherfucker = 1;
		return ;
	}
	for (int i = 1; i <= 3; i++)
	{
		int	dup = 0;
		str_tmp += 48 + i;
		size_t	str_len = str_tmp.size();
		size_t	pos = 1;
		while (pos <= (str_len + 1) / 2)
		{
			for (int i = 0; i < str_len - pos; i++)
			{
				int j;
				for (j = 0; j < pos; j++)
				{
					if (str_tmp[i + j] != str_tmp[i + pos + j])
						break ;
				}
				if (j == pos)
					dup = 1;
			}
			if (dup == 1)
				break ;
			pos++;
		}
		if (dup == 0)
			sol(n - 1);
		str_tmp.pop_back();
	}
}

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int	n;
	cin >> n;
	sol(n);
	return (0);
}