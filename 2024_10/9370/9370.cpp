#include <iostream>
#include <queue>
#include <vector>
#include <set>

using namespace std;

#define ii pair<int, int>

int	n, m, t, s, g, h;
priority_queue<ii, vector<ii>, greater<ii> >	q;
set<int>	des;
set<int>	ans;
vector<ii>	nodes[2002];
int	board[2002];
int	min_board[2002];

void	dijkstra()
{
	while (q.size())
	{
		auto [c_cost, c_node] = q.top();
		q.pop();
		// cout << "------\ncur_node: " << c_node << ", " << c_cost << "\n";
		if (board[c_node] < c_cost) continue ;
		for (auto nxt : nodes[c_node])
		{
			int n_node = nxt.first;
			int n_cost = nxt.second;
			// cout << "nxt_node: " << n_node << ", " << n_cost << '\n';
			if (board[n_node] <= n_cost + c_cost) continue ;
			board[n_node] = n_cost + c_cost;
			q.push({n_cost + c_cost, n_node});
		}
		// cout << "------\n";
	}
}

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int cases;
	cin >> cases;
	while (cases--)
	{
		cin >> n >> m >> t >> s >> g >> h;
		int	a, b, d, gh, tmp;
		for (int i = 1; i <= n; i++)
			nodes[i].clear();
		for (int i = 1; i <= m; i++)
		{
			cin >> a >> b >> d;
			nodes[a].push_back({b, d});
			nodes[b].push_back({a, d});
			if ((a == g && b == h) || (a == h && b == g))
				gh = d;
		}
		for (int i = 1; i <= t; i++)
		{
			cin >> tmp;
			des.insert(tmp);
		}
		fill(&board[0], &board[2002], 2e9 + 5);
		board[s] = 0;
		q.push({0, s});
		dijkstra();
		for (int i = 1; i <= n; i++)
			min_board[i] = board[i];
		int	sg = board[g];
		int	sh = board[h];
		q.push({0, g});
		fill(&board[0], &board[2002], 2e9 + 5);
		board[g] = 0;
		dijkstra();
		int	max = 2e9 + 5;
		for (auto v : des)
		{
			if (sh + gh + board[v] <= min_board[v])
				ans.insert(v);
		}
		q.push({0, h});
		fill(&board[0], &board[2002], 2e9 + 5);
		board[h] = 0;
		dijkstra();
		for (auto v : des)
		{
			if (sg + gh + board[v] <= min_board[v])
				ans.insert(v);
		}
		for (auto v : ans)
			cout << v << ' ';
		cout << '\n';
		des.clear();
		ans.clear();
	}
}