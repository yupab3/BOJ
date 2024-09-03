#include <iostream>
#include <string>
#include <set>

using namespace std;

int			l, c;
set<char>	s;
string		str;

void	sol(set<char>::iterator it, int aeiou, int count)
{
	while (it != s.end())
	{
		str += *it;
		if (count == l)
		{
			if (*it == 'a' || *it == 'e' || *it == 'i' || *it == 'o' || *it == 'u')
				++aeiou;
			if (aeiou && l - aeiou > 1)
				cout << str << '\n';
			if (*it == 'a' || *it == 'e' || *it == 'i' || *it == 'o' || *it == 'u')
				--aeiou;
			++it;
		}
		else if (*it == 'a' || *it == 'e' || *it == 'i' || *it == 'o' || *it == 'u')
			sol(++it, aeiou + 1, count + 1);
		else
			sol(++it, aeiou, count + 1);
		str.pop_back();
	}
}

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	cin >> l >> c;
	char	tmp;
	for (int i = 0; i < c; i++)
	{
		cin >> tmp;
		s.insert(tmp);
	}
	sol(s.begin(), 0, 1);
	return (0);
}