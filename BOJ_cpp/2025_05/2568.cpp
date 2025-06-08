#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

//LIS를 수행하며 최장 수열로 갱신하는 애들은 그대로 놔둔다
//최장 수열이 아닌 이전 값을 갱신하는 경우 큐에 쌓아둔다.

int n;
stack<int> stk;
vector<pair<int, int>> node;
vector<int> seq;
int m[100002];
int p[100002];

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> n;
    int s, e;
    for (int i = 1; i <= n; i++) {
        cin >> s >> e;
        node.push_back({s, e});
    }
    sort(node.begin(), node.end());
    seq.push_back(-1);
    m[0] = -1;
    for (int i = 1; i <= n; i++) {
        int idx = lower_bound(seq.begin(), seq.end(), node[i - 1].second) - seq.begin();
        // cout << "idx : " << idx << '\n';
        if (idx == seq.size()) {
            seq.push_back(node[i - 1].second);
            m[idx] = i - 1;
            p[i - 1] = m[idx - 1];
        } 
        else {
            seq[idx] = node[i - 1].second;
            m[idx] = i - 1;
            p[i - 1] = m[idx - 1];
        }
    }
    cout << node.size() - seq.size() + 1 << '\n';
    int idx = m[seq.size() - 1];
    while (idx >= 0) {
        stk.push(node[idx].first);
        idx = p[idx];
    }
    for (int i = 0; i < n; i++) {
        if (stk.size() && node[i].first == stk.top()) stk.pop();
        else cout << node[i].first << '\n';
    }
}