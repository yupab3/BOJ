#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int t, r, c, ans;
int parent[250002];
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

int     findUnion(int u) {
    if (u == parent[u]) return u;
    return parent[u] = findUnion(parent[u]);
}

void    mergeUnion(int uu, int vv) {
    int u = findUnion(uu);
    int v = findUnion(vv);

    if (u < v) parent[v] = u;
    else parent[u] = v;
}

void    Kruskal() {
    while (pq.size()) {
        auto [cost, u, v] = pq.top();
        // cout << "[" << cost << ", " << u << ", " << v << "]\n";
        pq.pop();
        // cout << "findUnion(" << u << ") : " << findUnion(u) << ", findUnion(" << v << ") : " << findUnion(v) << '\n';
        if (findUnion(u) == findUnion(v)) continue ;
        // cout << u << " - " << v << " is merged\n";
        mergeUnion(u, v);
        ans += cost;
    }
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> t;
    for (int i = 1; i <= t; ++i) {
        ans = 0;
        cin >> r >> c;
        for (int j = 1; j <= r * c; ++j)
            parent[j] = j;
        int cost;
        for (int j = 1; j <= r; ++j) {
            for (int k = 1; k < c; ++k) {
                cin >> cost;
                pq.push({cost, (j - 1) * c + k, (j - 1) * c + k + 1});
            }
        }
        for (int j = 1; j < r; ++j) {
            for (int k = 1; k <= c; ++k) {
                cin >> cost;
                pq.push({cost, (j - 1) * c + k, j * c + k});
            }
        }
        Kruskal();
        cout << ans << '\n';
    }
}