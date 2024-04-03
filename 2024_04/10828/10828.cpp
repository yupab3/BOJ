#include <iostream>
#include <stack>
using namespace std;

int	main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	stack<int>	S;
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
			S.push(num);
		}
		else if (cmd == "top")
		{
			if (S.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << S.top() << "\n";
			}
		}
		else if (cmd == "empty")
		{
			cout << S.empty() << "\n";
		}
		else if (cmd == "size")
		{
			cout << S.size() << "\n";
		}
		else if (cmd == "pop")
		{
			if (S.empty())
			{
				cout << "-1\n";
			}
			else
			{
				cout << S.top() << "\n";
				S.pop();
			}
		}
	}
}