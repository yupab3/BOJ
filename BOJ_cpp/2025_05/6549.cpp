#include <iostream>
#include <algorithm>

using namespace std;

long    seg[400008];
long    var[100002];
int     n;

long    getMin(int node, int st, int en, int left, int right) {
    if (right < st || en < left) return 1e17;
    if (left <= st && en <= right) return seg[node];

    int mid = (st + en) / 2;
    long lRes = getMin(node * 2, st, mid, left, right);
    long rRes = getMin(node * 2 + 1, mid + 1, en, left, right);
    if (lRes == 1e17) return rRes;
    if (rRes == 1e17) return lRes;
    if (var[lRes] > var[rRes]) return rRes;
    else return lRes;
}

long    dnc(int st, int en) {
    if (en <= st) return var[st];

    long mid = getMin(1, 1, n, st, en);
    long cur = (en - st + 1) * var[mid];
    long lRes = dnc(st, mid - 1);
    long rRes;
    if (mid + 1 < n) rRes = dnc(mid + 1, en);
    else rRes = dnc(n, en);
    return max(cur, max(lRes, rRes));
}

long    makeTree(int node, int st, int en) {
    if (st == en) return seg[node] = st;

    int mid = (st + en) / 2;
    int lRes = makeTree(node * 2, st, mid);
    int rRes = makeTree(node * 2 + 1, mid + 1, en);
    if (var[lRes] > var[rRes]) seg[node] = rRes;
    else seg[node] = lRes;
    return seg[node];
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (1) {
        cin >> n;
        if (n == 0) return 0;
        for (int i = 1; i <= n; i++) 
            cin >> var[i];
        makeTree(1, 1, n);
        cout << dnc(1, n) << '\n';
    }
    return 0;
}