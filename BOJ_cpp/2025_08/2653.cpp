#include <iostream>

using namespace std;

// 좋아하는 애들끼리 묶은 뒤 한 덩이인지 확인, 유니온 파인드!
int n;
int cnt[102];
int parent[102];

int findUnion(int u) {
    if (u == parent[u]) return u;
    return parent[u] = findUnion(parent[u]);
}

void    mergeUnion(int uu, int vv) {
    int u = findUnion(uu);
    int v = findUnion(vv);

    if (u < v) parent[v] = u;
    else parent[u] = v;
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> n;
    bool hate = false;
    for (int i = 1; i <= n; ++i)
        parent[i] = i;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> hate;
            if (hate) continue ;
            mergeUnion(i, j);
        }
    }
    for (int i = 1; i <= n; ++i)
        ++cnt[findUnion(i)];
    int groupCnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (cnt[i] == 1) {
            cout << 0 << '\n';
            return 0;
        }
        else if (cnt[i] > 0) ++groupCnt;
    }
    cout << groupCnt << '\n';
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == findUnion(j)) cout << j << ' ';
        }
        if (cnt[i]) cout << '\n';
    }
    return 0;
}