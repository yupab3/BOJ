#include <iostream>
#include <queue>
#include <deque>
using namespace	std;

int	main(void)
{
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int			T;
	string		p;
	int			n;
	string		x;
	int			idx;
	int			num;
	deque<int>	arr;
	int			R;

	cin >> T;
	while (T > 0)
	{
		cin >> p;
		cin >> n;
		cin >> x;
		R = 0;
		num = 0;
		idx = 0;
		while (n > 0)
		{
			if ('0' <= x[idx] && x[idx] <= '9')
			{
				num = num * 10 + x[idx] - 48;
			}
			else if (num != 0)
			{
				arr.push_back(num);
				num = 0;
				n--;
			}
			idx++;
		}
		idx = 0;
		while (idx < p.size())
		{
			if (p[idx] == 'R')
			{
				if (R)
				{
					R = 0;
				}
				else
				{
					R = 1;
				}
			}
			else if (arr.empty())
			{
				cout << "error\n";
				break;
			}
			else
			{
				if (R)
				{
					arr.pop_back();
				}
				else
				{
					arr.pop_front();
				}
			}
			idx++;
		}
		if (idx == p.size())
		{
			if (R)
			{
				cout << '[';
				while (arr.empty() == 0)
				{
					cout << arr.back();
					arr.pop_back();
					if (arr.empty() == 0)
					{
						cout << ',';
					}
				}
				cout << "]\n";
			}
			else
			{
				cout << '[';
				while (arr.empty() == 0)
				{
					cout << arr.front();
					arr.pop_front();
					if (arr.empty() == 0)
					{
						cout << ',';
					}
				}
				cout << "]\n";
			}
		}
		T--;
	}
}