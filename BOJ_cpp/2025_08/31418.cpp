#include <iostream>
#include <algorithm>

using namespace std;

long w, h, k, t;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> w >> h >> k >> t;
    long x, y, x1, x2, y1, y2;
    long ans = 1;
    for (int i = 1; i <= k; ++i) {
        cin >> x >> y;
        x1 = max(1L, x - t);
        x2 = min(w, x + t);
        y1 = max(1L, y - t);
        y2 = min(h, y + t);
        ans = (x2 - x1 + 1) * (y2 - y1 + 1) % 998244353 * ans % 998244353;
    }
    cout << ans << '\n';
    return 0;
}