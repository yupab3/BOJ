#include <iostream>
#include <vector>

using namespace std;

int n, m;
long    in[100002];
long    out[100002];
long    seg[400002];
vector<int> nodes[100002];
int idx;

void    setIdx(int i) {
    in[i] = ++idx;
    for (int next : nodes[i])
        setIdx(next);
    out[i] = idx;
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

    cin >> n >> m;
    int firm;
    cin >> firm;
    for (int i = 2; i <= n; i++) {
        cin >> firm;
        nodes[firm].push_back(i);
    }
    setIdx(1);
    int query, a, b;
    for (int i = 1; i <= m; i++) {
        cin >> query >> a;
        if (query == 1) {
            cin >> b;
            updateTree(1, 1, n, in[a], in[a], b);
        }
        else cout << getAns(1, 1, n, in[a], out[a]) << '\n';
    }
}