#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, s, p;
int board[328002];
vector<int> nodes[328002];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void    dijkstra() {
    while (pq.size()) {
        pair<int, int> cur = pq.top();
        pq.pop();
        int cost = cur.first;
        int idx = cur.second;
        if (board[idx] <= cost) continue ;
        board[idx] = cost;
        for (int next : nodes[idx]) {
            if (board[next] < cost + 1) continue ;
            pq.push({cost + 1, next});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> n >> s >> p;
    int st, en;
    for (int i = 1; i < n; ++i) {
        cin >> st >> en;
        nodes[st].push_back(en);
        nodes[en].push_back(st);
    }
    fill(board, board + 328002, 1e9);
    pq.push({0, p});
    dijkstra();
    sort(board, board + s);
    cout << n - board[0] - board[1] - 1 << '\n';
}