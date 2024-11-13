#include <iostream>

using namespace std;

int	prime[1000005] = {0, };

int	main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int m, n;
	cin >> m >> n;
	prime[1] = -1;
	prime[2] = 1;
	for (int i = 2; i <= 1000000; i++)
	{
		if (prime[i] == -1)
			continue;
		int mux = 2;
		while (i * mux <= n)
		{
			prime[i * mux] = -1;
			mux++;
		}
	}
	for (int i = m; i <= n; i++)
	{
		if (prime[i] != -1)
			cout << i << '\n';
	}
	return 0;
}