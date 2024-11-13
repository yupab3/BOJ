#include <iostream>
#include <vector>

using namespace std;

#define	INF 20'000'000
#define x 0
#define y 1

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int	n;
	cin >> n;

	int	tmp[16][2];
	double d[n][n];
	for (int i = 0; i <= n; i++)
		cin >> tmp[i][x] >> tmp[i][y];
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			d[i][j] = sqrt(pow(tmp[i][x] - tmp[j][x], 2) + pow(tmp[i][y] - tmp[j][y], 2));
			if (d[i][j] == 0) d[i][j] = INF;
		}
	}

	vector<vector<double>> dp(n - 1, vector<double>(n - 1, INF)); // 배열 버전으로 풀어보기
	for (int i = 0; i < 1 << (n - 1); i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			
		}
	}
}