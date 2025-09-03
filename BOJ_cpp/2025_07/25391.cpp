#include <iostream>
#include <algorithm>

using namespace std;

int n, m, k;
pair<long, long> b[200002];
long a[200002];
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i].first;
        b[i].second = i;
    }
    sort(b, b + n, greater<pair<long, long>>());
    long ans = 0;
    for (int i = 0; i < k; ++i) {
        ans += a[b[i].second];
        a[b[i].second] = 0;
    }
    sort(a, a + n, greater<long>());
    for (int i = 0; i < m; ++i)
        ans += a[i];
    cout << ans << '\n';
}