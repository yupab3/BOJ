#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack<int> stk;
ssize_t ans;

int	main()
{
	string str;
	cin >> str;
	int idx = 0;
	while (str[idx])
	{
		if (str[idx] == '(')
			stk.push(-1);
		else if (str[idx] == ')')
		{
			while (stk.top() != -1)
			{
				stk.pop();
				ans++;
			}
			stk.pop();
			ans *= (stk.top() - 48);
			stk.pop();
		}
		else stk.push(str[idx]);
		idx++;
	}
	cout << ans + stk.size() << '\n';
	return (0);
}