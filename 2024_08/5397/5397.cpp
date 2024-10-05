#include <iostream>
#include <string>
#include <list>

using namespace std;

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string str;
		list<char> L;
		cin >> str;
		auto pos = L.begin();
		for (auto c : str)
		{
			if (c == '-')
			{
				if (pos != L.begin()) pos = L.erase(--pos);
			}
			else if (c == '<')
			{
				if (pos != L.begin()) --pos;
			}
			else if (c == '>')
			{
				if (pos != L.end()) ++pos;
			}
			else
				L.insert(pos, c);
		}
		for (auto c : L) cout << c;
		cout << '\n';
	}
	return (0);
}