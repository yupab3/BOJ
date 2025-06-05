#include <iostream>

using namespace std;

int     n, q;
long    var[100002];
long    seg[400002];
long    chg[400002][2]; // 0번 초기항, 1번 등차

//초기항 : a, 등차 : b, 구간 : r = (en - st)
//좌측 항에는 초기항의 구간합을 그대로 보내면 된다.
//우측 항에는 초기항의 구간합을 현재 초기항의 구간합 + 인덱스 차이 * 최종 등차만큼 곱해서 보내줘야 한다.
//등차는 좌측 우측 모두 그대로 전달한다.
//나머진 일반 레이지 세그먼트 트리.

void    apply(int node, int st, int en, int mid) {
    if (!chg[node][0]) return ;
    seg[node] += chg[node][0] * (en - st + 1) + (en - st) * (en - st + 1) * chg[node][1] / 2;
    if (st != en) {
        chg[node * 2][0] += chg[node][0];
        chg[node * 2][1] += chg[node][1];
        chg[node * 2 + 1][0] += chg[node][0] + (mid - st + 1) * chg[node][1];
        chg[node * 2 + 1][1] += chg[node][1];
    }
    chg[node][0] = 0;
    chg[node][1] = 0;
}

void    updateTree(int node, int st, int en, int left, int right, int diff) {
    int mid = (st + en) / 2;
    apply(node, st, en, mid);
    if (en < left || right < st) return ;
    if (left <= st && en <= right) {
        if (diff < 1) return ;
        chg[node][0] += diff;
        chg[node][1] += 1;
        apply(node, st, en, mid);
        return ;
    }
    
    updateTree(node * 2, st, mid, left, right, diff);
    updateTree(node * 2 + 1, mid + 1, en, left, right, diff + mid - st + 1);
    seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

long    getAns(int node, int st, int en, int x) {
    int mid = (st + en) / 2;
    apply(node, st, en, mid);
    if (en < x || x < st) return 0;
    if (st == en) return seg[node];
    
    long lRes = getAns(node * 2, st, mid, x);
    long rRes = getAns(node * 2 + 1, mid + 1, en, x);
    return lRes + rRes;
}

long makeTree(int node, int st, int en) {
    if (st == en) return seg[node] = var[st];

    int mid = (st + en) / 2;
    long lRes = makeTree(node * 2, st, mid);
    long rRes = makeTree(node * 2 + 1, mid + 1, en);
    return seg[node] = lRes + rRes;
}

int     main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> var[i];
    makeTree(1, 1, n);
    cin >> q;
    int query, l, r, x;
    for (int i = 1; i <= q; i++) {
        cin >> query;
        if (query == 1) {
            cin >> l >> r;
            updateTree(1, 1, n, l, r, 2 - l);
        }
        else {
            cin >> x;
            cout << getAns(1, 1, n, x) << '\n';
        }
    }
}