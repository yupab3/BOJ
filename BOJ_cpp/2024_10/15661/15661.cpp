#include <iostream>
#include <vector>

using namespace std;

int	score[22][22];
int	n, cnt, ans = 10000000;

void	dfs(int idx, vector<int>& start, vector<int>& link)
{
	if (idx == n + 1)
	{
		int score_start = 0, score_link = 0;
		for (auto it = start.begin(); it != start.end(); ++it)
		{
			auto n_it = it;
			++n_it;
			while (n_it != start.end())
			{
				score_start += score[*it][*n_it] + score[*n_it][*it];
				++n_it;
			}
		}
		for (auto it = link.begin(); it != link.end(); ++it)
		{
			auto n_it = it;
			++n_it;
			while (n_it != link.end())
			{
				score_link += score[*it][*n_it] + score[*n_it][*it];
				++n_it;
			}
		}
		ans = min(ans, abs(score_start - score_link));
		return ;
	}
	start.push_back(idx);
	dfs(idx + 1, start, link);
	start.pop_back();
	link.push_back(idx);
	dfs(idx + 1, start, link);
	link.pop_back();
	return ;
}

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cin >> score[i][j];
	}
	vector<int>	start;
	vector<int>	link;
	dfs(1, start, link);
	cout << ans << '\n';
	return (0);
}