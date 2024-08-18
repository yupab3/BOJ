#include <iostream>
#include <tuple>
#include <queue>

#define ss	pair<size_t, size_t>
#define sss	tuple<size_t, size_t, size_t>

using namespace std;

priority_queue<sss, vector<sss>, greater<sss> >	q;
vector<ss>			node[10002];
size_t				d[22][10002];
int					n, m, k;

void	DijkstraP()
{
	while (!q.empty())
	{
		auto [cur_cost, cur_city, sekai] = q.top();
		q.pop();
		if (cur_cost > d[sekai][cur_city]) continue ;
		for (auto next : node[cur_city])
		{
			int	next_city = next.second;
			size_t	next_cost = next.first;
			// if (next_city == 1) continue;
			if (sekai != k && d[sekai][cur_city] < d[sekai + 1][next_city])
			{
				d[sekai + 1][next_city] = d[sekai][cur_city];
				// cout << cur_cost << ", " << cur_city << ", " << sekai << " -> " << d[sekai + 1][next_city] << ", " << next_city << ", " << sekai + 1 << '\n';
				q.push({d[sekai + 1][next_city], next_city, sekai + 1});
			}
			// cout << cur_cost << ", " << cur_city << ", " << sekai << " cmp-> " << d[sekai][next_city] << " <= " << next_cost << " + " << d[sekai][cur_city] << " city: " << next_city << '\n';
			if (d[sekai][next_city] <= next_cost + d[sekai][cur_city]) continue ;
			d[sekai][next_city] = next_cost + d[sekai][cur_city];
			// cout << cur_cost << ", " << cur_city << ", " << sekai << " -> " << d[sekai][next_city] << ", " << next_city << ", " << sekai << '\n';
			q.push({d[sekai][next_city], next_city, sekai});
		}
	}
}

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	cin >> n >> m >> k;
	int	a, b, c;
	
	fill(&d[0][0], &d[21][10001]+1, 1e18);
	for (int i = 0; i < 22; i++)
	{
		d[i][1] = 0;
	}
	for (int i = 1; i <= m; i++)
	{
		cin >> a >> b >> c;
		node[a].push_back({c, b});
		node[b].push_back({c, a});
	}
	q.push({0, 1, 0});
	DijkstraP();
	size_t	ans;
	for (int i = 0; i < k; i++)
		ans = min(d[i][n], d[i + 1][n]);
	if (k == 1)
		ans = min(d[0][n], d[1][n]);
	cout << ans << '\n';
	return (0);
}