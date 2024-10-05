#include <iostream>
#include <algorithm>

using namespace std;

// 0 -> 비교 대상, 1 -> 현재 최저
int	board[22][22];
int	dp[2][22][22];

int	main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cin >> board[i][j];
	}
	for (int i = 1; i < n; i++)
	{
		
	}
}