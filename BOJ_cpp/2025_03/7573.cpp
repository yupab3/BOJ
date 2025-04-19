#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, l;
vector<pair<int, int>> fishes;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    cin >> n >> l >> m;
    int x, y;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        fishes.push_back({x, y});
    }
    sort(fishes.begin(), fishes.end());
    int ans = 0;
    for (auto cur = fishes.begin(); cur != fishes.end(); cur++) {
        int cx = cur->first;
        int cy = cur->second;
        // cout << "cur: " << cx << ", " << cy << '\n';
        for (int lx = 2; lx <= l - 2; lx += 2) {
            int ly = l - lx;
            // cout << "l: " << lx << ", " << ly << '\n';
            for (int sx = cx - lx / 2; sx < cx + lx; sx++) {
                if (sx < 1 || n < sx) continue ;
                int ex = sx + lx / 2;
                if (ex < 1 || n < ex) continue ;
                if (cx < sx || ex < cx) continue ;
                // cout << "------ sx : " << sx << ", ex : " << ex << "------" << '\n';
                for (int sy = cy - ly / 2; sy < cy + ly; sy++) {
                    if (sy < 1 || n < sy) continue ;
                    int ey = sy + ly / 2;
                    if (ey < 1 || n < ey) continue ;
                    if (cy < sy || ey < cy) continue ;
                    // cout << "sy : " << sy << ", ey : " << ey << '\n';
                    int score = 0;
                    for (auto next = cur; next != fishes.end(); next++) {
                        if (next->first < sx || ex < next->first) continue ;
                        if (next->second < sy || ey < next->second) continue ;
                        score++;
                    }
                    ans = max(ans, score);
                }
            }
        }
    }
    cout << ans << '\n';
}
