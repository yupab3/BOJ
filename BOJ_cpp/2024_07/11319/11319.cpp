#include <iostream>
#include <string>

using namespace std;

int	main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int	s;
	cin >> s;
	string	tmp;
	getline(cin, tmp);
	for (int i = 0; i < s; i++)
	{
		string	str;
		getline(cin, str);
		int idx = 0;
		int	cnt_v = 0;
		int cnt = 0;
		while (str[idx] != '\0')
		{
			if (str[idx] == 'A' || str[idx] == 'E' || str[idx] == 'I' || str[idx] == 'O' || str[idx] == 'U' \
			|| str[idx] == 'a' || str[idx] == 'e' ||  str[idx] == 'i' || str[idx] == 'o' || str[idx] == 'u')
				cnt_v++;
			else if (str[idx] != ' ' && str[idx] != '\t')
				cnt++;
			idx++;
		}
		cout << cnt << " " << cnt_v << '\n';
	}
	return (0);
}