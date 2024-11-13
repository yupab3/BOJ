#include <iostream>

using namespace std;

int	main()
{
	cin.tie(NULL);cout.tie(NULL);

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
	int ans = 0;
	for (int k = 'a'; k <= 'z'; k++)
		ans += abs(_count[k]);
	cout << ans << '\n';
	return (0);
}
