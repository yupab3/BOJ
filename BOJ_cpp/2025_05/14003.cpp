#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int n;
int var[1000002];
int p[1000002];
int k[1000002];
vector<int> m;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> var[i];
    m.push_back(-1e9 - 3);
    int l = 0;
    k[0] = -1;
    for (int i = 1; i <= n; i++) {
        int idx = lower_bound(m.begin(), m.end(), var[i]) - m.begin();
        if (idx == m.size()) {
            m.push_back(var[i]);
            k[idx] = i;
            p[i] = k[idx - 1];
            ++l;
        }
        else {
            m[idx] = var[i];
            k[idx] = i;
            p[i] = k[idx - 1];
        }
    }
    cout << l << '\n';

    stack<int> s;
    int idx = k[l];
    while (idx > 0) {
        s.push(var[idx]);
        idx = p[idx];
    }
    while (s.size()) {
        cout << s.top();
        s.pop();
        if (s.size()) cout << ' ';
    }
    cout << '\n';
}