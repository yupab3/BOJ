#include <iostream>
#include <algorithm>

using namespace std;

int	a[2002];
int	b[2002];
int	dp[2002][2002];
int n = 0;

int	sol(int i, int j)
{
	if (i == n + 1 || j == n + 1) return (0);
	else if (dp[i][j] != -1) return dp[i][j];

	if (a[i] > b[j])
	{
		dp[i][j] = b[j] + sol(i, j + 1);
		return dp[i][j];
	}
	else
	{
		dp[i][j] = max(sol(i + 1, j), sol(i + 1, j + 1));
		return dp[i][j];
	}
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		cin >> b[i];
	for (int i = 0; i < 2002; i++)
		fill(dp[i], dp[i]+2001, -1);
    cout << sol(1, 1) << '\n';
    return (0);
}