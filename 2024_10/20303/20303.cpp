#include <iostream>
#include <vector>

using namespace std;

#define ii pair<int, int>

int			c_board[30002];
int			n_board[30002];
int			u_board[30002];
int			k_board[3002];
vector<ii>	v;

int	find_u(int u)
{
	if (u == u_board[u]) return (u);
	return (u_board[u] = find_u(u_board[u]));
}

void	merge_u(int u, int v)
{
	int uu = find_u(u);
	int uv = find_u(v);
	if (uu == uv) return ;
	if (uu > uv)
	{
		u_board[uu] = uv;
		c_board[uv] += c_board[uu];
		n_board[uv] += n_board[uu];
	}
	else
	{
		u_board[uv] = uu;
		c_board[uu] += c_board[uv];
		n_board[uu] += n_board[uv];
	}
}

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	fill(&n_board[0], &n_board[30002], 1);
	int	n, m, k, s, e;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> c_board[i];
		u_board[i] = i;
	}
	for (int i = 1; i <= m; i++)
	{
		cin >> s >> e;
		merge_u(e, s);
	}
	for (int i = 1; i <= n; i++)
	{
		// cout << i << ", u: " << u_board[i] << ", c: " << c_board[i] << ", n: " << n_board[i] << '\n';
		if (u_board[i] == i)
			v.push_back({n_board[i], c_board[i]});
	}
	for (auto [f, c] : v) // 1, 1 30000개
	{
		for (int i = k; i >= f; i--) // 1, 1 30000 * 3000번
			k_board[i] = max(k_board[i], k_board[i - f] + c);
	}
	// 0 0 0 0 0 0   ->     0 0 0 3 3 3
	cout << k_board[k - 1] << '\n';
	return (0);
}