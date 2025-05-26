#include <iostream>

using namespace std;

int n;
int ans = 0;
int board[100002][2];

// 현재 왼쪽을 보는 상의 수 기준 점수
// 현재 오른쪽을 보는 상의 수 기준 점수
// 최대 점수 측정
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> n;
    int dir;
    for (int i = 1; i <= n; i++) {
        cin >> dir;
        if (dir == 1) {
            if (board[i - 1][0] <= 0) board[i][0] = 1;
            else board[i][0] = board[i - 1][0] + 1;
            board[i][1] = board[i - 1][1] - 1;
        }
        else {
            if (board[i - 1][1] <= 0) board[i][1] = 1;
            else board[i][1] = board[i - 1][1] + 1;
            board[i][0] = board[i - 1][0] - 1;
        }
        ans = max(ans, max(board[i][0], board[i][1]));
    }
    cout << ans << '\n';
}