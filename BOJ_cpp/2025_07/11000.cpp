#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
vector<pair<int, int>> lectures;

bool    isPossible(int slot) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (pair<int, int> next : lectures) {
        if (pq.size() < slot) {
            pq.push(next.second);
            continue ;
        }
        if (pq.top() > next.first) return false;
        pq.pop();
        pq.push(next.second);
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> n;
    int st, en;
    for (int i = 1; i <= n; ++i) {
        cin >> st >> en;
        lectures.push_back({st, en});
    }
    sort(lectures.begin(), lectures.end(), [](pair<int, int> &a, pair<int, int> &b) {
        if (a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    });
    st = 0, en = 1e9;
    while (st + 1 < en) {
        int mid = (st + en) / 2;
        if (isPossible(mid)) en = mid;
        else st = mid;
    }
    cout << en << '\n';
}