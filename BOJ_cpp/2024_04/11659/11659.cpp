#include <iostream>
using namespace std;

int	DP[100005];

int	main(void){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int	N, M, j, k, ans;

	cin >> N;
	cin >> M;
	cin >> DP[1];
	for (int i = 2; i <= N; i++){
		cin >> DP[i];
		DP[i] += DP[i - 1];
	}
	for (int i = 1; i <= M; i++){
		cin >> j >> k;
		cout << DP[k] - DP[j - 1] << '\n';
	}
}