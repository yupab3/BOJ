#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;

	while (getline(cin, str))
	{
		if (str == "#") break ;
		int idx = 0;
		int ans = 0;
		while (str[idx])
		{
			if (str[idx] == 'a' || str[idx] == 'e' || str[idx] == 'i' || str[idx] == 'o' || str[idx] == 'u' ||
			str[idx] == 'A' || str[idx] == 'E' || str[idx] == 'I' || str[idx] == 'O' || str[idx] == 'U')
				ans++;
			idx++;
		}
		cout << ans << '\n';
	}
	return (0);
}