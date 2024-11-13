#include <iostream>
using namespace std;

int DP[1005];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;

    cin >> N;
    DP[1] = 1;
    DP[2] = 3;
    for (int i = 3; i <= N; i++){
        DP[i] = (DP[i - 2] * 2 + DP[i - 1]) % 10007;
    }
    cout << DP[N];
}