#include <iostream>

using namespace std;

int board[5][5];

bool    checkEnd() {
    for (int i = 1; i <= 3; ++i) {
        if (board[i][1] == board[i][2] && board[i][2] == board[i][3] && (board[i][3] == 1 || board[i][3] == 2)) return true ;
        if (board[1][i] == board[2][i] && board[2][i] == board[3][i] && (board[3][i] == 1 || board[3][i] == 2)) return true ;
    }
    if (board[1][1] == board[2][2] && board[2][2] == board[3][3] && (board[3][3] == 1 || board[3][3] == 2)) return true ;
    if (board[1][3] == board[2][2] && board[2][2] == board[3][1] && (board[3][1] == 1 || board[3][1] == 2)) return true ;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int x, y, num;
    cin >> num;
    for (int i = 1; i <= 9; ++i) {
        cin >> x >> y;
        board[x][y] = num;
        if (num == 1) num = 2;
        else num = 1;
        if (checkEnd()) {
            cout << board[x][y] + 2 * (board[x][y] == 0);
            return 0;
        }
    }
    cout << "0\n";
    return 0;
}