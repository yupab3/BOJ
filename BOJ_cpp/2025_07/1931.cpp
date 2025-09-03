#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, ans;
vector<pair<int, int>> lectures;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> n;
    int st, en;
    for (int i = 1; i <= n; ++i) {
        cin >> st >> en;
        lectures.push_back({en, st});
    }

    sort(lectures.begin(), lectures.end(), [](pair<int, int> &a, pair<int, int> &b) {
        if (a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    });
    int cur = 0, cnt = 0;
    for (pair<int ,int> next : lectures) {
        if (next.first < cur || next.second < cur) continue ;
        cur = next.first;
        cnt++;
    }
    cout << cnt << '\n';
}