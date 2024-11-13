#include <iostream>
#include <algorithm>
using namespace std;

int	board[100002];

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int	n, m, cur = 0, ans = 2e9 + 3;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		cin >> board[i];
	sort(board, board + n + 1);
	for (int i = 1; i < n; i++)
		board[i] = board[i + 1] - board[i];
	int st = 1;
	int en = 1;
	while (en != n)
	{
		cur += board[en++];
		while (cur >= m)
		{
			ans = min(ans, cur);
			cur -= board[st++];
		}
	}
	cout << ans << '\n';
	return (0);
}