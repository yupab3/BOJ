#include <iostream>
using namespace std;

int arr[1000002];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;

    arr[1] = 0;
    cin >> N;
    for (int i = 2; i <= N; i++){
        arr[i] = arr[i - 1] + 1;
        if (i % 2 == 0) arr[i] = min(arr[i], arr[i / 2] + 1);
        if (i % 3 == 0) arr[i] = min(arr[i], arr[i / 3] + 1);
    }
    cout << arr[N];
}