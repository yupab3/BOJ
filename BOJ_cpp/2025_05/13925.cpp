#include <iostream>
#include <algorithm>
#include <queue>

#define MOD 1000000007
using namespace std;

int var[100002];
long seg[400002];
long mul[400002];
long add[400002];
int n, m;

void apply(int node, long st, long en) {
    if (!add[node] && !mul[node]) return ;

    if (st != en) {
        if (!seg[node]) {
            seg[node * 2] = 0;
            mul[node * 2] = 1;
            add[node * 2] = 0;
            seg[node * 2 + 1] = 0;
            mul[node * 2 + 1] = 1;
            add[node * 2 + 1] = 0;
        }
        add[node * 2] = ((add[node * 2] * mul[node]) % MOD + add[node]) % MOD;
        add[node * 2 + 1] = ((add[node * 2 + 1] * mul[node]) % MOD + add[node]) % MOD;
        mul[node * 2] = mul[node * 2] * mul[node] % MOD;
        mul[node * 2 + 1] = mul[node * 2 + 1] * mul[node] % MOD;
    }
    seg[node] = ((mul[node] * seg[node]) % MOD + add[node] * (en - st + 1)) % MOD;
    // cout << "node : " << node << ", add[" << node << "] : " << add[node] << ", mul[" << node << "] : " << mul[node] << '\n';
    add[node] = 0;
    mul[node] = 1;
}

void    updateTree(int node, int st, int en, int left, int right, int mode, long diff) {
    apply(node, st, en);
    if (en < left || right < st) return ;
    if (left <= st && en <= right) {
        if (mode == 3) {
            seg[node] = 0;
            mul[node] = 1;
            add[node] = diff;
        }
        else if (mode == 2) {
            mul[node] = (mul[node] * diff) % MOD;
            add[node] = (add[node] * diff) % MOD;
        }
        else add[node] = (add[node] + diff) % MOD;
        apply(node, st, en);
        return ;
    }

    int     mid = (st + en) / 2;
    updateTree(node * 2, st, mid, left, right, mode, diff);
    updateTree(node * 2 + 1, mid + 1, en, left, right, mode, diff);
    seg[node] = (seg[node * 2] + seg[node * 2 + 1]) % MOD;
}

long    getAns(int node, int st, int en, int left, int right) {
    apply(node, st, en);
    if (en < left || right < st) return 0;
    if (left <= st && en <= right) return seg[node];

    int mid = (st + en) / 2;
    long    lRes = getAns(node * 2, st, mid, left, right);
    long    rRes = getAns(node * 2 + 1, mid + 1, en, left, right);
    return (lRes + rRes) % MOD;
}

void printTree() {
    cout << "------ seg ------\n";
    for (int i = 1; i <= 4 * n; i++) {
        cout << seg[i] << ' ';
    }
    cout << "\n------ mul ------ \n";
    for (int i = 1; i <= 4 * n; i++) {
        cout << mul[i] << ' ';
    }
    cout << "\n------ add ------ \n";
    for (int i = 1; i <= 4 * n; i++) {
        cout << add[i] << ' ';
    }
}

long makeTree(int node, int st, int en) {
    if (st == en) return seg[node] = var[st];

    int mid = (st + en) / 2;
    long    lRes = makeTree(node * 2, st, mid);
    long    rRes = makeTree(node * 2 + 1, mid + 1, en);
    return seg[node] = (lRes + rRes) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> var[i];
    cin >> m;
    fill(mul, mul + 400001, 1);
    makeTree(1, 1, n);
    int q, x, y, v;
    for (int i = 1; i <= m; i++) {
        cin >> q >> x >> y;
        if (q == 4)
            cout << getAns(1, 1, n, x, y) << '\n';
        else if (q == 5) printTree();
        else {
            cin >> v;
            updateTree(1, 1, n, x, y, q, v);
        }
    }
}