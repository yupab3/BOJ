#include <iostream>
#include <algorithm>

using namespace std;

// 최대 P개를 담을 수 있고, Q 그램까지 담을 수 있다
int t, n, p, q;
int eggs[32];

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> t;
    int cases = 1;
    while (cases <= t) {
        cin >> n >> p >> q;
        for (int i = 1; i <= n; ++i)
            cin >> eggs[i];
        sort(eggs + 1, eggs + n + 1);
        int curGrams = 0, cnt = 0;
        for (int i = 1; i <= n; ++i) {
            if (cnt == p) break ;
            if (curGrams + eggs[i] > q) break ;
            curGrams += eggs[i];
            ++cnt;
        }
        cout << "Case " << cases << ": " << cnt << '\n';
        ++cases;
    }
    return 0;
}