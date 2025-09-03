#include <iostream>

using namespace std;

int dp[32][32];

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        long ans = 1;
        int st = 1;
        while (st <= n) {
            ans *= m - n + st;
            ans /= st;
            ++st;
        }
        cout << ans << '\n';
    }
    return 0;
}