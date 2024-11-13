#include <iostream>
#include <algorithm>

using namespace std;

int	board[52];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int n, m, l;
	cin >> n >> m >> l;
	for (int i = 1; i <= n; i++)
	{
		cin >> board[i];
	}
	sort(board, board + n + 1);
	board[n + 1] = l;
	int st = 1;
	int	en = 1000;
	int	mid;
	while (st < en)
	{
		int	cnt = 0;
		mid = (st + en) / 2;
		for (int i = 0; i <= n; i++)
		{
			int gap = board[i + 1] - board[i];
			cnt += gap / mid;
			if (gap % mid == 0)
				cnt--;
		}
		if (cnt > m)
			st = mid + 1;
		else
			en = mid;
	}
	cout << st << '\n';
	return (0);
}