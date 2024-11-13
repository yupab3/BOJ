#include <iostream>
#include <queue>
using namespace std;

int	main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	queue<int>	Q;
	string		cmd;
	int			count;
	int			i;
	int			num;

	cin >> count;
	if (count == 1)
	{
		cout << "1";
		return (0);
	}
	for (i = 0; i < count; i++)
	{
		Q.push(i + 1);
	}
	i = 0;
	while (Q.size() > 1)
	{
		if (i % 2 == 0)
		{
			Q.pop();
			i = 1;
		}
		if (i % 2 == 1)
		{
			Q.push(Q.front());
			Q.pop();
			i = 0;
		}
	}
	cout << Q.front();
}