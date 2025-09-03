#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, t = 1;
    while (1) {
        cin >> n;
        if (n == 0) break;
        n *= 3;
        int odd = n % 2;
        if (odd) {
            n = (n + 1) / 2;
            cout << t << ". odd ";
        }
        else {
            n /= 2;
            cout << t << ". even ";
        }
        n *= 3;
        n /= 9;
        cout << n << '\n';
        ++t;
    }
    return 0;
}