#include <iostream>
#include <stack>

using namespace std;

stack<int>	a, b, c;
int	cnt[1000002];

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int	n;
	cin >> n;
	int tmp;
	for (int i = 1; i <= n; i++)
	{
		cin >> tmp;
		cnt[tmp]++;
		a.push(tmp);
	}
	while(a.size())
	{
		int cur = a.top(); a.pop();
		int trgt = 0;
		stack<int> d = c;
		while (d.size())
		{
			if (cnt[d.top()] > cnt[cur])
			{
				trgt = d.top();
				break ;
			}
			d.pop();
		}
		if (trgt == 0) b.push(-1);
		else	b.push(trgt);
		// cout << trgt << '\n';
		while (c.size() && cnt[c.top()] <= cnt[cur])
			c.pop();
		c.push(cur);
	}
	while(b.size())
	{
		int cur = b.top(); b.pop();
		cout << cur << ' ';
	}
	return (0);
}