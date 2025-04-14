#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int     n, totalCost = 0;
int     board[52];
bool    vis[52];
vector<pair<int, int>> nodes[52];
priority_queue<
    pair<int, int>,
    vector<pair<int, int>>,
    greater<pair<int, int>>
> pq;

void    dijkstra() {
    while (pq.size()) {
        auto [cost, dest] = pq.top();
        pq.pop();
        if (vis[dest]) continue ;
        vis[dest] = true;
        totalCost += cost;
        board[dest] = cost;
        for (auto next : nodes[dest])
            pq.push(next);
    }
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    cin >> n;
    string tmp;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        for (int j = 1; j <= n; j++) {
            int cost = 0;
            if ('a' <= tmp[j - 1] && tmp[j - 1] <= 'z') cost = tmp[j - 1] - 'a' + 1;
            else if ('A' <= tmp[j - 1] && tmp[j - 1] <= 'Z') cost = tmp[j - 1] - 'A' + 27;
            else continue ;
            if (i != j) {
                nodes[i].push_back({cost, j});
                nodes[j].push_back({cost, i});
            }
            sum += cost;
        }
    }
    fill(board, board + 52, 100);
    pq.push({0, 1});
    dijkstra();
    for (int i = 1; i <= n; i++) {
        if (board[i] == 100) {
            cout << "-1\n";
            return 0;
        }
    }
    cout << sum - totalCost << '\n';
}