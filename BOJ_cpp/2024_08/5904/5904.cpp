#include <iostream>

using namespace std;

int	idx;

void	moocursive(int moo, int depth)
{
	if (moo < idx) moocursive(moo + depth + 3 + moo, depth + 1);
	else return ;
	if (moo <= idx) idx -= moo;
	else return ;
	if (depth + 3 <= idx) idx -= depth + 3;
}

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
	cin >> idx;
	moocursive(3, 1);
	if (idx == 1) cout << "m\n";
	else cout << "o\n";
	return (0);
}