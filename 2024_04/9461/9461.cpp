#include <iostream>
using namespace std;

long long	DP[105];

int	main(void){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int	N, trgt;

	cin >> N;
	DP[1] = 1;
	DP[2] = 1;
	DP[3] = 1;
	for (int i = 4; i <= 100; i++){
		DP[i] = DP[i - 2] + DP[i - 3];
	}
	for (int i = 1; i <= N; i++){
		cin >> trgt;
		cout << DP[trgt];
		if (i != N) cout << '\n';
	}
}