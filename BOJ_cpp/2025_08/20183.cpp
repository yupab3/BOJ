#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

// A부터 B까지 최소 수치심을 찾되, 총 요금을 못 내면 다음 최소 수치심 찾기
// 최소 비용만 보면서 큐에서 뽑고, 누적 비용은 큐에 같이 저장하면서 진행
// 종점에 도착했을 때 확인하고 가능하면 중단, 안되면 다음 큐 진행
// 현재 최대치 // 누적 비용 // 다음 경로 를 큐에 저장하여 낮은 거부터 뽑아서 진행
// 현재 노드를 기준으로 이전까지 방문했던 조합 중 현재 조합보다 더 나은 조합이 있으면 무시
// 추가할 때도 동일하게 적용
// 만약 기존 조합보다 더 좋은 조합이 방문한 경우 기존 조합 중 현재 조합에 지배되는 조합 모두 삭제

long n, m, a, b, c, ans = 0;
vector<pair<long, long>> board[100002];
vector<pair<long, long>> nodes[100002];
priority_queue<tuple<long, long, long>, vector<tuple<long, long, long>>, greater<tuple<long, long, long>>> pq;

bool    isUseless(long cur, long cVal, long cCost) {
    for (auto past : board[cur]) {
        if (past.first <= cVal && past.second <= cCost) return true;
    }
    return false;
}

void    insertNewOne(long cur, long cVal, long cCost) {
    board[cur].erase(remove_if(board[cur].begin(), board[cur].end(), [&](const pair<long, long> trgt) { return (cVal <= trgt.first && cCost <= trgt.second); }), board[cur].end());
    board[cur].push_back({cVal, cCost});
}

void    dijkstra() {
    while (pq.size()) {
        auto [cVal, cCost, cur] = pq.top();
        pq.pop();
        if (c < cCost) continue ;
        if (isUseless(cur, cVal, cCost)) continue ;
        if (cur == b) {
            ans = cVal;
            break ;
        }
        insertNewOne(cur, cVal, cCost);
        for (auto [next, nCost] : nodes[cur]) {
            if (c < cCost + nCost) continue ;
            if (isUseless(next, max(cVal, nCost), cCost + nCost)) continue ;
            pq.push({max(cVal, nCost), cCost + nCost, next});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int st, en, cost;
    cin >> n >> m >> a >> b >> c;
    for (int i = 1; i <= m; ++i) {
        cin >> st >> en >> cost;
        nodes[st].push_back({en, cost});
        nodes[en].push_back({st, cost});
    }
    pq.push({0, 0, a});
    dijkstra();
    if (ans == 0) cout << "-1\n";
    else cout << ans << '\n';
    return 0;
}