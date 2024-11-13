#include <iostream>
#include <cmath>

using namespace std;

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int	n;
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		double res = sqrt(x * x + y * y);
		if (res <= 10)
			ans += 10;
		else if (res <= 30)
			ans += 9;
		else if (res <= 50)
			ans += 8;
		else if (res <= 70)
			ans += 7;
		else if (res <= 90)
			ans += 6;
		else if (res <= 110)
			ans += 5;
		else if (res <= 130)
			ans += 4;
		else if (res <= 150)
			ans += 3;
		else if (res <= 170)
			ans += 2;
		else if (res <= 190)
			ans += 1;
	}
	cout << ans << '\n';
}