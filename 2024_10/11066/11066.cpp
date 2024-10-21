#include <iostream>

using namespace std;

int	cost[502];
int	dp[502][502];

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int	t, k;
	cin >> t;
	while(t--)
	{
		cin >> k;
		fill(&dp[0][0], &dp[502][502], 1e9);
		for (int i = 1; i <= k; i++)
		{
			cin >> cost[i];
			cost[i] += cost[i - 1];
			dp[i][i] = 0;
		}
		for (int n = 1; n < k; n++)
		{
			int i = 1;
			int j = n + 1;
			while (j <= k)
			{
				for (int l = i; l < j; l++)
					dp[i][j] = min(dp[i][j], dp[i][l] + dp[l + 1][j] + cost[j] - cost[i - 1]);
				i++;
				j++;
			}
		}
		cout << dp[1][k] << '\n';
	}
	return (0);
}
// 연속적으로 합쳐야한다.
// 자기 왼쪽 거 / 오른쪽 거 / 안 합치는 거
// 40 30 30 50
// 1부터 n까지 합친 거 + n부터 n+1까지 합친 거 + n+1 부터 p까지 합친거
// 2, 3에 대해 계산할 때
// 1부터 2까지 합친거 + 3 부터 3 까지 비용