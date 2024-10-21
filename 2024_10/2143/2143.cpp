#include <iostream>
#include <vector>
#include <map>

using namespace std;

int	aa[1002];
int	bb[1002];
map<int, int>	a;
map<int, int>	b;

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int	t, n, m;
	cin >> t >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> aa[i];
		aa[i] += aa[i - 1];
	}
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> bb[i];
		bb[i] += bb[i - 1];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < i; j++)
			a[aa[i] - aa[j]]++;
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 0; j < i; j++)
			b[bb[i] - bb[j]]++;
	}
	size_t	ans = 0;
	for (auto a_it : a)
	{
		int a_num = a_it.first;
		ssize_t a_cnt = a_it.second;
		ssize_t trgt = t - a_num;
		auto b_it = b.lower_bound(trgt);
		int b_num = b_it->first;
		ssize_t b_cnt = b_it->second;
		// cout << "a: (" << a_num << ", " << a_cnt << "), b: (" << b_num << ", " << b_cnt << ")\n";
		if (b_num == trgt) ans += b_cnt * a_cnt;
	}
	vector<int>	c;
	c.push_back(3);
	c.push_back(3);
	c.push_back(4);
	auto [it1, it2] = equal_range(c.begin(), c.end(), 3);
	cout << it2 - it1 << '\n';
	cout << *it2 << '\n';
	cout << ans << '\n';
	return (0);
}