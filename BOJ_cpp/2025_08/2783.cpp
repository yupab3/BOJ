#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    double gram7, cost7;
    cin >> cost7 >> gram7;
    int n;
    double ans = 1000 / gram7 * cost7;
    double gram, cost;
    cin >> n;
    cout.precision(2);
    cout << fixed;
    for (int i = 1; i <= n; ++i) {
        cin >> cost >> gram;
        ans = min(ans, 1000 / gram * cost);
    }
    cout << ans << '\n';
    return 0;
}