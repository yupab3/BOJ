#include <iostream>

using namespace std;

// 시작 끝만 저장
// 시작 만나면 값 연산단위 추가 끝 만나면 감소
// 0부터 100만까지 스위핑

int st[1000002];
int en[1000002];

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    int a, b;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        ++st[a];
        ++en[b];
    }
    int l = 0, r = 0, score = 0, cl = 0, cr = 0;
    while (r <= 1000000) {
        if (score == k) break ;
        if (score < k) {
            cr += st[r];
            cr -= en[r];
            ++r;
            score += cr;
        }
        if (score > k) {
            cl += st[l];
            cl -= en[l];
            ++l;
            score -= cl;
        }
    }
    if (l == 0 && r == 1000001) cout << "0 0\n";
    else cout << l << ' ' << r << '\n';
    return 0;
}