#include <iostream>

using namespace std;

#define INF	10000000

int	dp[5][5][100002];
int	step[100002];
int	d[5][5];

void	init_d()
{
	d[0][0] = 1;
	for (int i = 1; i <= 4; i++)
	{
		d[0][i] = 2;
		d[i][i] = 1;
	}
	for (int i = 1; i < 4; i++)
		d[i][i + 1] = 3;
	d[4][1] = 3;
	for (int i = 4; i > 1; i--)
		d[i][i - 1] = 3;
	d[1][4] = 3;
	for (int i = 1; i <= 2; i++)
	{
		d[i][i + 2] = 4;
		d[i + 2][i] = 4;
	}
}

int	solve(int l, int r, int cnt)
{
	if (step[cnt] == 0) return 0;
	if (l == r && l != 0) return INF;

	int &cache = dp[l][r][cnt];
	if (cache != -1) return cache;
	return dp[l][r][cnt] = min(solve(step[cnt], r, cnt + 1) + d[l][step[cnt]], solve(l, step[cnt], cnt + 1) + d[r][step[cnt]]);
}

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int	n, r = 0, l = 0, cnt = 1;
	init_d();
	while (cin >> n)
	{
		step[cnt++] = n;
		if (n == 0) break ;
	}
	fill(&dp[0][0][0], &dp[5][0][0], -1);
	cout << solve(l, r, 1) << '\n';
	return (0);
}