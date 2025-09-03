#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, d, p, v;
vector<pair<long, long>>    gift;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> n >> d;
    long    ans = 0, cur = 0;
    int     idx = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> p >> v;
        gift.push_back({p, v});
    }
    sort(gift.begin(), gift.end(), [](pair<int, int> a, pair<int, int> b){ return a.first < b.first; });
    for (auto [cp, cv] : gift) {
        cur += cv;
        while (abs(gift[idx].first - cp) >= d) {
            cur -= gift[idx].second;
            ++idx;
        }
        ans = max(cur, ans);
    }
    cout << ans << '\n';
}