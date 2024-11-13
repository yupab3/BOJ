#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int	main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	stack<int>		S;
	vector<char>	sign;
	int				count;
	int				n[100000];
	int				num;
	int				i;

	cin >> count;
	for (i = 0; i < count; i++)
	{
		cin >> n[i];
	}
	i = 0;
	for (int j = 0; j < count; j++)
	{
		while (!(S.empty()) && S.top() == n[i])
		{
			S.pop();
			sign.push_back('-');
			i++;
		}
		S.push(j + 1);
		sign.push_back('+');
	}
	while (!(S.empty()) && S.top() == n[i])
	{
		S.pop();
		sign.push_back('-');
		i++;
	}
	if (S.empty())
	{
		for (int j = 0; j < sign.size(); j++)
		{
			cout << sign[j] << "\n";
		}
	}
	else
	{
		cout << "NO\n";
	}
}