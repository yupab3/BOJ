#include <iostream>
#include <string>
#include <list>


using namespace std;

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	string	str;
	list<char>	L;
	int m, idx;
	char	cmd, input_ch;
	cin >> str >> m;
	for (auto c : str) L.push_back(c);
	auto pos = L.end();
	for (int i = 0; i < m; i++)
	{
		cin >> cmd;
		if (cmd == 'P')
		{
			cin >> input_ch;
			L.insert(pos, input_ch);
		}
		else if (cmd == 'L' && pos != L.begin()) --pos;
		else if (cmd == 'D' && pos != L.end()) ++pos;
		else if (cmd == 'B' && pos != L.begin())
		{
			--pos;
			pos = L.erase(pos);
		}
	}
	for (auto c : L) cout << c;
	return (0);
}