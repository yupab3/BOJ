#include <iostream>

using namespace std;

size_t t[100005];
int	main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(0);

	size_t n, m, mid, cnt;
	size_t t_max = 0;
	cin >> n >> m;
	for (size_t i = 1; i <= n; i++)
	{
		cin >> t[i];
		t_max = max(t[i], t_max);
	}
	size_t left = 1, right = -1;
	while(1)
	{
		mid = (left + right) / 2;
		cnt = 0;
		for (size_t i = 1; i <= n; i++)
		{
			cnt += mid / t[i];
			if (cnt > m)
				break ;
		}
		if (left == right - 1)
			break;
		else if (cnt >= m)
			right = mid;
		else if (cnt < m)
			left = mid;
	}
	cout << right << '\n';
}