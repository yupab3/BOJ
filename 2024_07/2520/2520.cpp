#include <iostream>

using namespace std;

int	main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	size_t	n;
	cin >> n;

	for (size_t i = 0; i < n; i++)
	{
		double cm, y, ssu, ssa, f;
		cin >> cm >> y >> ssu >> ssa >> f;
		size_t b, gs, gc, w;
		cin >> b >> gs >> gc >> w;
		size_t ans = 0;
		size_t fan = 0;
		while (cm >= 8.0 / 16 && y >= 8.0 / 16 && ssu >= 4.0 / 16 && ssa >= 1.0 / 16 && f >= 9.0 / 16)
		{
			cm -= 8.0 / 16;
			y -= 8.0 / 16;
			ssu -= 4.0 / 16;
			ssa -= 1.0 / 16;
			f -= 9.0 / 16;
			fan += 1;
		}
		while (fan > 0 && b >= 1)
		{
			fan -= 1;
			b -= 1;
			ans++;
		}
		while (fan > 0 && gs >= 30)
		{
			fan -= 1;
			gs -= 30;
			ans++;
		}
		while (fan > 0 && gc >= 25)
		{
			fan -= 1;
			gc -= 25;
			ans++;
		}
		while (fan > 0 && w >= 10)
		{
			fan -= 1;
			w -= 10;
			ans++;
		}
		cout << ans << '\n';
	}
}