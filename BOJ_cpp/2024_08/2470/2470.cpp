#include <iostream>
#include <algorithm>

using namespace std;

int n;
int	board[100002];
int	ans = 2e9 + 5;

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> board[i];
	sort(&board[1], &board[n + 1]);
	int lp = 1, rp = n;
	int	ans_l, ans_r;
	while (lp < rp)
	{
		if (ans > abs(board[rp] + board[lp]))
		{
			// cout << lp << ", " << rp << '\n';
			ans = abs(board[rp] + board[lp]);
			ans_l = lp;
			ans_r = rp;
		}
		if (board[rp] + board[lp] < 0)
			lp++;
		else if (board[rp] + board[lp] > 0)
			rp--;
		else
			break ;
	}
	cout << board[ans_l] << ' ' << board[ans_r] << '\n';
	return (0);
}