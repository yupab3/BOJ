#include <iostream>
#include <string>

using namespace std;

string	v;
int n, ans = -2147483648;

int	do_op(int num1, int num2, int op)
{
	if (op == '+')
		return (num1 + num2);
	if (op == '-')
		return (num1 - num2);
	if (op == '*')
		return (num1 * num2);
	return (0);
}

void	dfs(int idx, int cur)
{
	if (idx > n - 1)
	{
		ans = max(ans, cur);
		return ;
	}
	int c_op;
	if (idx == 0) c_op = '+';
	else	c_op = v[idx - 1];
	if (idx + 2 < n)
	{
		int res = do_op(v[idx] - '0', v[idx + 2] - '0', v[idx + 1]);
		dfs(idx + 4, do_op(cur, res, c_op));
	}
	dfs(idx + 2, do_op(cur, v[idx] - '0', c_op));
}

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	cin >> n;

	int tmp;
	cin >> v;
	dfs(0, 0);
	cout << ans << '\n';
	return (0);
}