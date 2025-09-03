#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, r, c;
    cin >> n >> r >> c;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if ((r + c) % 2 == (i + j) % 2) cout << 'v';
            else cout << '.';
        }
        cout << '\n';
    }
    return 0;
}