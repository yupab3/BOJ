#include <iostream>

using namespace std;

int n;
int inputNum[1000002];
long bitbox[22];

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> inputNum[i];
        int cnt = 1;
        int div = 1;
        while (div <= inputNum[i]) {
            if (inputNum[i] & div) ++bitbox[cnt];
            div *= 2;
            ++cnt;
        }
    }
    long    ans = 0;
    for (int i = 1; i <= n; i++) {
        int cnt = 1;
        long div = 1;
        while (cnt < 21) {
            if ((inputNum[i] & div) == 0) ans += bitbox[cnt] * div;
            div *= 2;
            ++cnt;
        }
    }
    cout << ans << '\n';
}