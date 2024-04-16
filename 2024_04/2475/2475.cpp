#include <iostream>
using namespace std;

int	main(void){
	int	ans = 0, N;

	for (int i = 1; i <= 5; i++){
		cin >> N;
		ans += N * N;
	}
	cout << ans % 10;
}