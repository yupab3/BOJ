#include <iostream>

using namespace std;

// k : 테케 수, n : 광고 수, v : 방문자 수
// d_i : i번째 광고의 종류 - 1이면 노출 시 비용발생, 0이면 클릭 시 비용 발생
// p_i : i번째 광고에 대한 비용
// a_1, a_2 : 유저가 보는 2개의 광고 (1 <= a_1, a_2 <= n)
// c : 유저가 클릭한 광고 (0 = 클릭 안함, 1 = a_1, 2 = a_2)

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int k, n, v;
    cin >> k;
    int idx = 0;
    while (++idx <= k) {
        cin >> n >> v;
        int d[1002];
        int p[1002];
        for (int i = 1; i <= n; ++i)
            cin >> d[i] >> p[i];
        int a1, a2, c, ans = 0;
        for (int i = 1; i <= v; ++i) {
            cin >> a1 >> a2 >> c;
            d[a1] == 1 ? ans += p[a1] : (c == 1 ? ans += p[a1] : false);
            d[a2] == 1 ? ans += p[a2] : (c == 2 ? ans += p[a2] : false);
        }
        cout << "Data Set " << idx << ":\n" << ans << '\n';
        if (idx != k) cout << '\n'; 
    }
    return 0;
}