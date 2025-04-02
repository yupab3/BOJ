#include <iostream>
#include <deque>

using namespace std;

string  ans, str1, str2;
int     board[42][42];

void    checkPos(int i1) {
    for (int i2 = 1; i2 <= str2.length(); i2++) {
        if (str1[i1 - 1] == str2[i2 - 1]) board[i1][i2] = board[i1 - 1][i2 - 1] + 1;
        else board[i1][i2] = max(board[i1 - 1][i2], board[i1][i2 - 1]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    cin >> str1 >> str2;
    deque<char> dq;

    for (int i = 1; i <= str1.length(); i++) checkPos(i);
    int i1 = str1.length();
    int i2 = str2.length();
    while (board[i1][i2]) {
        while (board[i1 - 1][i2] == board[i1][i2]) i1--;
        while (board[i1][i2 - 1] == board[i1][i2]) i2--;
        dq.push_back(str1[i1 - 1]);
        i1--;
        i2--;
    }
    while (dq.size()) {
        cout << dq.back();
        dq.pop_back();
    }
}

// AUTABBEHNSA
// BCUAMEFKAJNA