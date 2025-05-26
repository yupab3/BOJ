#include <iostream>

using namespace std;

long val[1000002];
long segTree[4000008];
long n, m, k;

void updateTree(int node, int st, int en, int idx, long diff) {
    if (idx < st || en < idx) return ;
    segTree[node] += diff;

    if (st == en) return ;
    int mid = (st + en) / 2;
    updateTree(node * 2, st, mid, idx, diff);
    updateTree(node * 2 + 1, mid + 1, en, idx, diff);
}

long getSum(int node, int st, int en, int left, int right) {
    if (right < st || en < left) return 0;
    if (left <= st && en <= right) return segTree[node];

    int mid = (st + en) / 2;
    long lRes = getSum(node * 2, st, mid, left, right);
    long rRes = getSum(node * 2 + 1, mid + 1, en, left, right);
    return lRes + rRes;
}

long makeTree(int node, int st, int en) {
    if (st == en) return segTree[node] = val[st];

    int mid = (st + en) / 2;
    long lRes = makeTree(node * 2, st, mid);
    long rRes = makeTree(node * 2 + 1, mid + 1, en);
    segTree[node] = lRes + rRes;

    return segTree[node];
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        cin >> val[i];
    makeTree(1, 1, n);
    int a, b;
    long c;
    for (int i = 1; i <= m + k; i++) {
        // cout << "m : " << m << ", k : " << k << ", i : " << i << '\n';
        cin >> a >> b >> c;
        if (a == 1) {
            updateTree(1, 1, n, b, c - val[b]);
            val[b] = c;
        }
        else
            cout << getSum(1, 1, n, b, c) << '\n';
    }
}