#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define ii pair<int, int>

int	capacity[54][54];
int	flow[54][54];
int	total_flow;
int	n;

int	cast_alpha(char alpha)
{
	if ('A' <= alpha && alpha <= 'Z') return (alpha - 'A' + 1);
	else if ('a' <= alpha && alpha <= 'z') return (alpha - 'a' + 26 + 1);
	else return (0);
}

void	maximum_flow()
{
	while(true)
	{
		vector<int>	parent(54, -1);
		queue<char>	q;
		parent[1] = 1;
		q.push(1);
		while (q.size() && parent[26] == -1)
		{
			int c_node = q.front();
			q.pop();
			for (int i = 1; i <= 52; i++)
			{
				if (capacity[c_node][i] - flow[c_node][i] > 0 && parent[i] == -1)
				{
					parent[i] = c_node;
					q.push(i);
				}
			}
		}
		if (parent[26] == -1) break ;
		int	cur_flow = 1e9;
		for (int i = 26; i != 1; i = parent[i])
			cur_flow = min(capacity[parent[i]][i] - flow[parent[i]][i], cur_flow);
		for (int i = 26; i != 1; i = parent[i])
		{
			flow[parent[i]][i] += cur_flow;
			flow[i][parent[i]] -= cur_flow;
		}
		total_flow += cur_flow;
	}
}

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int	cost;
	cin >> n;
	char	s, e;
	for (int i = 1; i <= n; i++)
	{
		cin >> s >> e >> cost;
		capacity[cast_alpha(s)][cast_alpha(e)] += cost;
		capacity[cast_alpha(e)][cast_alpha(s)] += cost;
	}
	maximum_flow();
	cout << total_flow << '\n';
}