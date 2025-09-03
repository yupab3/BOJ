#include <iostream>
#include <algorithm>
#include <tuple>

using namespace std;

int n, q;
int parent[100002];
vector<tuple<int, int, int>> poles;

int findUnion(int u) {
    if (u == parent[u]) return u;
    return parent[u] = findUnion(parent[u]);
}

void mergeUnion(int uu, int vv) {
    auto &[ux1, ux2, unum] = poles[uu];
    auto &[vx1, vx2, vnum] = poles[vv];
    int u = findUnion(unum);
    int v = findUnion(vnum);
    if (vx1 > ux2) return ;
    vx2 = max(ux2, vx2);
    parent[u] = v;
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int x1, x2, y;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> x1 >> x2 >> y;
        parent[i] = i;
        poles.push_back({x1, x2, i});
    }
    sort(poles.begin(), poles.end());
    for (int i = 0; i < n - 1; ++i)
        mergeUnion(i, i + 1);
    for (int i = 1; i <= q; ++i) {
        cin >> x1 >> x2;
        if (findUnion(x1) == findUnion(x2)) cout << "1\n";
        else cout << "0\n";
    }
    return 0;
}