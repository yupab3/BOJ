#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 유니온 파인드

int n, m, c, h, k;
int ali[100002];
int parent[100002];
vector<int> score;

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

    cin >> n >> m;
    int x, y;
    for (int i = 1; i <= n; ++i)
        parent[i] = i;
    for (int i = 1; i <= m; ++i) {
        cin >> x >> y;
        mergeUnion(x, y);
    }
    cin >> c >> h >> k;
    h = findUnion(h);
    c = findUnion(c);
    for (int i = 1; i <= n; ++i) {
        if (findUnion(i) == h) continue ;
        ++ali[findUnion(i)];
    }
    for (int i = 1; i <= n; ++i) {
        if (ali[i]) score.push_back(ali[i]);
    }
    sort(score.begin(), score.end(), greater<int>());
    int idx = 0, ans = 0;
    while (k) {
        if (idx != c) {
            ans += score[idx];
            --k;
        }
        ++idx;
    }
    cout << ans + ali[c] << '\n';
}