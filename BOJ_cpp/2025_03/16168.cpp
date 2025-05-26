#include <iostream>
#include <vector>

using namespace std;

int v, e;
int parent[3002];
vector<int> nodes[3002];

int findUnion(int u) {
    if (u == parent[u]) return u;
    return parent[u] = findUnion(parent[u]);
}

void    mergeUnion(int u, int v) {
    u = findUnion(u);
    v = findUnion(v);
    if (u <= v) parent[v] = u;
    else parent[u] = v;
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    cin >> v >> e;
    int st, en;
    for (int i = 1; i <= e; i++) {
        cin >> st >> en;
        nodes[st].push_back(en);
        nodes[en].push_back(st);
    }
    for (int i = 1; i <= v; i++)
        parent[i] = i;
    for (int i = 1; i <= v; i++) {
        for (int next : nodes[i]) {
            mergeUnion(i, next);
        }
    }
    int cirNo = findUnion(1);
    for (int i = 2; i <= v; i++) {
        if (findUnion(i) != cirNo) {
            cout << "NO\n";
            return 0;
        }
    }
    int cnt = 0;
    for (int i = 1; i <= v; i++) {
        if (nodes[i].size() % 2) cnt++;
    }
    if (cnt > 2) cout << "NO\n";
    else cout << "YES\n";
}