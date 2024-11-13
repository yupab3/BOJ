#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int	d, n;
int	frame[300002];

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	cin >> d >> n;
	int	tmp;
	fill(&frame[0], &frame[300001], 1e9 + 5);
	for (int i = 1; i <= d; i++)
	{
		cin >> tmp;
		frame[i] = frame[i - 1];
		if (tmp < frame[i]) frame[i] = tmp;
		// cout << "frame: " << frame[i] << '\n';
	}
	int	idx;
	int	flag = false;
	for (int i = n; i >= 1; i--)
	{
		cin >> tmp;
		while (d)
		{
			// cout << "tmp: " << tmp << ", d: " << d << '\n';
			if (frame[d] < tmp) d--;
			else
			{
				d--;
				if (i == 1) flag = true;
				break ;
			}
		}
	}
	if (flag) d++;
	cout << d << '\n';
	return (0);
}