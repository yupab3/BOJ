#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;

int         dx[9] = {1, 1, 1, 0, 0, 0, -1, -1, -1};
int         dy[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
vector<int> board[102][102];
int bot[10002];
int r, c, mv, jx, jy;
string moveSchedule;

queue<tuple<int, int, int>> q;

bool    ignoreQueue(int bx, int by) {
    if (board[bx][by].size()) return true;
    else return false;
}

void    killDupBots() {
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (board[i][j].size() > 1) {
                for (int botNum : board[i][j]) {
                    bot[botNum] = 1;
                }
                board[i][j].clear();
            }
        }
    }
}

int checkDir(int jx, int jy, int mx, int my) {
    vector<int> wayX, wayY;    
    if (mx - jx < 0) {
        wayX.push_back(1);
        wayX.push_back(2);
        wayX.push_back(3);
    }
    else if (mx - jx == 0) {
        wayX.push_back(4);
        wayX.push_back(6);
    }
    else {
        wayX.push_back(7);
        wayX.push_back(8);
        wayX.push_back(9);
    }
    if (my - jy < 0) {
        wayY.push_back(3);
        wayY.push_back(6);
        wayY.push_back(9);
    }
    else if (my - jy == 0) {
        wayY.push_back(2);
        wayY.push_back(8);
    }
    else {
        wayY.push_back(1);
        wayY.push_back(4);
        wayY.push_back(7);
    }
    for (int way : wayX)
        if (find(wayY.begin(), wayY.end(), way) != wayY.end()) return way;
    return 100;
}

bool    moveJS(int x, int y, int botNum) {
    if (botNum != 0) return false;
    int nx = x + dx[moveSchedule[mv] - 49];
    int ny = y + dy[moveSchedule[mv] - 49];
    mv++;
    if ((nx != x || ny != y) && board[nx][ny].size() > 0) return true;
    board[x][y].clear();
    board[nx][ny].push_back(botNum);
    jx = nx;
    jy = ny;
    q.push({nx, ny, 0});
    return false;
}

bool    moveBot(int x, int y, int botNum) {
    if (botNum == 0) return false;
    if (bot[botNum]) return false;
    int dir = checkDir(jx, jy, x, y);
    int nx = x + dx[dir - 1];
    int ny = y + dy[dir - 1];
    if (find(board[nx][ny].begin(), board[nx][ny].end(), 0) != board[nx][ny].end()) return true;
    board[x][y].erase(remove(board[x][y].begin(), board[x][y].end(), botNum), board[x][y].end());
    board[nx][ny].push_back(botNum);
    q.push({nx, ny, botNum});
    return false;
}

void    printBoard() {
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (board[i][j].size() == 1 && board[i][j].front() == 0) cout << 'I';
            else if (board[i][j].size() == 1 && board[i][j].front() != 0) cout << 'R';
            else cout << '.';
        }
        cout << '\n';
    }
}

bool    bfs() {
    while (q.size()) {
        auto [cx, cy, botNum] = q.front();
        q.pop();
        // int tt;
        // cin >> tt;
        // cout << "cur mv : " << mv << ", botNum : " << botNum << '\n';
        // printBoard();
        if (botNum == 0) {
            killDupBots();
            if (mv == moveSchedule.length()) return true;
        }
        if (moveJS(cx, cy, botNum)) return false;
        if (moveBot(cx, cy, botNum)) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    cin >> r >> c;
    int tmpBoard[102][102];
    for (int i = 1; i <= r; i++) {
        string tmp;
        cin >> tmp;
        for (int j = 1; j <= c; j++) {
            tmpBoard[i][j] = tmp[j - 1];
            if (tmpBoard[i][j] == 'I')
            {
                board[i][j].push_back(0);
                q.push({i, j, 0});
                jx = i;
                jy = j;
            }
        }
    }
    cin >> moveSchedule;
    int botNum = 1;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (tmpBoard[i][j] == 'R')
            {
                board[i][j].push_back(botNum);
                q.push({i, j, botNum++});
            }
        }
    }
    if (bfs())
        printBoard();
    else
        cout << "kraj " << mv << '\n';
}