#include <iostream>
#include <stack>
using namespace std;

int	main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	stack<int>	S;
	long long	sum;
	int			num;
	int			count;

	sum = 0;
	cin >> count;
	for (int i = 0; i < count; i++)
	{
		cin >> num;
		if (num == 0)
		{
			if (S.empty())
			{
				continue ;
			}
			else
			{
				sum -= S.top();
				S.pop();
			}
		}
		else
		{
			sum += num;
			S.push(num);
		}
	}
	cout << sum << "\n";
}