#include <iostream>
#include <stack>
using namespace	std;

int	main(void)
{
	string		str;
	stack<char>	S;
	int			count;
	int			idx;

	cin >> count;
	while (count > 0)
	{
		cin >> str;
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
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
		while (S.empty() == 0)
		{
			S.pop();
		}
		count--;
	}
}