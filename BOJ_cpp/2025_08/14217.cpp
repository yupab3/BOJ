#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

// 벡터로 노드 관리하고 다익스트라 매번 돌리면서 불가능한 애들 -1, 나 자신은 0, 나머지는 최단거리로 출력

int n, m, q;
int dist[502];
vector<int> nodes[502];
queue<pair<int, int>> que;

void    dijkstra() {
    while (que.size()) {
        auto [cost, cur] = que.front();
        // cout << "cur : " << cur << ", dist[" << cur << "] : " << dist[cur] << ", cost : " << cost << '\n';
        que.pop();
        if (dist[cur] <= cost) continue ;
        dist[cur] = cost;
        for (int next : nodes[cur]) {
            if (dist[next] < cost + 1) continue ;
            // cout << "next : " << next << ", cost : " << cost + 1 << '\n';
            que.push({cost + 1, next});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> n >> m;
    int a, b, task;
    for (int i = 1; i <= m; ++i) {
        cin >> a >> b;
        nodes[a].push_back(b);
        nodes[b].push_back(a);
    }
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        fill(dist, dist + 502, 1e9);
        cin >> task >> a >> b;
        if (task == 1) {
            nodes[a].push_back(b);
            nodes[b].push_back(a);
        }
        else {
            nodes[a].erase(find(nodes[a].begin(), nodes[a].end(), b));
            nodes[b].erase(find(nodes[b].begin(), nodes[b].end(), a));
        }
        que.push({0, 1});
        dijkstra();
        for (int j = 1; j <= n; ++j) {
            if (dist[j] == 1e9) cout << "-1 ";
            else cout << dist[j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}