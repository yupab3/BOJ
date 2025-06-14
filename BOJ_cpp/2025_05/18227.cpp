#include <iostream>
#include <vector>

using namespace std;

int n, c, q;
int in[200002];
int out[200002];
long    mul[200002];
long    seg[800002];
bool    vis[200002];
vector<int> nodes[200002];
int idx;
int depth;

void    setIdx(int i) {
    vis[i] = true;
    in[i] = ++idx;
    mul[i] = ++depth;
    for (int next : nodes[i]) {
        if (vis[next]) continue ;
        setIdx(next);
    }
    out[i] = idx;
    --depth;
}

long    updateTree(int node, int st, int en, int left, int right, int diff) {
    if (en < left || right < st) return seg[node];
    if (left <= st && en <= right) return seg[node] += diff;

    int mid = (st + en) / 2;
    long lRes = updateTree(node * 2, st, mid, left, right, diff);
    long rRes = updateTree(node * 2 + 1, mid + 1, en, left, right, diff);
    return seg[node] = lRes + rRes;
}

long    getAns(int node, int st, int en, int left, int right) {
    if (en < left || right < st) return 0;
    if (left <= st && en <= right) return seg[node];

    int mid = (st + en) / 2;
    long lRes = getAns(node * 2, st, mid, left, right);
    long rRes = getAns(node * 2 + 1, mid + 1, en, left, right);
    return lRes + rRes;
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> n >> c;
    int st, en;
    for (int i = 1; i < n; i++) {
        cin >> st >> en;
        nodes[st].push_back(en);
        nodes[en].push_back(st);
    }
    setIdx(c);
    cin >> q;
    int query, a;
    for (int i = 1; i <= q; i++) {
        cin >> query >> a;
        if (query == 1) {
            updateTree(1, 1, n, in[a], in[a], 1);
        }
        else {
            cout << getAns(1, 1, n, in[a], out[a]) * mul[a] << '\n';
        }
    }
}