#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, x;
vector<int> prod;

bool    isPossible(int n) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int cur : prod) {
        if (pq.size() < n) pq.push(cur);
        else if (x - pq.top() < cur) return false;
        else {
            cur += pq.top();
            pq.pop();
            pq.push(cur);
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> n >> x;
    int tmp;
    for (int i = 1; i <= n; ++i) {
        cin >> tmp;
        prod.push_back(tmp);
    }
    int st = 1, en = n;
    while (st < en) {
        // cout << "st : " << st << ", en : " << en << '\n';
        int mid = (st + en) / 2;
        if (isPossible(mid)) en = mid;
        else st = mid + 1;
    }
    cout << st << '\n';
}