#include <iostream>
#include <list>

using namespace std;

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	list<int>	L;
	int	n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) L.push_back(i);

	auto it = L.begin();
	for (int i = 1; i < k; i++)
	{
		++it;
		if (it == L.end())
			it = L.begin();
	}
	
	cout << '<';
	while (L.size())
	{
		cout << *it;
		it = L.erase(it);
		if (L.size())
			cout << ", ";
		for (int i = 1; i < k; i++)
		{
			if (it == L.end())
				it = L.begin();
			++it;
			if (it == L.end())
				it = L.begin();
		}
	}
	cout << ">\n";
}