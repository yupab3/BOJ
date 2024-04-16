#include <iostream>
using namespace std;

long long	DP[11] = {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
long long	BF[11] = {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

int	main(void){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long	N, ans = 0;
	cin >> N;
	for (int i = 2; i <= N; i++){
		for (int j = 1; j <= 8; j++){
			DP[j] = (BF[j - 1] + BF[j + 1]) % 1000000000;
		}
		DP[0] = BF[1];
		DP[9] = BF[8];
		for (int j = 0; j <= 9; j++){
			BF[j] = DP[j];
		}
	}
	for (int i = 0; i <= 9; i++){
		ans += DP[i];
		ans = ans % 1000000000;
	}
	cout << ans;
}