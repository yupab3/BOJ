#include <iostream>
#include <stack>
using namespace	std;

int	DP[1000005];

int	main(void){
	int	N, tmp;

	cin >> N;
	DP[1] = 0;
	DP[2] = 1;
	DP[3] = 1;
	for (int i = 4; i <= N; i++){
		DP[i] = DP[i - 1] + 1;
		if (i % 2 == 0) DP[i] = min(DP[i], DP[i / 2] + 1);
		if (i % 3 == 0) DP[i] = min(DP[i], DP[i / 3] + 1);
	}
	cout << DP[N] << '\n' << N;
	tmp = N;
	while (1){
		if (tmp != 1) cout << ' ';
		else break;
		if (DP[tmp - 1] == DP[tmp] - 1){
			tmp = tmp - 1;
			cout << tmp;
		}
		else if (tmp % 2 == 0 && DP[tmp / 2] == DP[tmp] - 1){
			tmp = tmp / 2;
			cout << tmp;
		}
		else if (tmp % 3 == 0 && DP[tmp / 3] == DP[tmp] - 1){
			tmp = tmp / 3;
			cout << tmp;
		}
	}
}