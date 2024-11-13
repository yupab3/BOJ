#include <iostream>

using namespace std;

int	main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int a, b, c;
	cin >> a >> b >> c;
	cout << a + b - c << '\n';
	int tmp = b;
	while (b > 0)
	{
		a *= 10;
		b /= 10;
	}
	cout << a + tmp - c << '\n';
	return (0);
}