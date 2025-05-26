#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define STR 0
#define DEX 1
#define INT 2

int stat[3][102];

int n, k;
int ans = 40000000;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int st, de, in;
        cin >> st >> de >> in;
        stat[0][i] = st;
        stat[1][i] = de;
        stat[2][i] = in;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int v = 1; v <= n; v++) {
                int cnt = 0;
                for (int m = 1; m <= n; m++) {
                    if (stat[0][i] >= stat[0][m] && stat[1][j] >= stat[1][m] && stat[2][v] >= stat[2][m]) {
                        cnt++;
                    }
                }
                if (cnt >= k) {
                    ans = min(ans, stat[0][i] + stat[1][j] + stat[2][v]);
                }
            }
        }
    }
    cout << ans << endl;
}