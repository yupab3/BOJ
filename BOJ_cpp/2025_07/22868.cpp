#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// bfs로 vis찍으면서 모든 노드 방문, queue는 pq로 사용
// 지나왔던 길을 다 저장해둬야 함.
// 도착했을 때 결과를 빼놓고 두 개를 출력
// 각 배열에 자기 자신에 도착하는 최소치를 저장 -> e에서 역으로 추적하면 s로 도착

int         n, m, s, e;
int         pre[10002];
bool        vis[10002];
vector<int> nodes[10002];
queue<int>  q;

void    bfs(int e) {
    while (q.size()) {
        int cur = q.front();
        q.pop();
        if (e == cur) break ;
        for (int next : nodes[cur]) {
            if (vis[next]) continue ;
            vis[next] = 1;
            pre[next] = cur;
            q.push(next);
        }
    }
}

int countNodes(int s, int e) {
    fill(vis, vis + 10001, 0);
    int cur = e, cnt = 0;
    while (cur != s) {
        if (cur != s && cur != e) vis[cur] = 1;
        ++cnt;
        cur = pre[cur];
    }
    fill(pre, pre + 10001, 0);
    while (q.size()) q.pop();
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> s >> e;
        nodes[s].push_back(e);
        nodes[e].push_back(s);
    }
    cin >> s >> e;
    for (int i = 1; i <= n; ++i)
        sort(nodes[i].begin(), nodes[i].end());
    vis[s] = 1;
    q.push(s);
    bfs(e);
    int forward = countNodes(s, e);
    vis[e] = 1;
    q.push(e);
    bfs(s);
    int backward = countNodes(e, s);
    cout << forward + backward << '\n';
}