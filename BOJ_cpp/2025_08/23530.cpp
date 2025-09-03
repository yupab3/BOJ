#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t, a, b;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        int sum = a + b;
        int c;
        for (int i = 1; i <= 50; ++i) {
            if (i != a + b) {
                c = i;
                break ;
            }
        }
        cout << c << '\n';
    }
    return 0;
}