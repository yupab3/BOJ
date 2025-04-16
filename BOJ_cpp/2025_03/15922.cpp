#include <iostream>

using namespace std;

int n;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    cin >> n;
    int x, y;
    int s = 1e9 + 2, e = -1e9 - 2;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y;
        if (e != - 1e9 - 2 && e < x) {
            ans += e - s;
            s = x;
        }
        if (x < s) s = x;
        if (e < y) e = y;
    }
    ans += e - s;
    cout << ans << '\n';
}