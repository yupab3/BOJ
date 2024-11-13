#include <iostream>
#include <string>

using namespace std;

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	string	str;
	while (cin >> str)
	{
		if (str[0] == '0') return (0);
		int lp = 0, rp = str.size() - 1;
		while (str[lp] == str[rp])
		{
			if (lp >= rp) break ;
			lp++;
			rp--;
		}
		if (str[lp] == str[rp]) cout << "yes\n";
		else cout << "no\n";
	}
	return (0);
}