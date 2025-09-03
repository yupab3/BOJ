#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 마지막 도착지에 있는 위상이 0이 될 때 까지 반복
// 각 기본 재료가 몇 개 필요한지 곱하면서 합산 저장
// 1->5 3개 5 -> 6 4개 // 1 -> [5][1] = [5][1] * [1][1] 3 저장 // 5 -> [6][1] = [5][1] * [6][5] 12 저장

// 기본 재료만 처음에 파악한 뒤 진행

int n, m;
int degree[102];
int board[102];
queue<int> q;
vector<pair<int, int>> material[102];

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> n >> m;
    int x, y, k;
    for (int i = 1; i <= m; ++i) {
        cin >> x >> y >> k;
        ++degree[y];
        material[x].push_back({y, k});
    }
    board[n] = 1;
    q.push(n);
    while (q.size()) {
        int cur = q.front();
        q.pop();
        for (auto [next, cost] : material[cur]) {
            --degree[next];
            if (degree[next] == 0) q.push(next);
            board[next] += cost * board[cur];
        }
    }
    for (int i = 1; i <= n; ++i)
        if (material[i].size() == 0) cout << i << ' ' << board[i] << '\n';
    return 0;
}