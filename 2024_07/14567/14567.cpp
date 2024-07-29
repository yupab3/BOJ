#include <iostream>
#include <vector>
using namespace std;
int	main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(0);

	vector<int> dp[1005];
	int	ans[1005] = {0, };
	int	n, m;
	int	lhs, rhs;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> lhs >> rhs;
		dp[rhs].push_back(lhs);
	}
	std::cout << "1 ";
	for (int i = 2; i <= n; i++)
	{
		for (vector<int>::iterator it = dp[i].begin(); it != dp[i].end(); ++it)
		{
			ans[i] = max(ans[i], ans[*it] + 1);
		}
		std::cout << ans[i] + 1;
		if (i != n)
			std::cout << " ";
	}
	std::cout << '\n';
}
