#include <iostream>

using namespace std;

int	main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int	h, m;
	cin >> h >> m;
	cout << (h - 9) * 60 + m << '\n';
}