#include <iostream>

using namespace std;

int	dp[101][1 << 10][10];
int	bf[101][1 << 10][10];

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int	n;
	cin >> n;
	fill(&dp[1][0][0], &dp[101][0][0], 1);
	for (int j = 1; j <= 100; j++)
		dp[j][1 << 0][0] = 0;
	for (int j = 1; j <= 100; j++)
	{
		for (int k = 0; k < (1 << n); k++)
		{
			for (int i = 1; i <= 8; i++)
				dp[j][k | (1 << i)][i] = (dp[j - 1][k][i - 1] + dp[j - 1][k][i + 1]) % 1000000000;
			dp[j][k | (1 << 0)][0] = dp[j - 1][k][1];
			dp[j][k | (1 << 9)][9] = dp[j - 1][k][8];
		}
	}
}
// 계단수 : 현재 숫자 = 이전 숫자 중 현재 숫자와 1차이 나는 애들의 합
// 갱신 값 : 현재 자릿수[현재비트][추가할 숫자] = 이전 자릿수[i - 1 이 없는 비트][i - 1] + 이전 자릿수[i + 1이 없는 비트][i + 1]
// k는 비트, i는 추가할 숫자, j는 자릿수
// i == 0 -> i - 1은 계산 ㄴ, i == 9 -> i + 1 은 계산 ㄴㄴ
