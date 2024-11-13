#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

#define	ii pair<int, int>
#define	INF 1e9+10

int			d[50002];
vector<ii>	node[50002];

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	fill(d, d+50001, INF);
	int	n, m;
	cin >> n >> m;
	while (m--)
	{
		int	a, b, c;
		cin >> a >> b >> c;
		node[a].push_back({c, b});
		node[b].push_back({c, a});
	}
	priority_queue<ii, vector<ii>, greater<ii>>	q;
	q.push({0, 1});
	d[1] = 0;
	while(!q.empty())
	{
		int	cur_node = q.top().second;
		int	cur_cost = q.top().first;
		q.pop();
		if (cur_cost > d[cur_node]) continue;
		for (auto next : node[cur_node])
		{
			int	nxt_node = next.second;
			int	nxt_cost = next.first;
			if (d[nxt_node] <= nxt_cost + d[cur_node]) continue;
			d[nxt_node] = nxt_cost + d[cur_node];
			q.push({d[nxt_node], nxt_node});
		}
	}
	cout << d[n] << '\n';
}