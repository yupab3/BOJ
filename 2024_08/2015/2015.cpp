#include <iostream>
#include <map>

using namespace std;

int				board[200002];
map<int, int>	_count;

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int	n, k, tmp;
	cin >> n >> k;
	size_t	ans = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> board[i];
		board[i] = board[i] + board[i - 1];
		if (board[i] == k) ans++;
	}
	for (int i = 1; i <= n; i++)
	{
		ans += _count[board[i] - k];
		_count[board[i]]++;
	}
	cout << ans << '\n';
	return (0);
}
// 1 -2 1 -2 -3
// 1 -1 0 -2 -5
// 2 -2 // 2 -2 2 -2
// 0 = 처음 ~ 합  = 0, 0의 갯수만큼