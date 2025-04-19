#include <iostream>
#include <map>
#include <queue>

using namespace std;

int n, k;
map<int, int> vis;
queue<int> q;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        vis[x] = 0;
        q.push(x);
    }
    long ans = 0;
    while (k > 0) {
        int cur = q.front();
        q.pop();
        if (vis.find(cur - 1) == vis.end()) {
            vis[cur - 1] = vis[cur] + 1;
            ans += vis[cur] + 1;
            q.push(cur - 1);
            k--;
        }
        if (k == 0) break ;
        if (vis.find(cur + 1) == vis.end()) {
            vis[cur + 1] = vis[cur] + 1;
            ans += vis[cur] + 1;
            q.push(cur + 1);
            k--;
        }
    }
    cout << ans << '\n';
}