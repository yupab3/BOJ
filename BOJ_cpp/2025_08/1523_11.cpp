#include <iostream>
#include <set>

using namespace std;

int     cnt[10002];
set<int> nums;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    int cur;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> cur;
            nums.insert(cur);
            ++cnt[cur];
        }
    }
    int odd = 0;
    for (int trgt : nums) {
        if (cnt[trgt] % 2) ++odd;
        // cout << "trgt : " << trgt << ", cnt[trgt] : " << cnt[trgt] << '\n';
    }
    if (m % 2 && abs(odd - n) % 2 == 0 && odd <= n) cout << "YES\n";
    else if (m % 2 == 0 && odd == 0) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}