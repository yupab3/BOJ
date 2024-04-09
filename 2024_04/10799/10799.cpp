#include <iostream>
#include <stack>
using namespace	std;

int	main(void)
{
	string		str;
	stack<char>	S;
	char		p_paren;
	int			idx;
	size_t		ans;

	getline(cin, str);
	idx = 0;
	ans = 0;
	while (str[idx] != '\0')
	{
		if (str[idx] == '(')
		{
			p_paren = '(';
			S.push(str[idx]);
		}
		else if (str[idx] == ')')
		{
			S.pop();
			if (p_paren == '(')
			{
				ans += S.size();
			}
			else
			{
				ans += 1;
			}
			p_paren = ')';
		}
		idx++;
	}
	cout << ans << '\n';
}