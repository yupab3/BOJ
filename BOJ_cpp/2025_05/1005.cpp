#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, k;
int d[1002];
int messi[1002];
int dp[1002];
vector<int> nodes[1002];

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        fill(d, d + 1002, 0);
        fill(messi, messi + 1002, 0);
        fill(dp, dp + 1002, 0);
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
            cin >> d[i];
        int st, en;
        for (int i = 1; i <= k; i++) {
            cin >> st >> en;
            nodes[st].push_back(en);
            messi[en]++;
        }
        int w;
        cin >> w;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (messi[j] == 0) {
                    for (int next : nodes[j])
                    {
                        messi[next]--;
                        dp[next] = max(dp[next], dp[j] + d[j]);
                    }
                    nodes[j].clear();
                }
            }
        }
        cout << dp[w] + d[w] << '\n';
    }
}