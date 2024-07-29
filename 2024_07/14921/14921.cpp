#include <iostream>
#include <vector>

using namespace std;

int	main(void)
{
	ios::sync_with_stdio(0);
	std::cin.tie(0);
	vector<int> a;
	vector<int>::iterator it_n;
	vector<int>::iterator it_p;
	int n, c;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> c;
		a.push_back(c);
	}

	int min = -200000000;
	it_n = a.begin();
	it_p = --(a.end());
	while (it_p != it_n)
	{
		int tmp;
		// std::cout << "*it_p: " << *it_p << ", *it_n: " << *it_n << '\n';
		tmp = *it_p + *it_n;
		if (std::min(std::abs(min), std::abs(tmp)) != std::abs(min))
			min = tmp;
		if (tmp < 0)
			++it_n;
		else
			--it_p;
		// std::cout << "min: " << min << '\n';
	}
	std::cout << min << '\n';
	return 0;
}