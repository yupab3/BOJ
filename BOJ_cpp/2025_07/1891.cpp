#include <iostream>
using namespace std;

long d, x, y, error;
int pos[52];

void    chgPosX(int trgt, int gap) {
    if (trgt == 0) {
        error = 1;
        return ;
    }
    if (gap < 0) {
        if (pos[trgt] == 2) {
            pos[trgt] = 1;
            chgPosX(trgt - 1, gap);
        }
        else if (pos[trgt] == 3) {
            pos[trgt] = 4;
            chgPosX(trgt - 1, gap);
        }
        else if (pos[trgt] == 1) pos[trgt] = 2;
        else pos[trgt] = 3;
    }
    else if (gap > 0){
        if (pos[trgt] == 1) {
            pos[trgt] = 2;
            chgPosX(trgt - 1, gap);
        }
        else if (pos[trgt] == 4) {
            pos[trgt] = 3;
            chgPosX(trgt - 1, gap);
        }
        else if (pos[trgt] == 2) pos[trgt] = 1;
        else pos[trgt] = 4;
    }
}

void    chgPosY(int trgt, int gap) {
    if (trgt == 0) {
        error = 1;
        return ;
    }
    if (gap < 0) {
        if (pos[trgt] == 3) {
            pos[trgt] = 2;
            chgPosY(trgt - 1, gap);
        }
        else if (pos[trgt] == 4) {
            pos[trgt] = 1;
            chgPosY(trgt - 1, gap);
        }
        else if (pos[trgt] == 1) pos[trgt] = 4;
        else pos[trgt] = 3;
    }
    else if (gap > 0) {
        if (pos[trgt] == 1) {
            pos[trgt] = 4;
            chgPosY(trgt - 1, gap);
        }
        else if (pos[trgt] == 2) {
            pos[trgt] = 3;
            chgPosY(trgt - 1, gap);
        }
        else if (pos[trgt] == 3) pos[trgt] = 2;
        else pos[trgt] = 1;
    }
}

void    printNum() {
    for (int i = 1; i <= d; ++i)
        cout << pos[i];
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string input;
    cin >> d >> input;
    for (int i = 1; i <= d; ++i)
        pos[i] = input[i - 1] - '0';
    cin >> x >> y;
    long share, remain;
    for (int i = d; i >= 1; --i) {
        share = x / 2;
        remain = x % 2;
        chgPosX(i, remain);
        share = y / 2;
        remain = y % 2;
        chgPosY(i, remain);
        x = x / 2;
        y = y / 2;
        if (x == 0 && y == 0) break ;
    }
    if (error == 1 || x > 0 || y > 0) cout << "-1\n";
    else {
        for (int i = 1; i <= d; ++i) {
            cout << pos[i];
        }
        cout << '\n';
    }
}