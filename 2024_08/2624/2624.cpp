#include <iostream>
#include <set>
#include <map>

#define	ii	pair<int, int>

using namespace std;

int	dp[102][10002];

set<ii>		coins;
int			ans = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int t, k, p, n, sum = 0;
	cin >> t >> k;

	for (int i = 1; i <= k; i++)
	{
		cin >> p >> n;
		coins.insert({p, n});
	}
	auto it = coins.begin();
	for (int i = 1; i <= k; i++)
	{
		int	c_pi = (*it).first;
		int	c_ni = (*it).second;
		for (int j = 0; j <= c_ni; j++)
		{
			if (c_pi * j > t) break ;
			if (it != coins.begin())
			{
				--it;
				int	b_pi = (*it).first;
				++it;
				// cout << "------\n";
				for (int l = 1; l <= t; l++)
				{
					if (c_pi * j + l > t) break ;
					dp[i][c_pi * j + l] += dp[i - 1][l];
					// cout << c_pi << ", " << c_pi * i + j << " += " << b_pi << ", " << j << " -> " << dp[c_pi][c_pi * i + j] << '\n';
				}
				// cout << "------\n";
			}
			dp[i][c_pi * j]++;
		}
		++it;
		// cout << "----case: " << c_pi << " has done ----\n";
	}
	// for (int i = 1; i <= k; i++)
	// {
	// 	for (int j = 1; j <= t; j++)
	// 	{
	// 		cout << dp[i][j] << ' ';
	// 	}
	// 	cout << '\n';
	// }
	it = coins.end();
	--it;
	ans = dp[k][t];
	cout << ans << '\n';
	return (0);
}