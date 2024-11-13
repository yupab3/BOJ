#include <iostream>

using namespace std;

int	n, m;
int	death[18];
int	g[18];
int	R[18][18];
int	ans = 0, night = 0, ff = 0;
void	dfs(int day)
{
	if (ff) return ;
	if (2 * n - day <= 1 || death[m])
	{
		ans = max(ans, night);
		if (!death[m]) ff = 1;
		return ;
	}
	if (day % 2 == 1)
	{
		int target = 0;
		for (int i = 1; i <= n; i++)
			if (!death[i] && g[target] < g[i]) target = i;
		death[target] = 1;
		dfs(day + 1);
		death[target] = 0;
		return ;
	}
	for (int i = 1; i <= n; i++)
	{
		if (i == m || death[i]) continue ;
		death[i] = 1;
		for (int j = 1; j <= n; j++)
			g[j] += R[i][j];
		night++;
		dfs(day + 1);
		death[i] = 0;
		for (int j = 1; j <= n; j++)
			g[j] -= R[i][j];
		night--;
	}
}

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	cin >> n;
	fill(&death[0], &death[18], 0);
	g[0] = -1e9;
	for (int i = 1; i <= n; i++)
		cin >> g[i];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cin >> R[i][j];
	}
	cin >> m;
	m++;
	dfs(n);
	cout << ans << '\n';
	return (0);
}

// 0번 부터 시작
// 짝수 : 밤, 홀수 - 낮
// 밤에 i가 죽으면 다른 참가자 j는 R[i][j] 만큼 유죄지수가 오른다
// 낮에 유죄지수가 가장 높은 사람 중 번호가 가장 작은 사람이 죽는다.
// 매번 최적의 선택을 했을 때 몇 밤을 보낼 수 있는가