#include <iostream>

using namespace std;

int	b[302][302];

void	rotate_b(int cn, int cm, int st)
{
	int tmp = b[st + 1][st + 1];
	for (int i = st + 1; i < cm + st; i++)
		b[st + 1][i] = b[st + 1][i + 1];
	for (int i = st + 1; i < cn + st; i++)
		b[i][cm + st] = b[i + 1][cm + st];
	for (int i = cm + st; i > st + 1; i--)
		b[cn + st][i] = b[cn + st][i - 1];
	for (int i = cn + st; i > st + 1; i--)
		b[i][st + 1] = b[i - 1][st + 1];
	b[st + 2][st + 1] = tmp;
}

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int	n, m, r;
	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			cin >> b[i][j];
	}
	int total_rt = min(n, m) / 2;
	for (int i = 0; i < total_rt; i++)
	{
		int cn = n - i * 2; // 3
		int cm = m - i * 2; // 2
		int cr = r % (cn * 2 + cm * 2 - 4);
		for (int j = 1; j <= cr; j++)
			rotate_b(cn, cm, i);
	}
	// cout << '\n';
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			cout << b[i][j] << ' ';
		cout << '\n';
	}
	return (0);
}