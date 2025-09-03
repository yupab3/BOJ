#include <iostream>
#include <algorithm>

using namespace std;

int r, c, paper, wTile;
int board[1000002];

bool    isPossible(int size) {
    int last = 0, cnt = 0;
    for (int i = 1; i <= c; ++i) {
        if (board[i] > size) return false;
        if (board[i]) {
            if (last <= 0) {
                last = size;
                cnt++;
            }
        }
        last--;
    }
    if (paper >= cnt) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> r >> c >> paper >> wTile;
    int cr, cc;
    for (int i = 1; i <= wTile; ++i) {
        cin >> cr >> cc;
        board[cc] = max(board[cc], cr);
    }
    int st = -1, en = 1e6;
    while (st + 1 < en) {
        int mid = (st + en) / 2;
        if (isPossible(mid)) en = mid;
        else st = mid;
    }
    cout << en << '\n';
}