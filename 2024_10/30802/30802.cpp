#include <iostream>

using namespace std;

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int	n, t, s[6], p;
	cin >> n;
	for (int i = 0; i < 6; i++)
		cin >> s[i];
	cin >> t >> p;
	int ans_t = 0, ans_p = 0;
	for (int i = 0; i < 6; i++)
	{
		ans_t += s[i] / t + (s[i] % t != 0);
		ans_p += s[i];
	}
	cout << ans_t << '\n' << ans_p / p << ' ' << ans_p % p << '\n';
	return (0);
}