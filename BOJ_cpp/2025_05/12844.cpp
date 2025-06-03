#include <iostream>

using namespace std;

int n, m;
int var[500002];
int seg[2000002];
int chg[2000002];

// 0 ^ X = X
// X ^ B ^ C == (X ^ B) ^ C == X ^ (B ^ C)
// B ^ C = C ^ B
// X ^ B ^ X ^ C == X ^ X ^ B ^ C == 0 ^ B ^ C
// 홀수 개의 범위면 Xor, 짝수 개의 범위면 그대로

void apply(int node, int st, int en) {
    if (!chg[node]) return ;
    if (st != en) {
        chg[node * 2] = chg[node * 2] ^ chg[node];
        chg[node * 2 + 1] = chg[node * 2 + 1] ^ chg[node];
    }
    if ((en - st + 1) & 1) seg[node] = seg[node] ^ chg[node];
    chg[node] = 0;
}

void updateTree(int node, int st, int en, int left, int right, int k) {
    apply(node, st, en);
    if (en < left || right < st) return ;
    if (left <= st && en <= right) {
        chg[node] = chg[node] ^ k;
        apply(node, st, en);
        return ;
    }
    int mid = (st + en) / 2;
    updateTree(node * 2, st, mid, left, right, k);
    updateTree(node * 2 + 1, mid + 1, en, left, right, k);
    seg[node] = seg[node * 2] ^ seg[node * 2 + 1];
}

int getAns(int node, int st, int en, int left, int right) {
    apply(node, st, en);
    if (en < left || right < st) return 0;
    if (left <= st && en <= right) return seg[node];

    int mid = (st + en) / 2;
    int lRes = getAns(node * 2, st, mid, left, right);
    int rRes = getAns(node * 2 + 1, mid + 1, en, left, right);
    return lRes ^ rRes;
}

int makeTree(int node, int st, int en) {
    if (st == en) return seg[node] = var[st];

    int mid = (st + en) / 2;
    int lRes = makeTree(node * 2, st, mid);
    int rRes = makeTree(node * 2 + 1, mid + 1, en);
    return seg[node] = lRes ^ rRes;
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> var[i - 1];
    makeTree(1, 0, n - 1);
    cin >> m;
    int query;
    int a, b, c;
    for (int i = 1; i <= m; i++) {
        cin >> query;
        if (query == 1) {
            cin >> a >> b >> c;
            updateTree(1, 0, n - 1, a, b, c);
        }
        else {
            cin >> a >> b;
            cout << getAns(1, 0, n - 1, a, b) << '\n';
        }
    }
}