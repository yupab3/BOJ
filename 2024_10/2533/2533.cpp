#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define	ii		pair<int, int>
#define	JJAK	0
#define	HOL		1

vector<int>	e[1000002];
int			visit[1000002];
int			ans;

int	dfs(int c_no)
{
	if (c_no != 1 && e[c_no].size() == 1)
	{
		return (1);
	}
	int rt_v = 0;
	for (int n_no : e[c_no])
	{
		if (visit[n_no]) continue ;
		visit[n_no] = 1;
		rt_v += dfs(n_no);
	}
	if (rt_v)
		ans++;
	else
		return (1);
	return (0);
}

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int n, u, v;
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	visit[1] = 1;
	dfs(1);
	cout << ans << '\n';
	return (0);
}
// 정점: 사람, 노드: 친구관계
// 연결되어있는 모든 정점이 얼리면 얼리가 된다.