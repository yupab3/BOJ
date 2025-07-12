#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int line[26];
queue<int> q;
vector<int> nodes[26];

void    bfs() {
    while(q.size()) {
        int cur = q.front();
        q.pop();
        line[cur] = 0;
        for (int next : nodes[cur])
            if (--line[next] == 0) q.push(next);
    }
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> n >> m;
    char st, en;
    for (int i = 1; i <= m; ++i) {
        cin >> st >> en;
        st = st - 'A';
        en = en - 'A';
        nodes[st].push_back(en);
        ++line[en];
    }
    cin >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> en;
        en = en - 'A';
        q.push(en);
    }
    bfs();
    int ans = 0;
    for (int i = 0; i < n; ++i)
        if (line[i] > 0) ++ans;
    cout << ans << '\n';
}