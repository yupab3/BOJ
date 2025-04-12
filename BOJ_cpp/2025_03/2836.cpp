#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int n, m;
set<pair<int, int>> P;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int home, dest;
        cin >> home >> dest;
        if (home > dest) P.insert({dest, home});
    }
    int cur_p = 0;
    long ans = m;
    int home = 0, dest = 1e9 + 2;
    for (auto cur : P) { // p2 dest < p1 home -> p2 home
        // cout << "dest : " << cur.first << ", home : " << cur.second << '\n';
        if (home < cur.first) {
            cur_p = cur.first;
            if (dest != 1e9 + 2) ans += (home - dest) * 2;
            dest = cur.first;
            home = cur.second;
        }
        if (cur.first < dest) dest = cur.first;
        if (home < cur.second) home = cur.second; 
    }
    if (dest != 1e9 + 2) ans += (home - dest) * 2;
    cout << ans << '\n';
}

// home 보다 dest가 앞에 있는 노드를 기준으로 분기점 생성
// 스위핑
