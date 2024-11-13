#include <iostream>
#include <string>

using namespace std;
int	ans, idx, rec;
string s;

int	recursion()
{
	int count = 0;
	while (s[idx])
	{
		// cout << "----- rec = " << rec << " -----\n";
		char cur = s[idx];
		// cout << "cur: " << cur << ", count: " << count << '\n';
		if (cur == ')')
		{
			idx++;
			return count;
		}
		if (cur == '(')
		{
			count--;
			idx++;
			// rec++;
			count += (s[idx - 2] - 48) * recursion();
			// rec--;
		}
		else
		{
			count++;
			idx++;
		}
	}
	return count;
}

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	cin >> s;
	ans = recursion();
	cout << ans << '\n';
	return (0);
}