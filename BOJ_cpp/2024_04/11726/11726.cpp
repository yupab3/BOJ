#include <iostream>
using namespace std;

int	DP[1005];

int	main(void){
	int	N;

	cin >> N;
	DP[1] = 1;
	DP[2] = 2;
	if (N == 1){
		cout << DP[N];
		return 0;
	}
	for (int i = 3; i <= N; i++){
		DP[i] = (DP[i - 1] + DP[i - 2]) % 10007;
	}
	cout << DP[N];
}