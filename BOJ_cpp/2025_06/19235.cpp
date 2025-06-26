#include <iostream>

using namespace std;

int n, ans = 0;
int G[6][4];
int B[4][6];

int pushCountB(int blockType, int x, int y) {
    if (blockType == 1) {
        if (B[x][1] && B[x][2]) return 1;
    }
    else if (blockType == 2) {
        if (B[x][0] && B[x][2]) return 2;
        if (B[x][0] && B[x][3]) return 1;
        if (B[x][1] && B[x][2]) return 1;
    }
    else if ((B[x][1] && B[x][2]) || (B[x + 1][1] && B[x + 1][2])) return 1;
    return 0;
}

int pushCountG(int blockType, int x, int y) {
    if (blockType == 1) {
        if (G[1][y] && G[2][y]) return 1;
    }   
    else if (blockType == 3) {
        if (G[0][y] && G[2][y]) return 2;
        if (G[0][y] && G[3][y]) return 1;
        if (G[1][y] && G[2][y]) return 1;
    }
    else if ((G[1][y] && G[2][y]) || (G[1][y + 1] && G[2][y + 1])) return 1;
    return 0;
}

int checkScoreB() {
    int score = 0;
    for (int i = 2; i < 6; ++i) {
        bool complete = true;
        for (int j = 0; j < 4; ++j) {
            if (!B[j][i]) complete = false;
        }
        if (complete) {
            score ++;
        }
    }
    return score;
}

int checkScoreG() {
    int score = 0;
    for (int i = 2; i < 6; ++i) {
        bool complete = true;
        for (int j = 0; j < 4; ++j) {
            if (!G[i][j]) complete = false;
        }
        if (complete) {
            score ++;
        }
    }
    return score;
}

int getScoreB() {
    int score = 0;
    for (int i = 2; i < 6; ++i) {
        bool complete = true;
        for (int j = 0; j < 4; ++j) {
            if (!B[j][i]) complete = false;
        }
        if (complete) {
            score ++;
            for (int j = 0; j < 4; ++j) {
                B[j][i] = 0;
            }
        }
    }
    return score;
}

int getScoreG() {
    int score = 0;
    for (int i = 2; i < 6; ++i) {
        bool complete = true;
        for (int j = 0; j < 4; ++j) {
            if (!G[i][j]) complete = false;
        }
        if (complete) {
            score ++;
            for (int j = 0; j < 4; ++j) {
                G[i][j] = 0;
            }
        }
    }
    return score;
}

void    pushB(int cnt) {
    for (int i = 1; i <= cnt; i++) {
        for (int j = 5; j >= 2; --j) {
            for (int k = 0; k < 4; ++k) {
                if (j == 2) B[k][j] = 0;
                else B[k][j] = B[k][j - 1];
            }
        }
    }
}

void    pushG(int cnt) {
    for (int i = 1; i <= cnt; i++) {
        for (int j = 5; j >= 2; --j) {
            for (int k = 0; k < 4; ++k) {
                if (j == 2) G[j][k] = 0;
                else G[j][k] = G[j - 1][k];
            }
        }
    }
}

void    insertBlock(int blockType, int x, int y, int blockNum) {
    if (blockType == 1) {
        B[x][1] = blockNum;
        G[1][y] = blockNum;
    }
    else if (blockType == 2) {
        B[x][0] = blockNum;
        B[x][1] = blockNum;
        G[1][y] = blockNum;
        G[1][y + 1] = blockNum;
    }
    else {
        B[x][1] = blockNum;
        B[x + 1][1] = blockNum;
        G[0][y] = blockNum;
        G[1][y] = blockNum;
    }
}
// B는 세로, A는 가로 확인 필요
void    sortB() {
    for (int i = 2; i < 6; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (!B[j][i]) {
                if (j > 0 && B[j][i - 1] == B[j - 1][i - 1]) {
                    if (!B[j - 1][i]) {
                        B[j][i] = B[j][i - 1];
                        B[j - 1][i] = B[j - 1][i - 1];
                        B[j][i - 1] = 0;
                        B[j - 1][i - 1] = 0;
                    }
                    continue ;
                }
                if (j < 3 && B[j][i - 1] == B[j + 1][i - 1]) {
                    if (!B[j + 1][i]) {
                        B[j][i] = B[j][i - 1];
                        B[j + 1][i] = B[j + 1][i - 1];
                        B[j][i - 1] = 0;
                        B[j + 1][i - 1] = 0;
                        ++j;
                    }
                    continue ;
                }
                B[j][i] = B[j][i - 1];
                if (B[j][i - 1] == B[j][i - 2]) B[j][i - 2] = 0;
                else B[j][i - 1] = 0;
            }
        }
    }
}

void    sortG() {
    for (int i = 2; i < 6; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (!G[i][j]) {
                if (j > 0 && G[i - 1][j] == G[i - 1][j - 1]) {
                    if (!G[i][j - 1]) {
                        G[i][j] = G[i - 1][j];
                        G[i][j - 1] = G[i - 1][j - 1];
                        G[i - 1][j] = 0;
                        G[i - 1][j - 1] = 0;
                    }
                    continue ;
                }
                if (j < 3 && G[i - 1][j] == G[i - 1][j + 1]) {
                    if (!G[i][j + 1]) {
                        G[i][j] = G[i - 1][j];
                        G[i][j + 1] = G[i - 1][j + 1];
                        G[i - 1][j] = 0;
                        G[i - 1][j + 1] = 0;
                        ++j;
                    }
                    continue ;
                }
                G[i][j] = G[i - 1][j];
                if (G[i - 1][j] == G[i - 2][j]) G[i - 2][j] = 0;
                else G[i - 1][j] = 0;
            }
        }
    }
}

int lastG() {
    int cnt = 0;
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (G[i][j]) ++cnt;
        }
    }
    return cnt;
}

int lastB() {
    int cnt = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 6; ++j) {
            if (B[i][j]) ++cnt;
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> n;
    int blockType, x, y;
    for (int i = 1; i <= n; i++) {
        cin >> blockType >> x >> y;
        insertBlock(blockType, x, y, i);
        sortB();
        sortG();
        while (checkScoreB()) {
            ans += getScoreB();
            sortB();
        }
        while (checkScoreG()) {
            ans += getScoreG();
            sortG();
        }
        pushB(pushCountB(blockType, x, y));
        pushG(pushCountG(blockType, x, y));
        sortB();
        sortG();
    }
    cout << ans << '\n';
    cout << lastB() + lastG() << '\n';
}