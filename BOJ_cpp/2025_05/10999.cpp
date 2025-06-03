#include <iostream>

int     n, m, k;
long    var[1000002];
long    seg[4000002];
long    chg[4000002];

using namespace std;

void apply(int node, int st, int en) {
    if (!chg[node]) return ;
    seg[node] += (en - st + 1) * chg[node];
    if (st != en) {
        chg[node * 2] += chg[node];
        chg[node * 2 + 1] += chg[node];
    }
    chg[node] = 0;
}

void updateTree(int node, int st, int en, int left, int right, long diff) {
    apply(node, st, en);
    if (en < left || right < st) return ;
    if (left <= st && en <= right) {
        chg[node] += diff;
        apply(node, st, en);
        return ;
    }

    int mid = (st + en) / 2;
    updateTree(node * 2, st, mid, left, right, diff);
    updateTree(node * 2 + 1, mid + 1, en, left, right, diff);
    seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

long getSum(int node, int st, int en, int left, int right) {
    apply(node, st, en);
    if (en < left || right < st) return 0;
    if (left <= st && en <= right) return seg[node];

    int mid = (st + en) / 2;
    long lRes = getSum(node * 2, st, mid, left, right);
    long rRes = getSum(node * 2 + 1, mid + 1, en, left, right);
    return lRes + rRes;
}

long makeTree(int node, int st, int en) {
    if (st == en) return seg[node] = var[st];

    int mid = (st + en) / 2;
    long lRes = makeTree(node * 2, st, mid);
    long rRes = makeTree(node * 2 + 1, mid + 1, en);
    return seg[node] = lRes + rRes;
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> n >> m >> k;
    long a, b, c, d;
    for (int i = 1; i <= n; i++)
        cin >> var[i];
    makeTree(1, 1, n);
    for (int i = 1; i <= m + k; i++) {
        cin >> a;
        if (a == 1) {
            cin >> b >> c >> d;
            updateTree(1, 1, n, b, c, d);
        }
        else {
            cin >> b >> c;
            cout << getSum(1, 1, n, b, c) << '\n';
        }
    }
}