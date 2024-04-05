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
	int			num;

	cin >> count;
	for(int i = 0; i < count; i++)
	{
		cin >> cmd;
		if (cmd == "push")
		{
			cin >> num;
			Q.push(num);
		}
		else if (cmd == "front")
		{
			if (Q.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << Q.front() << "\n";
			}
		}
		else if (cmd == "back")
		{
			if (Q.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << Q.back() << "\n";
			}
		}
		else if (cmd == "empty")
		{
			cout << Q.empty() << "\n";
		}
		else if (cmd == "size")
		{
			cout << Q.size() << "\n";
		}
		else if (cmd == "pop")
		{
			if (Q.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << Q.front() << "\n";
				Q.pop();
			}
		}
	}
}