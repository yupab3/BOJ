#include <iostream>
#include <string>

using namespace std;


int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	string str;
	cin >> str;
	bool	mode = str[0] - 48;
	int	i = 0;
	bool	flag = 0;
	for (; i < str.size(); i++)
	{
		// cout << "mode: " << mode << '\n';
		if (mode)
		{
			if (str[i] == '1' && str[i + 1] == '0' && str[i + 2] == '0')
			{
				i += 3;
				while (str[i] == '0')
					i++;
				if (str[i] == '1')
				{
					if (str[i + 1] == '0' && str[i + 2] == '0')
					{
						flag = 1;
						break ;
					}
					while (str[i + 1] == '1')
						i++;
					if (str[i + 1] == '\0')
					{
						break ;
					}
				}
				else 
				{
					flag = 1;
					break ;
				}
			}
			else
			{
				flag = 1;
				break ;
			}
			if (str[i + 1] == '0' && str[i + 2] == '1')
				mode = 0;
			else i--;
		}
		else
		{
			if (str[i] == '0' && str[i + 1] == '1')
				i += 2;
			else 
			{
				flag = 1;
				break ;
			}
			if (str[i] == '1') mode = 1;
			i--;
		}
	}
	if (flag) cout << "NOISE\n";
	else cout << "SUBMARINE\n";
	return (0);
}