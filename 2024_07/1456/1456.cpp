#include <iostream>

using namespace std;

ssize_t	prime[10000005] = {0, };

int	main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	ssize_t a, b, ans = 0;
	cin >> a >> b;
	prime[1] = -1;
	prime[2] = 1;
	for (ssize_t i = 2; i <= 10000000; i++)
	{
		if (prime[i] == -1)
			continue;
		ssize_t mux = 2;
		while (i * mux <= 10000000)
		{
			prime[i * mux] = -1;
			mux++;
		}
	}
	for (ssize_t i = 2; i <= 10000000; i++)
	{
		if (prime[i] != -1)
		{
			ssize_t z = i;
			while (1)
			{
				if (100000000000000 / z < i) break ;
				z *= i;
				if (a > z) continue ;
				if (b < z) break ;
				ans++;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}