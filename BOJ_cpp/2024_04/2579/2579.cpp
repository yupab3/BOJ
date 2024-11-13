#include <iostream>
using namespace std;

int arr[302];

int main(void){
    int N, S, total;

    cin >> N;
    total = 0;
    for (int i = 1; i <= N; i++){
            cin >> S;
            arr[i] = S;
            total += S;
    }
    if (N <= 2)
    {
        cout << total;
        return 0;
    }
    for (int i = 4; i <= N - 1; i++){
        arr[i] = min(arr[i - 2], arr[i - 3]) + arr[i];
    }
    cout << total - min(arr[N - 1], arr[N - 2]);
}