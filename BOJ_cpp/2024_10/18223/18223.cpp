#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define ii pair<int, int>

priority_queue<ii, vector<ii>, greater<ii> > q;
vector<ii> node[5002];
int	board[5002];
int	v, e, p;

void	dijkstra()
{
	while(q.size())
	{
		auto [c_cost, c_node] = q.top(); q.pop();
		if (c_cost > board[c_node]) continue ;
		for (auto next : node[c_node])
		{
			int n_cost = next.first;
			int n_node = next.second;
			if (c_cost + n_cost >= board[n_node]) continue ;
			q.push({n_cost + c_cost, n_node});
			board[n_node] = n_cost + c_cost;
		}
	}
}

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	cin >> v >> e >> p;
	int a, b, c;
	for (int i = 1; i <= e; i++)
	{
		cin >> a >> b >> c;
		node[a].push_back({c, b});
		node[b].push_back({c, a});
	}
	q.push({0, 1});
	fill(&board[0], &board[5002], 999999999);
	board[1] = 0;
	dijkstra();
	int	sv = board[v];
	int	sp = board[p];
	fill(&board[0], &board[5002], 999999999);
	q.push({0, p});
	board[p] = 0;
	dijkstra();
	// cout << "sp: " << sp << ", board[" << v << "]: " << board[v] << ", sv: " << sv << '\n'; 
	if (sp + board[v] == sv) cout << "SAVE HIM";
	else cout << "GOOD BYE";
	return (0);
}