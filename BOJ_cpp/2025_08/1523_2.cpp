#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int ans[2002];
int board[2002][2002];
vector<pair<int, int>> bulb;

void printBoard() {
    cout << "------ board ------ \n";
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "------ board ------ \n";
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> n >> m;
    string input;
    for (int i = 1; i <= n; ++i) {
        cin >> input;
        for (int j = 1; j <= m; ++j) {
            if (input[j - 1] == '.') board[i][j] = 0;
            else {
                board[i][j] = 1; 
                bulb.push_back({i, j});
            }
        }
    }
    for (auto [cx, cy] : bulb) {
        board[cx][cy] += board[cx - 1][cy - 1];
        // cout << '(' << cx << ", " << cy << ") : " << board[cx][cy] << "\n";
        int gapX = 1;
        int gapY = 1;
        int tx = cx - 1, ty = cy;
        while (tx > 0 && board[tx][ty] == 0) {
            ++gapX;
            --tx;
        }
        tx = cx;
        ty = cy - 1;
        while (ty > 0 && board[tx][ty] == 0) {
            ++gapY;
            --ty;
        }
        // cout << "gap : (" << gapX << ", " << gapY << ")\n";
        board[cx][cy] = min(board[cx][cy], min(gapX, gapY));
    }
    // printBoard();
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            while (board[i][j]) {
                ++ans[board[i][j]];
                --board[i][j];
            }
        }
    }
    for (int i = 1; i <= min(n, m); ++i)
        cout << ans[i] << '\n';
    return 0;
}