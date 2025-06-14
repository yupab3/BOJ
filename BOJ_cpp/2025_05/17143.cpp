#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int sizeR, sizeC, m;
int r[10002];
int c[10002];
int s[10002];
int d[10002];
int z[10002];
int board[102][102];
queue<int> q;
int ans;

void    getShark(int cC) {
    for (int i = 1; i <= sizeR; i++) {
        if (board[i][cC]) {
            ans += z[board[i][cC]];
            board[i][cC] = 0;
            return ;
        }
    }
}

void    setQueue() {
    for (int i = 1; i <= sizeR; i++) {
        for (int j = 1; j <= sizeC; j++)
            if (board[i][j]) q.push(board[i][j]);
    }
}

int getDistance(int idx) {
    if (d[idx] == 1) return r[idx] - 1;
    else if (d[idx] == 2) return sizeR - r[idx];
    else if (d[idx] == 3) return sizeC - c[idx];
    else return c[idx] - 1;
}

int togleDirection(int idx) {
    if (d[idx] == 1) return 2;
    else if (d[idx] == 2) return 1;
    else if (d[idx] == 3) return 4;
    else return 3;
}

void    setShark(int idx, int trgt) {
    if (d[idx] == 1) r[idx] -= trgt;
    else if (d[idx] == 2) r[idx] += trgt;
    else if (d[idx] == 3) c[idx] += trgt;
    else c[idx] -= trgt;
}

void    turnShark(int idx) {
    if (d[idx] == 1) r[idx] = 1;
    else if (d[idx] == 2) r[idx] = sizeR;
    else if (d[idx] == 3) c[idx] = sizeC;
    else c[idx] = 1;
    d[idx] = togleDirection(idx);
}

void    moveShark(int idx) {
    int cnt = s[idx];
    while (cnt) {
        int lastD = getDistance(idx);
        if (cnt > lastD) {
            cnt -= lastD;
            turnShark(idx);
        }
        else {
            setShark(idx, cnt);
            cnt = 0;
        }
    }
}

void    eatSmaller(int idx) {
    if (!board[r[idx]][c[idx]]) {
        board[r[idx]][c[idx]] = idx;
        return ;
    }
    int rival = board[r[idx]][c[idx]];
    if (z[rival] > z[idx]) return ;
    else board[r[idx]][c[idx]] = idx;
}

void    setBoard() {
    fill(&board[0][0], &board[0][0] + 102 * 102 - 1, 0);
    while (q.size()) {
        int cur = q.front();
        q.pop();
        moveShark(cur);
        eatSmaller(cur);
    }
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> sizeR >> sizeC >> m;
    for (int i = 1; i <= m; i++) {
        cin >> r[i] >> c[i] >> s[i] >> d[i] >> z[i];
        board[r[i]][c[i]] = i;
    }
    int cC = 1;
    while (cC <= sizeC) {
        getShark(cC);
        setQueue();
        setBoard();
        ++cC;
    }
    cout << ans << '\n';
}