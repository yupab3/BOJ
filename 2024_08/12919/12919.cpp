#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string	s, t;
bool	ans = false;
void	sol()
{
	if (ans)
		return ;
	if (t == s)
		ans = true;
	if (t.back() == 'A')
	{
		t.pop_back();
		sol();
		t += 'A';
	}
	if (t.front() == 'B')
	{
		reverse(t.begin(), t.end());
		t.pop_back();
		sol();
		t += 'B';
		reverse(t.begin(), t.end());
	}
}

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	cin >> s >> t;
	sol();
	cout << ans << '\n';
	return (0);
}