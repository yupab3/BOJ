#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define	ii	pair<int, int>

vector<ii>	node[1002];
queue<int>	q;
int			my_start, _end;
int			fin, visit[1002];

void	bfs()
{
	while (cin >> my_start >> _end)
	{
		fill(&visit[0], &visit[1001] + 1, 1e9 + 10);
		fin = false;
		q.push(my_start);
		visit[my_start] = 0;
		while (!q.empty())
		{
			if (fin)
			{
				q.pop();
				continue ;
			}
			int	cur = q.front();
			q.pop();
			for (auto next : node[cur])
			{
				int n_node = next.first;
				int	n_cost = next.second;
				if (n_node == _end)
				{
					cout << visit[cur] + n_cost << '\n';
					fin = true;
					break ;
				}
				if (visit[n_node] < visit[cur] + n_cost) continue ;
				visit[n_node] = n_cost + visit[cur];
				q.push({n_node});
			}
		}
	}
}

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int	n, m;
	cin >> n >> m;
	for (int i = 1; i <= n - 1; i++)
	{
		int a, b, cost;
		cin >> a >> b >> cost;
		node[a].push_back({b, cost});
		node[b].push_back({a, cost});
	}
	bfs();
	return (0);
}