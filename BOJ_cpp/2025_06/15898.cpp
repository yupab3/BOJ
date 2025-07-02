#include <iostream>
using namespace std;

int     n, ans = 0;
bool    vis[10];
char    block[10][4][4][2];
char    board[5][5][2];

void rotateBlock(int idx) {
    char    rot[4][4][2];
    for (int i = 0; i < 2; ++i) {
        rot[1][1][i] = block[idx][1][2][i];
        rot[1][2][i] = block[idx][2][2][i];
        rot[2][2][i] = block[idx][2][1][i];
        rot[2][1][i] = block[idx][1][1][i];
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 2; ++j) {
            rot[0][i][j] = block[idx][i][3][j];
            rot[i][3][j] = block[idx][3][3 - i][j];
            rot[3][3 - i][j] = block[idx][3 - i][0][j];
            rot[3 - i][0][j] = block[idx][0][i][j];
        }
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            block[idx][i][j][0] = rot[i][j][0];
            block[idx][i][j][1] = rot[i][j][1];
        }
    }
}

void    checkAns() {
    int r = 0, b = 0, g = 0, y = 0;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (board[i][j][1] == 'R') r += board[i][j][0];
            else if (board[i][j][1] == 'B') b += board[i][j][0];
            else if (board[i][j][1] == 'G') g += board[i][j][0];
            else if (board[i][j][1] == 'Y') y += board[i][j][0];
        }
    }
    ans = max(ans, 7 * r + 5 * b + 3 * g + 2 * y);
}

void    insertBlock(int idx, int x, int y) {
    for (int i = x; i < 4 + x; ++i) {
        for (int j = y; j < 4 + y; ++j) {
            board[i][j][0] += block[idx][i - x][j - y][0];
            if (block[idx][i - x][j - y][1] != 'W') board[i][j][1] = block[idx][i - x][j - y][1];
            if (board[i][j][0] < 0) board[i][j][0] = 0;
            else if (9 < board[i][j][0]) board[i][j][0] = 9;
        }
    }
}

void    dfs(int cnt) {
    if (cnt == 3) {
        checkAns();
        return ;
    }
    char    tmp[5][5][2];
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            tmp[i][j][0] = board[i][j][0];
            tmp[i][j][1] = board[i][j][1];
        }
    }
    for (int i = 0; i < n; ++i) {
        if (vis[i]) continue ;
        for (int j = 0; j < 4; ++j) {
            rotateBlock(i);
            for (int k = 0; k < 2; ++k) {
                for (int l = 0; l < 2; ++l) {
                    insertBlock(i, k, l);
                    vis[i] = true;
                    dfs(cnt + 1);
                    vis[i] = false;
                    for (int ii = 0; ii < 5; ++ii) {
                        for (int jj = 0; jj < 5; ++jj) {
                            board[ii][jj][0] = tmp[ii][jj][0];
                            board[ii][jj][1] = tmp[ii][jj][1];
                        }
                    }
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j)
            board[i][j][1] = 'W';
    }
    cin >> n;
    int input;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                cin >> input;
                block[i][j][k][0] = input;
            }
        }
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k)
                cin >> block[i][j][k][1];
        }
        // cout << "\n print Num ------- \n";
        // for (int j = 0; j < 4; ++j) {
        //     for (int k = 0; k < 4; ++k) {
        //         cout << block[i][j][k][0] << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << "\n print Col ------- \n";
        // for (int j = 0; j < 4; ++j) {
        //     for (int k = 0; k < 4; ++k) {
        //         cout << block[i][j][k][1] << ' ';
        //     }
        //     cout << '\n';
        // }
        // rotateBlock(i);
        // cout << "\n rot Num ------- \n";
        // for (int j = 0; j < 4; ++j) {
        //     for (int k = 0; k < 4; ++k) {
        //         cout << (int)block[i][j][k][0] << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << "\n rot Col ------- \n";
        // for (int j = 0; j < 4; ++j) {
        //     for (int k = 0; k < 4; ++k) {
        //         cout << block[i][j][k][1] << ' ';
        //     }
        //     cout << '\n';
        // }
    }
    dfs(0);
    cout << ans << '\n';
}