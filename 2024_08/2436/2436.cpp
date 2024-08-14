#include <iostream>

using namespace std;

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	long long	a, b, cnt = 0, trgt, sml = 0, big = 0;
	long long	ans_big, ans_sml;
	cin >> a >> b;
	trgt = a * b;
	ans_sml = a;
	ans_big = b;
	sml = a;
	big = b;
	while (1)
	{
		if (sml >= big)
			break ;
		if (trgt % sml == 0 && (trgt / sml) % sml != 0)
		{
			big = trgt / sml;
			if (ans_big + ans_sml > big + sml)
			{
				int	div = 2, tmp_big = big, tmp_sml = sml, tmp = 1;
				while (1)
				{
					if (div >= tmp_sml)
						break ;
					if (tmp_big % div == 0 && tmp_sml % div == 0)
					{
						tmp_big /= div;
						tmp_sml /= div;
						tmp *= div;
					}
					else
						div++;
				}
				tmp *= tmp_big * tmp_sml;
				if (tmp == b)
				{
					ans_big = big;
					ans_sml = sml;
				}
			}
		}
		sml += a;
	}
	cout << ans_sml << " " << ans_big << '\n';
	return (0);
}