#include <iostream>
using namespace std;

int	DP[505][505];

int	main(void){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int	N, trgt, ans = 0;

	cin >> N;
	cin >> trgt;
	DP[1][1] = trgt;
	for (int i = 2; i <= N; i++){
		for (int j = 1; j <= i; j++){
			cin >> trgt;
			DP[i][j] = trgt + DP[i - 1][j];
			if (j > 1) DP[i][j] = max(DP[i][j], trgt + DP[i - 1][j - 1]);
			ans = max(ans, DP[i][j]);
		}
	}
	ans = max(ans, DP[1][1]);
	cout << ans;
}