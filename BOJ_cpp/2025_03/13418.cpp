#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

// 왕복 가능한 노드
// 비용은 0과 1
// 모든 정점을 거쳤을 떄 비용을 합친 값 k가 제일 적은 경로 찾기 - 최선
// 설정 해두고 프림 돌리면 끝..
// 모든 정점을 거쳤을 때 비용을 합친 값 k가 제일 큰 경로 찾기 - 최악
// 설정 해두고 프림 돌리면 끝..

// 큰 값을 찾으며 가면 내리막수 최대
// 작은 값을 찾으며 가면 오르막수 최대

int n, m, maxCost = 0, minCost = 0;
bool vis[1002];
vector<pair<int, int>>  nodes[1002];
priority_queue<
    pair<int, int>, 
    vector<pair<int, int>>, 
    greater<pair<int, int>>
> pq_asc;
priority_queue<
    pair<int, int>
> pq_desc;

void dijkstra_asc() {
    while (pq_asc.size()) {
        auto [cost, dest] = pq_asc.top();
        pq_asc.pop();
        if (vis[dest]) continue ;
        vis[dest] = true;
        maxCost += cost;
        for (auto [n_cost, n_dest] : nodes[dest]) {
            if (vis[n_dest]) continue ;
            pq_asc.push({n_cost, n_dest});
        }
    }
}

void dijkstra_desc() {
    while (pq_desc.size()) {
        auto [cost, dest] = pq_desc.top();
        pq_desc.pop();
        if (vis[dest]) continue ;
        vis[dest] = true;
        minCost += cost;
        for (auto [n_cost, n_dest] : nodes[dest]) {
            if (vis[n_dest]) continue ;
            pq_desc.push({n_cost, n_dest});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    cin >> n >> m;
    int home, dest, cost;
    // if (n == 1) {
    //     cin >> home >> dest >> cost;
    //     cout << n - cost << '\n';
    //     return 0;
    // }
    for (int i = 1; i <= m + 1; i++) {
        cin >> home >> dest >> cost;
        nodes[home].push_back({cost, dest});
        nodes[dest].push_back({cost, home});
    }
    for (auto n_node : nodes[0])
    {
        pq_asc.push(n_node);
        pq_desc.push(n_node);
    }
    fill(vis, vis + 1002, false);
    vis[0] = true;
    dijkstra_asc();
    fill(vis, vis + 1002, false);
    vis[0] = true;
    dijkstra_desc();
    minCost = n - minCost;
    maxCost = n - maxCost;
    cout << pow(maxCost, 2) - pow(minCost, 2) << '\n';
}




// 모든 노드에 대한 비용이 독립적이고, 모두 1이므로 그냥 정리한 다음 싹 합해도 같다?
// 양방향 노드이므로 불가능..

// int main() {
//     ios::sync_with_stdio(false);
//     std::cin.tie(NULL);

//     cin >> n >> m;
//     int home, dest, cost;
//     fill(board, board + 1002, 1e9 + 2);
//     for (int i = 1; i <= n * (n - 1) / 2; i++) {
//         cin >> home >> dest >> cost;
//         nodes[home].push_back({cost, dest});
//         if (board[dest] == 0) continue ;
//         else board[dest] = cost;
//     }
//     int maxCost = 0;
//     for (int i = 1; i <= n; i++)
//         maxCost += board[i];
//     maxCost = n - maxCost;
//     fill(board, board + 1002, 1e9 + 2);
//     for (int i = 0; i <= n; i++) {
//         for (auto [cost, dest] : nodes[i]) {
//             if (board[dest] == 1) continue ;
//             else board[dest] = cost;
//         }
//     }
//     int minCost = 0;
//     for (int i = 1; i <= n; i++)
//         minCost += board[i];
//     minCost = n - minCost;
//     maxCost = pow(maxCost, 2);
//     minCost = pow(minCost, 2);
//     cout << maxCost - minCost << '\n';
// }