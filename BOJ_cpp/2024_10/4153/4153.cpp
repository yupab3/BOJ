#include <iostream>

using namespace std;

int	main()
{
	int	a, b, c;
	while (cin >> a >> b >> c)
	{
		int tmp;
		if (a == 0 && b == 0 && c == 0) break ;
		if (a < b)
		{
			tmp = b; b = a; a = tmp;
		}
		if (a < c)
		{
			tmp = c; c = a; a = tmp;
		}
		if (a * a == b * b + c * c) cout << "right\n";
		else cout << "wrong\n";
	}
	return (0);
}