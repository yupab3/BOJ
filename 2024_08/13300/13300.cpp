#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int	n, k, s, y;
	cin >> n >> k;
	int room[2][8] = {0, };
	for (int i = 1; i <= n; i++)
	{
		cin >> s >> y;
		room[s][y]++;
	}
	int	ans = 0;
	for (int i = 1; i <= 6; i++)
	{
		ans += room[0][i] / k + (room[0][i] % k > 0);
		ans += room[1][i] / k + (room[1][i] % k > 0);
	}
	cout << ans << '\n';
	return (0);
}