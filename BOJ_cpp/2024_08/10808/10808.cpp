#include <iostream>

using namespace std;

int main()
{
	char	str[102] = {0, };
	int		niddle[256] = {0, };
	fgets(str, 102, stdin);
	int i = 0;
	while (str[i])
	{
		niddle[str[i]]++;
		i++;
	}
	for (int i = 'a'; i <= 'z'; i++)
	{
		cout << niddle[i];
		if (i != 'z') cout << ' ';
	}
	return (0);
}