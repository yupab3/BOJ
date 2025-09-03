#include <iostream>

using namespace std;

// 고기 한 덩이당 85개의 꼬치 생산 가능
// 1키로 마리네이트 하는데 8RM 비용 추가

double chicken, beef, lamb, nasi;
double benefit[4] = {0.80 - 15.50 / 85, 1.00 - 32.00 / 85, 1.20 - 40.00 / 85, 0.60};

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, cnt = 0;
    while (1) {
        cin >> n;
        if (n == 0) break ;
        double ans = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> chicken >> beef >> lamb >> nasi;
            ans += chicken * benefit[0] + beef * benefit[1] + lamb * benefit[2] + nasi * benefit[3];
        }
        cout << fixed;
        cout.precision(2);
        cout << "Case #" << ++cnt << ": RM" << ans << '\n';
    }
}