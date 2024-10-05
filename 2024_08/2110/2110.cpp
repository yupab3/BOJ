#include <iostream>
#include <algorithm>

using namespace std;

int	board[200002];

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int	n, c;
	cin >> n >> c;
	for (int i = 1; i <= n; i++)
		cin >> board[i];
	sort(board + 1, board + n + 1);
	int	gap;
	int	st = 0;
	int	en = 1e9 + 1;
	int	ans = 0;
	while(st < en)
	{
		int	cur = 1;
		int	cnt = 1;
		gap = (st + en) / 2;
		for (int i = 2; i <= n; i++)
		{
			if (board[i] - board[cur] >= gap)
			{
				// cout << gap << " -> " << i << ", " << cur << '\n';
				cur = i;
				cnt++;
			}
		}
		if (cnt == c)
			ans = gap;
		if (cnt < c - 1)
			en = gap;
		else
			st = gap + 1;
	}
	cout << st - 1 << '\n';
	return (0);
}

// 6 3
// 1 3 6 9 10 100
// 9      9