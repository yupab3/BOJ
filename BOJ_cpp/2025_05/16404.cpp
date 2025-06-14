#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int>    nodes[100002];
long    seg[400002];
long    chg[400002];
int s[100002];
int e[100002];
int idx = 0;

void setIdx(int num) {
    s[num] = ++idx;
    for (int next : nodes[num])
        setIdx(next);
    e[num] = idx;
}

void    apply(int node, int st, int en) {
    if (!chg[node]) return ;

    seg[node] += chg[node];
    if (st != en) {
        chg[node * 2] += chg[node];
        chg[node * 2 + 1] += chg[node];
    }
    chg[node] = 0;
}

void    updateTree(int node, int st, int en, int left, int right, int diff) {
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
}

long    getAns(int node, int st, int en, int trgt) {
    apply(node, st, en);
    if (en < trgt || trgt < st) return 0;
    if (st == en) return seg[node];

    int mid = (st + en) / 2;
    long lRes = getAns(node * 2, st, mid, trgt);
    long rRes = getAns(node * 2 + 1, mid + 1, en, trgt);
    return lRes + rRes;
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> n >> m;
    int firm;
    cin >> firm;
    for (int i = 2; i <= n; ++i) {
        cin >> firm;
        nodes[firm].push_back(i);
    }
    setIdx(1);
    long cmd, i, w;
    while (m--) {
        cin >> cmd;
        if (cmd == 1) {
            cin >> i >> w;
            updateTree(1, 1, n, s[i], e[i], w);
        }
        else {
            cin >> i;
            cout << getAns(1, 1, n, s[i]) << '\n';
        }
    }
}