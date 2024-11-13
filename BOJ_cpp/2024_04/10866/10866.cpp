#include <iostream>
#include <deque>
using namespace std;

int	main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	deque<int>	Q;
	string		cmd;
	int			count;
	int			num;

	cin >> count;
	for(int i = 0; i < count; i++)
	{
		cin >> cmd;
		if (cmd == "push_front")
		{
			cin >> num;
			Q.push_front(num);
		}
		else if (cmd == "pop_front")
		{
			if (Q.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << Q.front() << '\n';
				Q.pop_front();
			}
		}
		else if (cmd == "push_back")
		{
			cin >> num;
			Q.push_back(num);
		}
		else if (cmd == "pop_back")
		{
			if (Q.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << Q.back() << '\n';
				Q.pop_back();
			}
		}
		else if (cmd == "empty")
		{
			cout << Q.empty() << '\n';
		}
		else if (cmd == "size")
		{
			cout << Q.size() << '\n';
		}
		else if (cmd == "front")
		{
			if (Q.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << Q.front() << '\n';
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
				cout << Q.back() << '\n';
			}
		}
	}
}