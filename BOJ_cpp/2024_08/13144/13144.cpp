#include <iostream>

using namespace std;

int 	board[100002];
int 	visit[100002];
int		n;
ssize_t	ans;

void	tp()
{
	int lp = 1, rp = 1;
	visit[0] = true;
	while (1)
	{
		if (lp == n + 1) break ;
		if (visit[board[rp]])
		{
			ans += rp - lp;
			visit[board[lp]] = false;
			lp++;
		}
		else
		{
			visit[board[rp]] = true;
			rp++;
		}
	}
}

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> board[i];
	tp();
	cout << ans << '\n';
	return (0);
}