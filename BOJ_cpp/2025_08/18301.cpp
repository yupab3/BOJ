#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int a, b, c;
    cin >> a >> b >> c;
    cout << (a + 1) * (b + 1) / (c + 1) - 1 << '\n';
    return 0;
}