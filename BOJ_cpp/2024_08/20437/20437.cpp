#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int t, k;
	cin >> t;
	string w;
	for (int i = 1; i <= t; i++)
	{
		cin >> w >> k;
		vector<int>	v[26];
		int _min = 2e9 + 5;
		int _max = 0;
		int j = 0;
		while (w[j] != '\0')
		{
			v[w[j] - 97].push_back(j);
			j++;
		}
		for (j = 0; j < 26; j++)
		{
			if (v[j].size() >= k)
			{
				auto st = v[j].begin();
				auto en = v[j].begin();
				int l = 0;
				while (++l < k)
					++en;
				while (en != v[j].end())
				{
					_min = min(_min, *en - *st + 1);
					_max = max(_max, *en - *st + 1);
					++st;
					++en;
				}
			}
		}
		if (_min == 2e9 + 5)
			cout << "-1\n";
		else
			cout << _min << ' ' << _max << '\n';
	}
	return (0);
}