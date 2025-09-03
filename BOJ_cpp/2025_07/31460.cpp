#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t, n;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cin >> n;
        if (n == 1) {
            cout << "0\n";
            continue ;
        }
        cout << '1';
        for (int i = 1; i < n - 1; ++i)
            cout << '2';
        cout << "1\n";
    }
    return 0;
}
