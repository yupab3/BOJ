#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int n;
	string str;
	cin >> n >> str;
	size_t	ans = 0;
	for (int i = 0; i < n; i++)
	{
		int j = i;
		size_t	r = 31;
		size_t	ri = 1;
		while (j--)
			ri = ri * r % 1234567891;
		// cout << (str[i] - 96) << ' ' << ri << '\n';
		ans += (str[i] - 96) * ri;
		ans %= 1234567891;
	}
	cout << ans << '\n';
	return (0);
}