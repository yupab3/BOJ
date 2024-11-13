#include <iostream>
#include <numeric>

using namespace std;

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	long	t, a, b;
	cin >> t;
	while (t--)
	{
		cin >> a >> b;
		long i = 1;
		while (1)
		{
			// cout << "i: " << i << '\n';
			long gap = b / i + (b % i > 0);
			if (a >= gap)
			{
				a = a * i - b;
				b = b * i;
				if (a == 0)
				{
					b /= i;
					b /= gap;
					break ;
				}
				int div = gcd(a, b);
				a /= div;
				b /= div;
				// cout << a << '\n' << b << '\n';
				if (a == 1) break ;
			}
			else i++;
		}
		cout << b << '\n';
	}
	return (0);
}