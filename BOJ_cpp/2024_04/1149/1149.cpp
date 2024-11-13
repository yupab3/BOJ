#include <iostream>
using namespace std;

int	DP[1002][5];

int	main(void){
	int	N;

	cin >> N;
	cin >> DP[1][1];
	cin >> DP[1][2];
	cin >> DP[1][3];
	for (int i = 2; i <= N; i++){
		for (int j = 1; j <= 3; j++){
			cin >> DP[i][j];
			if (j == 1){
				DP[i][j] = min(DP[i - 1][j + 1] + DP[i][j], DP[i - 1][j + 2] + DP[i][j]);
			}
			else if (j == 2){
				DP[i][j] = min(DP[i - 1][j - 1] + DP[i][j], DP[i - 1][j + 1] + DP[i][j]);
			}
			else if (j == 3){
				DP[i][j] = min(DP[i - 1][j - 2] + DP[i][j], DP[i - 1][j - 1] + DP[i][j]);
			}
		}
	}
	cout << min(DP[N][1], min(DP[N][2], DP[N][3]));
}