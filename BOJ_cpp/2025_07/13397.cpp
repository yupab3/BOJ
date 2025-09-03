#include <iostream>

using namespace std;

int n, m;
int board[5002];

bool    isPossible(int gap) {
    int maxVal = 0, minVal = 10000, cnt = 1;
    for (int i = 1; i <= n; ++i) {
        maxVal = max(maxVal, board[i]);
        minVal = min(minVal, board[i]);
        if (maxVal - minVal > gap) {
            maxVal = board[i];
            minVal = board[i];
            cnt++;
        }
    }
    if (cnt <= m) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> board[i];

    int st = -1, en = 10000;
    while (st + 1 < en) {
        int mid = (st + en) / 2;
        if (isPossible(mid)) en = mid;
        else st = mid;
    }
    cout << en << '\n';
}