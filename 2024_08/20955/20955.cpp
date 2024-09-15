#include <iostream>

using namespace std;

int		board[100002];
bool	visit[100002];

int	u_find(int u)
{
	if (u == board[u]) return u;
	return board[u] = u_find(board[u]);
}

void	u_merge(int u, int v)
{
	u = u_find(u);
	v = u_find(v);
	if (u == v) return;
	if (u < v)
		board[v] = u;
	else
		board[u] = v;
}

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int	n, u, v;
	size_t m, ans = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		board[i] = i;
	for (int i = 1; i <= m; i++)
	{
		cin >> u >> v;
		u_find(u);
		u_find(v);
		if (board[u] == board[v])
		{
			// cout << "input\n";
			ans++;
		}
		u_merge(u, v);
	}
	for (int i = 1; i <= n; i++)
	{
		u_find(i);
		if (!visit[board[i]])
		{
			visit[i] = true;
			ans++;
		}
	}
	ans--;
	cout << ans << '\n';
	return (0);
}