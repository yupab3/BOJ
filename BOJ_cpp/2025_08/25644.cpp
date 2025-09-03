#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, minV = 1e9 + 2, maxV = 0, cur, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> cur;
        if (cur < minV) {
            if (minV != 1e9 + 2) ans = max(ans, maxV - minV);
            minV = cur;
            maxV = cur;
        }
        else if (maxV < cur) maxV = cur;
    }
    ans = max(ans, maxV - minV);
    cout << ans << '\n';
    return 0;
}