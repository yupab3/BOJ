#include <iostream>

using namespace std;

int n, m;
int num[2002];
int ans[2002][2002];

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> num[i];
    for (int i = 1; i <= n; ++i) {
        ans[i][i] = 1;
        int st = i - 1;
        int en = i + 1;
        while (st > 0 && en <= n && num[st] == num[en]) {
            ans[st][en] = 1;
            --st;
            ++en;
        }
        if (num[i] == num[i + 1]) {
            ans[i][i + 1] = 1;
            st = i - 1;
            en = i + 2;
            while (st > 0 && en <= n && num[st] == num[en]) {
                ans[st][en] = 1;
                --st;
                ++en;
            }
        }
    }
    cin >> m;
    int s, e;
    for (int i = 1; i <= m; ++i) {
        cin >> s >> e;
        cout << ans[s][e] << '\n';
    }
    return 0;
}