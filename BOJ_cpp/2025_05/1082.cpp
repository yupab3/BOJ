#include <iostream>
#include <queue>

using namespace std;

int p[10];
queue<int> dp[52];

queue<int> maxQueue(queue<int> l, queue<int> r) {
    queue<int> orgL = l;
    queue<int> orgR = r;
    if (l.size() == r.size()) {
        while (l.size()) {
            if (l.front() > r.front()) return orgL;
            else if (l.front() < r.front()) return orgR;
            l.pop();
            r.pop();
        }
    }
    return (l.size() > r.size() ? orgL : orgR);
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> p[i];
    cin >> m;
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j < n; j++) {
            if (i + p[j] <= m) {
                queue<int> cur = dp[i];
                if (cur.size() && cur.front() == 0) cur.pop();
                cur.push(j);
                dp[i + p[j]] = maxQueue(dp[i + p[j]], cur);
            }
        }
    }
    while (dp[m].size()) {
        cout << dp[m].front();
        dp[m].pop();
    }
}