#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int board[2000002] = {0, };
	int n, cur;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> cur;
		board[cur]++;
	}
	int x;
	cin >> x;
	int ans = 0;
	for (int i = 1; i <= x / 2; i++)
	{
		if (i * 2 == x)
			ans += min(board[x - i], board[i]) / 2;
		else
			ans += min(board[x - i], board[i]);
	}
	cout << ans << '\n';
	return (0);
}