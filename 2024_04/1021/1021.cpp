#include <iostream>
#include <deque>
using namespace	std;

int	main(void)
{
	ios::sync_with_stdio(0);
	std::cin.tie(0);
	deque<int>	D;
	deque<int>	D2;
	deque<int>	D3;
	int			size;
	int			cmds;
	int			num;
	int			trgt;
	int			cmd2;
	int			cmd3;

	cmds = 0;
	cin >> size;
	cin >> num;
	for (int i = 0; i < size; i++)
	{
		D.push_back(i + 1);
	}
	while (num > 0)
	{
		cin >> trgt;
		cmd2 = 0;
		cmd3 = 0;
		D2 = D;
		D3 = D;
		while (trgt != D2.front())
		{
			D2.push_back(D2.front());
			D2.pop_front();
			cmd2++;
		}
		while (trgt != D3.front())
		{
			D3.push_front(D3.back());
			D3.pop_back();
			cmd3++;
		}
		if (cmd2 <= cmd3)
		{
			while (trgt != D.front())
			{
				D.push_back(D.front());
				D.pop_front();
				cmds++;
			}
		}
		else
		{
			while (trgt != D.front())
			{
				D.push_front(D.back());
				D.pop_back();
				cmds++;
			}
		}
		D.pop_front();
		num--;
	}
	cout << cmds << '\n';
}