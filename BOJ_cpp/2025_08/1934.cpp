#include <iostream>

using namespace std;

int getGYS(int a, int b) {
    if (a % b == 0) return b;
    return getGYS(b, a % b);
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t, a, b;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        cout << a * b / getGYS(a, b) << '\n';
    }
    return 0;
}