#include <iostream>
#include <vector>
#include <queue>

// 2000개 순회하며 하나씩 터뜨린 다음 이상 없는지 확인하기 -> n^2

using namespace std;

int         n, m, k;
bool        trgt[2002];
bool        fire[2002];
vector<int> nodes[2002];

bool    checkAns() {
    for (int i = 1; i <= n; ++i)
        if (trgt[i] != fire[i]) return false;
    return true ;
}

bool    checkTrgt(queue<int> q) {
    while (q.size()) {
        if (trgt[q.front()] != fire[q.front()]) return false;
        q.pop();
    }
    return true ;
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> n >> m;
    int a, b;
    for (int i = 1; i <= m; ++i) {
        cin >> a >> b;
        nodes[a].push_back(b);
        nodes[b].push_back(a);
    }
    cin >> k;
    int idx;
    for (int i = 1; i <= k; ++i) {
        cin >> idx;
        trgt[idx] = true;
    }
    queue<int> ans;
    for (idx = 1; idx <= n; ++idx) {
        queue<int> cur;
        if (fire[idx] == 0) {
            // cout << "first idx : " << idx << '\n';
            fire[idx] = true;
            cur.push(idx);
        }
        for (int next : nodes[idx]) {
            // cout << "idx's next : " << next << '\n';
            if (fire[next]) continue ;
            // cout << "changed\n";
            fire[next] = true;
            cur.push(next);
        }
        if (checkTrgt(cur)) {
            ans.push(idx);
            continue ;
        }
        // cout << "reset\n";
        while (cur.size()) {
            fire[cur.front()] = false;
            cur.pop();
        }
    }
    if (checkAns() == false) {
        cout << "-1";
        return 0;
    }
    cout << ans.size() << '\n';
    while (ans.size()) {
        cout << ans.front();
        ans.pop();
        if (ans.size() != 0) cout << ' ';
    }
    return 0;
}