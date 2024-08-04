#include <iostream>
#include <map>

using namespace std;

int	arr[3000005] = {0, };
int	sushi[3005] = {0, };
int	main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int	n, d, k, c;
	int	ans = 0, cnt = 0;
	cin >> n >> d >> k >> c;
	sushi[c]++;
	cnt++;
	for (int i = 1; i <= n; i++)
	{
		if (i > k)
			if (--sushi[arr[i - k]] == 0)
				cnt--;
		cin >> arr[i];
		if (++sushi[arr[i]] == 1)
			cnt++;
		ans = max(ans, cnt);
	}
	for (int i = 1; i < k; i++)
	{
		if (--sushi[arr[n - k + i]] == 0)
			cnt--;
		if (++sushi[arr[i]] == 1)
			cnt++;
		ans = max(ans, cnt);
	}
	std::cout << ans << '\n';
}