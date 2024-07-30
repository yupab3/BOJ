#include <iostream>

using namespace std;

size_t	prime[1000005] = {0, };

int	main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int	t, n;
	cin >> t;
	for (size_t i = 1; i <= 1000000; i++)
	{
		size_t	mux = 1;
		while (i * mux <= 1000000)
		{
			prime[i * mux] += i;
			mux++;
		}
	}
	for (int i = 2; i <= 1000000; i++)
		prime[i] += prime[i - 1];
	for (int i = 1; i <= t; i++)
	{
		cin >> n;
		cout << prime[n] << '\n';
	}
	return (0);
}