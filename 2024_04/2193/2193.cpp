#include <iostream>
using namespace std;

long long DP[95];

int main(void){
    int N;

    cin >> N;
    DP[1] = 1;
    DP[2] = 1;
    for (int i = 3; i <= N; i++){
        for (int j = i - 2; j > 0; j--){
            DP[i] += DP[j];
        }
        DP[i]++;
    }
    cout << DP[N];
}