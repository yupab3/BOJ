#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, k;
int seg[65536 * 4 + 2];
queue<int> q;

int getCenter(int node, int st, int en, int trgt) {
    if (st == en) return st;
    int mid = (st + en) / 2;
    if (seg[node * 2] >= trgt)
        return getCenter(node * 2, st, mid, trgt);
    else
        return getCenter(node * 2 + 1, mid + 1, en, trgt - seg[node * 2]);
}

int updateTree(int node, int st, int en, int idx, int diff) {
    if (idx < st || en < idx) return seg[node];
    if (st == idx && en == idx) return seg[node] += diff;

    int mid = (st + en) / 2;
    int lRes = updateTree(node * 2, st, mid, idx, diff);
    int rRes = updateTree(node * 2 + 1, mid + 1, en, idx, diff);
    seg[node] = lRes + rRes;
    return seg[node];
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> n >> k;
    long cur, ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> cur;
        q.push(cur);
        if (i < k)
            updateTree(1, 0, 65536, cur, 1);
        else {
            updateTree(1, 0, 65536, cur, 1);
            ans += getCenter(1, 0, 65536, (k + 1) / 2);
            updateTree(1, 0, 65536, q.front(), -1);
            q.pop();
        }
    }
    cout << ans << '\n';
}