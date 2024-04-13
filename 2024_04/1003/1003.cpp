#include <iostream>
using namespace std;

int	DP[45][2];

int	main(void){
	int	N, trgt;

	DP[0][0] = 1;
	DP[0][1] = 0;
	DP[1][0] = 0;
	DP[1][1] = 1;
	for (int i = 2; i <= 40; i++){
		DP[i][0] = DP[i - 1][0] + DP[i - 2][0];
		DP[i][1] = DP[i - 1][1] + DP[i - 2][1];
	}
	cin >> N;

	for (int i = 1; i <= N; i++){
		cin >> trgt;
		cout << DP[trgt][0] << ' ' << DP[trgt][1] << '\n';
	}
}