#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define	ii	pair<int, int>

vector<ii>	total_node;
vector<ii>	node[100002];
priority_queue<ii>	q;
int	board[3][100002];
int	n, s1, s2;

void	dijkstra(int s)
{
	while (q.size())
	{
		auto [cost, cur] = q.top();
		cost *= -1;
		q.pop();
		if (cost > board[s][cur]) continue ;
		for (auto pipe : node[cur])
		{
			int	n_node = pipe.second;
			int	n_cost = pipe.first;
			// cout << "cost, cur: (" << cost << ", " << cur << ") >> n_cost, n_node: (" << n_cost << ", " << n_node << '\n';
			if (n_cost + cost >= board[s][n_node]) continue ;
			q.push({-(n_cost + cost), n_node});
			board[s][n_node] = n_cost + cost;
		}
	}
}

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	cin >> n >> s1 >> s2;
	int	p1, p2, cost, ans = 1e9 + 5;
	for (int i = 1; i < n; i++)
	{
		cin >> p1 >> p2 >> cost;
		total_node.push_back({p1, p2});
		node[p1].push_back({cost, p2});
		node[p2].push_back({cost, p1});
	}
	fill(&board[1][0], &board[1][100001], 1e9 + 5);
	fill(&board[2][0], &board[2][100001], 1e9 + 5);
	board[1][s1] = 0;
	board[2][s2] = 0;
	q.push({0, s1});
	dijkstra(1);
	q.push({0, s2});
	dijkstra(2);
	ans = min(ans, board[1][s2] + board[2][s1]);
	for (auto trgt : total_node)
	{
		int	p1 = trgt.first;
		int	p2 = trgt.second;
		ans = min(ans, board[1][p1] + board[2][p2]);
		ans = min(ans, board[1][p2] + board[2][p1]);
	}
	cout << ans << '\n';
}