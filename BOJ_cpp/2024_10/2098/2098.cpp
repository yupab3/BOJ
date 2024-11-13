#include <iostream>
#include <vector>

using namespace std;

#define INF 10'000'000

int	n;
int	dist[16][16];
int	dp[15][1 << 15];

// void	print_data(int num)
// {
// 	for (int i = n - 1; i >= 0; i--)
// 	{
// 		cout << (num & (1 << i)) / (1 << i);
// 	}
// }

int	solve(int c, int bf)
{
	if (c == (1 << (n - 1)) - 1) // -> dist 검사안함
	{
		return (dist[bf][n - 1]);
	}
	if (dp[bf][c] != -1) // -1
		return dp[bf][c];
	dp[bf][c] = INF; // 방문하고 나서 그 후에 길이 끊어져있는 경우 1e8 값이 유지되어 계속 방문하는 상황 발생
	// 이거를 -1로 검사를 하고 윗 줄 처럼 아주 큰 값으로 방문을 표시해두면 방지할 수 있다.
	for (int i = 0; i < n - 1; i++)
	{
		if ((c & (1 << i)) == 0 && dist[bf][i] != INF)
		{
			dp[bf][c] = min(dp[bf][c], solve(c | (1 << i), i) + dist[bf][i]);
			// cout << "dp[" << bf << "][" << c << "] = " << dp[bf][c] << '\n';
		}
	}
	return dp[bf][c];
}

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	cin >> n;
	fill(&dp[0][0], &dp[15][0], -1);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> dist[i][j];
			if (dist[i][j] == 0) dist[i][j] = INF;
		}
	}
	int	ans = INF;
	for (int i = 0; i < n - 1; i++)
		ans = min(ans, solve(1 << i, i) + dist[n - 1][i]);
		// cout << "dp[" << bf << "][" << c << "] = " << dp[bf][c] << '\n';
	cout << ans << '\n';
	return (0);
}
// n -> 0000000000000000 ~ 1111111111111111
// 