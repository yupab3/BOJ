#include <iostream>

using namespace std;

ssize_t	pig[50002];

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int g;
	cin >> g;
	for (ssize_t i = 1; i <= 50000; i++)
		pig[i] = i * i;
	int i = 0;
	while (pig[i] < g)
		i++;
	int j = 1;
	bool you_are_pig = 1;
	while (i < 50001)
	{
		ssize_t res = pig[i] - pig[j];
		if (res == g)
		{
			you_are_pig = 0;
			cout << i << '\n';
			i++;
			continue ;
		}
		if (res < g) i++;
		else j++;
	}
	if (you_are_pig) cout << "-1\n";
	return (0);
}