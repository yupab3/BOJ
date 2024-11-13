#include <iostream>
using namespace std;

int	main(void){
	int	ans, cur = 0, N;
	string	str;

	cin >> N;
	for (int i = 1; i <= N; i++){
		ans = 0;
		cur = 0;
		cin >> str;
		for (size_t j = 0; j < str.size(); j++){
			if (str[j] == 'O') cur++;
			else cur = 0;
			ans += cur;
		}
		cout << ans << '\n';
	}
}