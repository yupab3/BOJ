#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

#define ii	pair<int, int>

int	n;
vector<ii>	dots;

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	cin >> n;
	ssize_t	sx, sy;
	for (int i = 1; i <= n; i++)
	{
		cin >> sx >> sy;
		dots.push_back({sx, sy});
	}
	auto it = dots.begin();
	sx = it->first;
	sy = it->second;
	++it;
	ssize_t ax = it->first;
	ssize_t ay = it->second;
	ssize_t bx, by;
	++it;
	ssize_t	ans = 0;
	for (; it != dots.end(); ++it)
	{
		bx = it->first;
		by = it->second;
		ans += (sx * ay - sx * by + ax * by - ax * sy + bx * sy - bx * ay);
		ax = bx;
		ay = by;
	}
	ans = abs(ans);
	cout << ans / 2 << '.';
	if (ans % 2) cout << '5';
	else cout << '0';
	return (0);
}