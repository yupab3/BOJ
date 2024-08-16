#include <iostream>
#include <queue>

#define ii	pair<int, int>
#define iii	tuple<int, int, int>

using namespace std;

priority_queue<iii>	q;
vector<ii>			node[10002];
size_t	d[22][10002];
int	n, m, k;

void	DijkstraP()
{
	while (!q.empty())
	{
		auto [cur_city, cur_cost, sekai] = q.top();
		q.pop();
		for (auto next : node[cur_city])
		{
			int	next_city = next.second;
			int	next_cost = next.first;
			if (d[sekai][next_city] <= next_cost + d[sekai][cur_city] && sekai == k) continue;
			else if (d[next_city] <= next_cost + d[cur_city] && )
		}
	}
}

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	cin >> n >> m >> k;
	int	a, b, c;
	for (int i = 0; i < 22; i++)
	{
		fill(d[i], d[i]+10001, static_cast<size_t>(-1));
		d[i][0] = 0;
	}
	for (int i = 1; i <= m; i++)
	{
		cin >> a >> b >> c;
		node[a].push_back({c, b});
		node[b].push_back({c, a});
	}
	q.push({0, 1, 0});
	DijkstraP();
	return (0);
}