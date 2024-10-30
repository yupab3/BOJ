#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define ii pair<int, int>

int n, k;
int dp[10002];
vector<ii> lec;

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	cin >> n >> k;
	int l, t;
	for (int i = 1; i <= k; i++)
	{
		cin >> l >> t;
		lec.push_back({l, t});
	}
	for (auto [cl, ct] : lec)
	{
		for (int i = n; i >= ct; i--)
			dp[i] = max(dp[i], dp[i - ct] + cl);
	}
	cout << dp[n];
	return (0);
}