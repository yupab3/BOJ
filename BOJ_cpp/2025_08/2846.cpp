#include <iostream>

using namespace std;

int n;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> n;
    int min = 0, bf = 0, cur, ans = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> cur;
        if (bf >= cur) {
            ans = max(ans, bf - min);
            min = cur;
        }
        if (min == 0) min = cur;
        bf = cur;
    }
    ans = max(ans, bf - min);
    cout << ans << '\n';
    return 0;
}