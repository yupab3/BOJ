#include <iostream>
#include <algorithm>

using namespace std;

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int	arr[10] = {0, };
	int	n;
	cin >> n;
	while (n > 0)
	{
		arr[n % 10]++;
		n = n / 10;
	}
	arr[6] += arr[9];
	arr[6] = arr[6] % 2 + arr[6] / 2;
	int	_max = 0;
	for (int i = 0; i <= 8; i++)
	{
		_max = max(arr[i], _max);
	}
	cout << _max << '\n';
	return (0);
}
