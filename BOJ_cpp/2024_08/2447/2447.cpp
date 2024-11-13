#include <iostream>

using namespace std;

int n;

void	draw_that_fucking_shit_square(int cur_x, int cur_y, int num)
{
	if ((cur_x / num) % 3 == 1 && (cur_y / num) % 3 == 1) cout << ' ';
	else if (num == 1) cout << '*';
	else draw_that_fucking_shit_square(cur_x, cur_y, num / 3);
}

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			draw_that_fucking_shit_square(i, j, n);
		cout << '\n';
	}
	return (0);
}
