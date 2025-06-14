#include <iostream>
#include <vector>

using namespace std;

int n, m;
int in[100002];
int out[100002];
int chg[400002];
int seg[2][400002];
vector<int> nodes[100002];
int idx;

// 부하 -> 상사 일반 구간합 세그먼트 트리 togle = 0
// 상사 -> 부하 레이지 세그먼트 트리 togle = 1

void    setIdx(int i) {
    in[i] = ++idx;
    for (int next : nodes[i])
        setIdx(next);
    out[i] = idx;
}

void    apply(int node, int st, int en) {
    if (!chg[node]) return ;

    seg[1][node] += chg[node];
    if (st != en) {
        chg[node * 2] += chg[node];
        chg[node * 2 + 1] += chg[node];
    }
    chg[node] = 0;
}

long    updateTree(int node, int st, int en, int left, int right, int diff, int togle) {
    if (togle) apply(node, st, en);
    if (en < left || right < st) return seg[togle][node];
    if (left <= st && en <= right) {
        if (togle) {
            chg[node] += diff;
            apply(node, st, en);
            return 0;
        }
        return seg[togle][node] += diff;
    }

    int mid = (st + en) / 2;
    long lRes = updateTree(node * 2, st, mid, left, right, diff, togle);
    long rRes = updateTree(node * 2 + 1, mid + 1, en, left, right, diff, togle);
    if (togle) return 0;
    return seg[togle][node] = lRes + rRes;
}

long    getAns(int node, int st, int en, int left, int right, int togle) {
    if (togle) apply(node, st, en);
    if (en < left || right < st) return 0;
    if (left <= st && en <= right) return seg[togle][node];

    int mid = (st + en) / 2;
    long lRes = getAns(node * 2, st, mid, left, right, togle);
    long rRes = getAns(node * 2 + 1, mid + 1, en, left, right, togle);
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
    int query, a, b, togle = 1;
    for (int i = 1; i <= m; i++) {
        cin >> query;
        if (query == 1) {
            cin >> a >> b;
            if (togle) updateTree(1, 1, n, in[a], out[a], b, togle);
            else updateTree(1, 1, n, in[a], in[a], b, togle);
        }
        else if (query == 2) {
            cin >> a;
            cout << getAns(1, 1, n, in[a], in[a], 1) + getAns(1, 1, n, in[a], out[a], 0) << '\n';
        }
        else togle ^= 1;
    }
}