#include <iostream>
#include <numeric>

using namespace std;

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	cout << m - gcd(n, m) << '\n';
	return (0);
}