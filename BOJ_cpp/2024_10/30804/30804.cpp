#include <iostream>
#include <algorithm>

using namespace std;

int n;
int fruit[200002];
int	cnt[11];

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	cin >> n;
	int	ans = 0;
	for (int i = 1; i <= n; i++)
		cin >> fruit[i];
	int lp = 1, rp = 1;
	while (rp <= n + 1)
	{
		int	var = 0;
		for (int i = 1; i <= 9; i++)
		{
			if (cnt[i])
				var++;
			// cout << cnt[i] << " ";
		}
		// cout << '\n';
		if (var > 2)
		{
			cnt[fruit[lp]]--;
			lp++;
		}
		else
		{
			int sum = 0;
			for (int i = 1; i <= 9; i++)
			{
				if (cnt[i])
					sum += cnt[i];
			}
			ans = max(ans, sum);
			cnt[fruit[rp]]++;
			rp++;
		}
	}
	cout << ans << '\n';
	return (0);
}