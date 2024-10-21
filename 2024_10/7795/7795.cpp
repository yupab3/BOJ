#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int>	a, b;

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int	t, n, m;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		int tmp;
		for (int i = 1; i <= n; i++)
		{
			cin >> tmp;
			a.push_back(tmp);
		}
		for (int i = 1; i <= m; i++)
		{
			cin >> tmp;
			b.push_back(tmp);
		}
		sort(a.rbegin(), a.rend());
		sort(b.rbegin(), b.rend());
		//8 7 3 1 1
		//6 3 1
		ssize_t ans = 0;
		size_t lp = 0, rp = 0;
		while (lp < a.size())
		{
			if (a[lp] > b[rp])
			{
				ans += b.size() - rp;
				lp++;
			}
			else
				rp++;
			if (rp == b.size()) break ;
		}
		a.clear();
		b.clear();
		cout << ans << '\n';
	}
	return (0);
}