#include <iostream>
#include <stack>
using namespace	std;

int	main(void)
{
	string		str;
	stack<int>	S;
	int			add;
	int			mul;
	int			idx;
	int			tmp;
	int			ans;

	getline(cin, str);
	idx = 0;
	ans = 0;
	tmp = 1;
	while (str[idx] != '\0')
	{
		S.push(str[idx]);
		if (S.top() == '(')
		{
			tmp *= 2;
		}
		else if (S.top() == '[')
		{
			tmp *= 3;
		}
		else if (S.top() == ')')
		{
			if (S.empty() == 0 && str[idx - 1] == '(')
			{
				ans += tmp;
			}
			tmp /= 2;
			S.pop();
			if (S.empty() || S.top() != '(')
			{
				break;
			}
			S.pop();
		}
		else if (S.top() == ']')
		{
			if (S.empty() == 0 && str[idx - 1] == '[')
			{
				ans += tmp;
			}
			tmp /= 3;
			S.pop();
			if (S.empty() || S.top() != '[')
			{
				break;
			}
			S.pop();
		}
		idx++;
	}
	if (str[idx] != '\0' || S.empty() == 0)
	{
		cout << "0\n";
	}
	else
	{
	cout << ans << '\n';
	}
}