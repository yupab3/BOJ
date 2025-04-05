#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>>  node[1002];
bool                    visit_node[1002];
int dfs(int c_node, int c_d) {
    if (node[c_node].size() == 1) return c_d;
    int sum_d = 0;
    for (auto it = node[c_node].begin(); it != node[c_node].end(); it++)  {
        int n_node = it->first;
        if (visit_node[n_node]) continue ;
        visit_node[n_node] = true;
        sum_d += dfs(n_node, it->second);
    }
    return min(sum_d, c_d);
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    cin >> t;
    while (t) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= m; i++) {
            int a, b, d;
            cin >> a >> b >> d;
            node[a].push_back({b, d});
            node[b].push_back({a, d});
        }
        visit_node[1] = true;
        int ans = 0;
        for (auto it = node[1].begin(); it != node[1].end(); it++) {
            visit_node[it->first] = true;
            ans += dfs(it->first, it->second);
        }
        cout << ans << '\n';
        for (int i = 1; i <= n; i++) {
            node[i].clear();
        }
        fill(visit_node, visit_node + 1002, false);
        t--;
    }
}