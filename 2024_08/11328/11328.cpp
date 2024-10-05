#include <iostream>

using namespace std;

int	main()
{
	cin.tie(NULL);cout.tie(NULL);

	int	n;
	cin >> n;
	//fflush(stdin);
	for (int i = 0; i < n; i++)
	{
		char	str[2004] = {0, };
		scanf("%s %s", str, &str[1000]);
		//fflush(stdin);
		//cout << str << " " << &str[1000] << '\n';
		int	_count[256] = {0, };
		int j = 0;
		for (; j < 1000; j++)
			_count[str[j]]++;
		for (; j < 2000; j++)
			_count[str[j]]--;
		for (int k = 'a'; k <= 'z'; k++)
		{
			if (_count[k] != 0)
			{
				cout << "Impossible\n";
				break ;
			}
			else if (k == 'z')
			{
				cout << "Possible\n";
				break ;
			}
		}
	}
	return (0);
}
