#include <iostream>
using namespace std;

int DP[100005][2];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, ans = -1000;

    cin >> N;
    cin >> DP[1][1];
    DP[1][2] = DP[1][1];
    for (int i = 2; i <= N; i++){
        cin >> DP[i][2];
        DP[i][1] = max(DP[i - 1][1] + DP[i][2], DP[i][2]);
    }
    for (int i = 1; i <= N; i++){
        ans = max(ans, DP[i][1]);
    }
    cout << ans;
}