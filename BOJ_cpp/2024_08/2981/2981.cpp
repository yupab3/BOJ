#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

size_t		board[102];
size_t		trgt[102];
set<int>	ans;

int	gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

int	main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> board[i];
	}
	sort(board + 1, board + n + 1);
	int	div = board[2] - board[1];
	for (int i = 3; i <= n; i++)
	{
		div = gcd(div, board[i] - board[i - 1]);
	}
	for (int i = 1; i <= sqrt(div); i++)
	{
		if (div % i == 0)
		{
			ans.insert(i);
			ans.insert(div / i);
		}
	}
	for (auto it = ans.begin(); it != ans.end(); ++it)
	{
		if (*it != 1)
		{
			cout << *it;
			if (it != --(ans.end())) cout << ' ';
		}
	}
	return (0);
}