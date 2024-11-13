#include <iostream>
#include <string>

using namespace std;

size_t		ans = 1;
int			depth = 0;
string		card;

int			sungyoon[2][42];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	cin >> card;
	if (card[0] != 0)
			sungyoon[0][0] = 1;
	for (int i = 1; i < card.size(); i++)
	{
		if (card[i] - 48 != 0)
			sungyoon[0][i] = 1;
		if ()
			sungyoon[1][i] = 1;
	}
	for (int i = 1; i < card.size(); i++)
	{
		ans *= (sungyoon[0][i] + sungyoon[1][i]);
	}
	cout << ans << '\n';
	return (0);
}
// i번째 인덱스에서 가능한 경우의 수
// 