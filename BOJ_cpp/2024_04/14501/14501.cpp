#include <iostream>
using namespace std;

int	T[1500005];
int	P[1500005];

int	main(void){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int	N, tmp_P, ans = 0, curmax = 0;

	cin >> N;
	for (int i = 1; i <= N; i++){
		cin >> T[i];
		cin >> tmp_P;
		curmax = max(curmax, P[i]);
		if (i + T[i] <= N + 1){
			P[i + T[i]] = max(P[i + T[i]], curmax + tmp_P);
		}
		ans = max(ans, P[i + T[i]]);
	}
	cout << ans;
}
