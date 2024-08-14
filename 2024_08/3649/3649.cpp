#include <iostream>
#include <set>

using namespace std;

int	x, n, l;
multiset<int>	lego;

void	sol()
{
	multiset<int>::iterator	left = lego.begin();
	multiset<int>::iterator	right = --lego.end();
	while (left != right)
	{
		int	sum = *left + *right;
		if (sum == x * 10000000)
		{
			cout << "yes " << *left << " " << *right << '\n';
			return ;
		}
		if (sum > x * 10000000)
			--right;
		else
			++left;
	}
	cout << "danger\n";
}

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	while (cin >> x)
	{
		cin >> n;
		if (n == 0)
		{
			cout << "danger\n";
			continue ;
		}
		for (int i = 1; i <= n; i++)
		{
			cin >> l;
			lego.insert(l);
		}
		sol();
		lego.clear();
	}
}