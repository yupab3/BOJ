#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

#define ll pair<long, long>
#define dl pair<double, long>

priority_queue<dl, vector<dl>, greater<dl> >	pq;
vector<dl>			node[1002];
vector<ll>			point;

bool	visit[1002];
int	n, m, cnt = 1;
double ans = 0;

void	prim()
{
	while (!pq.empty())
	{
		if (cnt == n)
			break ;
		auto [n_cost, n_node] = pq.top();
		pq.pop();
		if (visit[n_node]) continue ;
		visit[n_node] = true;
		ans += n_cost;
		// cout << "node: " << n_node << ", cost: " << n_cost << "  ->  ans: " << ans << '\n';
		cnt++;
		for (auto next : node[n_node])
			pq.push(next);
	}
}

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	cin >> n >> m;
	int	x, y;
	for (int i = 1; i <= n; i++)
	{
		cin >> x >> y;
		point.push_back({x, y});
	}
	for (int i = 1; i <= m; i++)
	{
		cin >> x >> y;
		node[x].push_back({0, y});
		node[y].push_back({0, x});
	}
	for (int i = 0; i < n; i++)
	{
		auto cur = point[i];
		for (int j = i + 1; j < n; j++)
		{
			auto next = point[j];
			double dis = sqrt(pow(cur.first - next.first, 2) + pow(cur.second - next.second, 2));
			node[i + 1].push_back({dis, j + 1});
			node[j + 1].push_back({dis, i + 1});
		}
	}
	for (auto next : node[1])
		pq.push(next);
	visit[1] = true;
	prim();
	cout << fixed << setprecision(2) << ans << '\n';
	return (0);
}