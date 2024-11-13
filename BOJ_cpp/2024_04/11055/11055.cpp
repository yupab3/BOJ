#include <iostream>
using namespace std;

int	DP[1005][3];

int	main(void){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int	N, ans;

	cin >> N;
	cin >> DP[1][1];
	DP[1][2] = DP[1][1];
	ans = DP[1][2];
	for (int i = 2; i <= N; i++){
		cin >> DP[i][1];
		for (int j = 1; j < i; j++){
			if (DP[j][1] < DP[i][1] && DP[j][2] > DP[i][2]) DP[i][2] = DP[j][2];
		}
		DP[i][2] += DP[i][1];
		ans = max(ans, DP[i][2]);
	}
	cout << ans;
}