#include <iostream>
using namespace std;

int arr[12];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T, N;
    arr[1] = 1; arr[2] = 2; arr[3] = 4;
    cin >> T;
    for (int i = 4; i < 11; i++){
        arr[i] = arr[i - 3] + arr[i - 2] + arr[i - 1];
    }
    for (int j = 0; j < T; j++){
        cin >> N;
        cout << arr[N] << '\n';
    }
}