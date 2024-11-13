#include <iostream>
#include <stack>
using namespace	std;

int	main(void)
{
	string		str;
	stack<char>	S;
	int			count;
	int			ans;
	int			idx;

	ans = 0;
	cin >> count;
	while (count > 0)
	{
		cin >> str;
		idx = 0;
		while (str[idx] != '\0')
		{
			if (S.empty() == 0 && S.top() == str[idx])
			{
				S.pop();
			}
			else
			{
				S.push(str[idx]);
			}
			idx++;
		}
		// while (S.empty() == 0)
		// {
		// 	if (S.empty() == 0 && S.top() == 'A')
		// 	{
		// 		S.pop();
		// 		if (S.empty() == 0 && S.top() == 'A')
		// 		{
		// 			S.pop();
		// 		}
		// 		else if (S.empty())
		// 		{
		// 			ans--;
		// 			break;
		// 		}
		// 		else
		// 		{
		// 			break;
		// 		}
		// 	}
		// 	if (S.empty() == 0 && S.top() == 'B')
		// 	{
		// 		S.pop();
		// 		if (S.empty() == 0 && S.top() == 'B')
		// 		{
		// 			S.pop();
		// 		}
		// 		else if (S.empty())
		// 		{
		// 			ans--;
		// 			break;
		// 		}
		// 		else
		// 		{
		// 			break;
		// 		}
		// 	}
		// }
		if (S.empty())
		{
			ans++;
		}
		while (S.empty() == 0)
		{
			S.pop();
		}
		count--;
	}
	cout << ans << '\n';
}