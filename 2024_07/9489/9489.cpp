#include <iostream>

using namespace std;

int	findnextidx(int idx, int *num)
{
	for (int i = idx + 1; i < 1000005; i++)
	{
		if (num[i] != 0)
			return i;
	}
	return 0;
}

int	main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(0);
	int	n, k, idx, comp, tmp, bf;
	while (cin >> n >> k)
	{
		if (n == 0 && k == 0)
			break ;
		int	num[1000005] = {0, };
		cin >> bf;
		idx = 0;
		num[bf] = bf;
		comp = bf;
		for (int i = 2; i <= n; i++)
		{
			cin >> tmp;
			if (tmp > comp + 1)
				idx = findnextidx(idx, num);
			num[tmp] = idx;
			comp = tmp;
			// std::cout << "num[" << tmp << "]: " << idx << '\n';
		}
		int ans = 0;
		for (int i = 1; i <= tmp; i++)
		{
			if (num[num[i]] >= num[k])
				break ;
			if (num[num[k]] == num[num[i]] && num[k] != num[i] && num[i] != i && num[i] != num[num[i]])
			{
				ans++;
				// std::cout << "i: " << i << '\n';
			}
		}
		std::cout << ans << '\n';
	}
}