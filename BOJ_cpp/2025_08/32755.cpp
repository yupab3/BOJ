#include <iostream>
#include <vector>

using namespace std;

vector<int> nodes[502];

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, st, en;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        cin >> st >> en;
        nodes[st].push_back(en);
        nodes[en].push_back(st);
    }
    int flag = 0;
    for (int i = 1; i <= n; ++i)
        if (nodes[i].size() == n - 1) flag = 1 ;
    cout << n - flag << '\n';
    return 0;
}