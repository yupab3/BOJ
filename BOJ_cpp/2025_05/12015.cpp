#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int var[1000002];
vector<int> m;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> var[i];
    m.push_back(-1);
    for (int i = 1; i <= n; i++) {
        int idx = lower_bound(m.begin(), m.end(), var[i]) - m.begin();
        if (idx == m.size()) m.push_back(var[i]);
        else m[idx] = var[i];
    }
    cout << m.size() - 1 << '\n';
}