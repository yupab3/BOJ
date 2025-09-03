#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string a, b;
    cin >> a >> b;
    int cases = 1;
    for (int i = 0; i < 4; ++i)
        if (a[i] != b[i]) cases *= 2;
    cout << cases << '\n';
    return 0;
}