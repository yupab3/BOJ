#include <iostream>

using namespace std;

long	a, b, c;

int	recursive_func(int i)
{
	if (i == 1)
		return a % c;
	long temp = recursive_func(i / 2);
	if (i % 2)
		return (temp * temp % c * a % c);
	return (temp * temp % c);
}

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	cin >> a >> b >> c;
	cout << recursive_func(b) << '\n';
	return (0);
}