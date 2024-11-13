#include <iostream>
#include <algorithm>

using namespace std;

int	a[10002];
int	n;
size_t ans = 0;

void	sol(int start)
{
	int left = start + 1;
	while (left < n)
	{
		int	trgt = 0 - (a[left] + a[start]);
		int lp = left + 1, rp = n, cp = (lp + rp) / 2;
		// cout << "-------------------\n";
		// cout << "a[start]: " << a[start] << ", a[left]: " << a[left] << '\n';
		// cout << "-------------------\n";
        while (lp < rp)
		{
			// cout << "cp: " << cp << ", a[cp]: " << a[cp] << '\n';
			if (a[cp] == trgt) break ;
			else if (a[cp] > trgt) rp = cp;
			else lp = cp + 1;
			cp = (lp + rp) / 2;
		}
		if (a[cp] == trgt)
		{
			int left_sungyoon = left + 1;
			int right_sungyoon = cp;
			int	min_sungyoon = (left_sungyoon + right_sungyoon) / 2;
			while (left_sungyoon < right_sungyoon)
			{
				if (a[min_sungyoon] == trgt) right_sungyoon = min_sungyoon;
				else left_sungyoon = min_sungyoon + 1;
				min_sungyoon = (left_sungyoon + right_sungyoon) / 2;
			}
			left_sungyoon = cp;
			right_sungyoon = n;
			int	max_sungyoon = (left_sungyoon + right_sungyoon) / 2;
			while (left_sungyoon < right_sungyoon)
			{
				if (a[max_sungyoon] == trgt) left_sungyoon = max_sungyoon + 1;
				else right_sungyoon = max_sungyoon;
				max_sungyoon = (left_sungyoon + right_sungyoon) / 2;
			}
			ans += max_sungyoon - min_sungyoon;
			if (a[max_sungyoon] == trgt)
				ans++;
		}
		left++;
	}
}

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(&a[1], &a[n] + 1);
	// for (int i = 1; i <= n; i++)
	// 	cout << a[i];
	for (int i = 1; i <= n; i++)
	{
        sol(i);
	}
	cout << ans << '\n';
	return (0);
}