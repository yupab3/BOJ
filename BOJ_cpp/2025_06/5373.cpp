#include <iostream>

using namespace std;

int n;
char    board[6][3][3];

//0 위
//1 아래
//2 앞
//3 뒤
//4 좌
//5 우

void    initBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[0][i][j] = 'w';
            board[1][i][j] = 'y';
            board[2][i][j] = 'r';
            board[3][i][j] = 'o';
            board[4][i][j] = 'g';
            board[5][i][j] = 'b';
        }
    }
}

void    rotateOwnFace(int face, char direction) {
    int tmp[3];
    if (face == 'U') face = 0;
    else if (face == 'D') face = 1;
    else if (face == 'F') face = 2;
    else if (face == 'B') face = 3;
    else if (face == 'L') face = 4;
    else face = 5;
    for (int i = 0; i < 2; i++)
        tmp[i] = board[face][0][i];
    if (direction == '+') {
        for (int i = 0; i < 2; i++) {
            board[face][0][i] = board[face][2 - i][0];
            board[face][2 - i][0] = board[face][2][2 - i];
            board[face][2][2 - i] = board[face][i][2];
            board[face][i][2] = tmp[i];
        }
    }
    else {
        for (int i = 0; i < 2; i++) {
            board[face][0][i] = board[face][i][2];
            board[face][i][2] = board[face][2][2 - i];
            board[face][2][2 - i] = board[face][2 - i][0];
            board[face][2 - i][0] = tmp[i];
        }
    }
}

void    rotateUpper(char direction) {
    int tmp;
    if (direction == '+') {
        for (int i = 0; i < 3; i++) {
            tmp = board[2][0][i];
            board[2][0][i] = board[5][0][i];
            board[5][0][i] = board[3][0][i];
            board[3][0][i] = board[4][0][i];
            board[4][0][i] = tmp;
        }
    }
    else {
        for (int i = 0; i < 3; i++) {
            tmp = board[2][0][i];
            board[2][0][i] = board[4][0][i];
            board[4][0][i] = board[3][0][i];
            board[3][0][i] = board[5][0][i];
            board[5][0][i] = tmp;
        }
    }
}

void    rotateLower(char direction) {
    int tmp;
    if (direction == '+') {
        for (int i = 0; i < 3; i++) {
            tmp = board[2][2][i];
            board[2][2][i] = board[4][2][i];
            board[4][2][i] = board[3][2][i];
            board[3][2][i] = board[5][2][i];
            board[5][2][i] = tmp;
        }
    }
    else {
        for (int i = 0; i < 3; i++) {
            tmp = board[2][2][i];
            board[2][2][i] = board[5][2][i];
            board[5][2][i] = board[3][2][i];
            board[3][2][i] = board[4][2][i];
            board[4][2][i] = tmp;
        }
    }
}

void    rotateFront(char direction) {
    int tmp;
    if (direction == '+') {
        for (int i = 0; i < 3; i++) {
            tmp = board[0][2][i];
            board[0][2][i] = board[4][2 - i][2];
            board[4][2 - i][2] = board[1][0][2 - i];
            board[1][0][2 - i] = board[5][i][0];
            board[5][i][0] = tmp;
        }
    }
    else {
        for (int i = 0; i < 3; i++) {
            tmp = board[0][2][i];
            board[0][2][i] = board[5][i][0];
            board[5][i][0] = board[1][0][2 - i];
            board[1][0][2 - i] = board[4][2 - i][2];
            board[4][2 - i][2] = tmp;
        }
    }
}

void    rotateBack(char direction) {
    int tmp;
    if (direction == '+') {
        for (int i = 0; i < 3; i++) {
            tmp = board[0][0][i];
            board[0][0][i] = board[5][i][2];
            board[5][i][2] = board[1][2][2 - i];
            board[1][2][2 - i] = board[4][2 - i][0];
            board[4][2 - i][0] = tmp;
        }
    }
    else {
        for (int i = 0; i < 3; i++) {
            tmp = board[0][0][i];
            board[0][0][i] = board[4][2 - i][0];
            board[4][2 - i][0] = board[1][2][2 - i];
            board[1][2][2 - i] = board[5][i][2];
            board[5][i][2] = tmp;
        }
    }
}

void    rotateLeft(char direction) {
    int tmp;
    if (direction == '+') {
        for (int i = 0; i < 3; i++) {
            tmp = board[0][i][0];
            board[0][i][0] = board[3][2 - i][2];
            board[3][2 - i][2] = board[1][i][0];
            board[1][i][0] = board[2][i][0];
            board[2][i][0] = tmp;
        }
    }
    else {
        for (int i = 0; i < 3; i++) {
            tmp = board[0][i][0];
            board[0][i][0] = board[2][i][0];
            board[2][i][0] = board[1][i][0];
            board[1][i][0] = board[3][2 - i][2];
            board[3][2 - i][2] = tmp;
        }
    }
}

void    rotateRight(char direction) {
    int tmp;
    if (direction == '+') {
        for (int i = 0; i < 3; i++) {
            tmp = board[0][i][2];
            board[0][i][2] = board[2][i][2];
            board[2][i][2] = board[1][i][2];
            board[1][i][2] = board[3][2 - i][0];
            board[3][2 - i][0] = tmp;
        }
    }
    else {
        for (int i = 0; i < 3; i++) {
            tmp = board[0][i][2];
            board[0][i][2] = board[3][2 - i][0];
            board[3][2 - i][0] = board[1][i][2];
            board[1][i][2] = board[2][i][2];
            board[2][i][2] = tmp;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> n;
    string input;
    char face, direction;
    for (int i = 1; i <= n; i++) {
        int cases;
        cin >> cases;
        initBoard();
        for (int j = 1; j <= cases; j++) {
            cin >> input;
            face = input[0];
            direction = input[1];
            if (face == 'U') rotateUpper(direction);
            else if (face == 'D') rotateLower(direction);
            else if (face == 'F') rotateFront(direction);
            else if (face == 'B') rotateBack(direction);
            else if (face == 'L') rotateLeft(direction);
            else if (face == 'R') rotateRight(direction);
            rotateOwnFace(face, direction);
        }
        for (int k = 0; k < 3; k++) {
            for (int l = 0; l < 3; l++) {
                cout << board[0][k][l];
            }
            cout << '\n';
        }
    }
}