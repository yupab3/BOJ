#include <iostream>
#include <stack>
using namespace	std;

int	main(void)
{
	string		str;
	stack<char>	S;
	int			idx;

	while (1)
	{
		getline(cin, str);
		if (str == ".")
		{
			break;
		}
		idx = 0;
		while (str[idx] != '\0')
		{
			if (str[idx] == '(' || str[idx] == '[')
			{
				S.push(str[idx]);
			}
			else if (str[idx] == ')')
			{
				if (S.empty() || S.top() != '(')
				{
					break;
				}
				else
				{
					S.pop();
				}
			}
			else if (str[idx] == ']')
			{
				if (S.empty() || S.top() != '[')
				{
					break;
				}
				else
				{
					S.pop();
				}
			}
			idx++;
		}
		if (S.empty() && str[idx] == '\0')
		{
			cout << "yes\n";
		}
		else
		{
			cout << "no\n";
		}
		while (S.empty() == 0)
		{
			S.pop();
		}
	}
}