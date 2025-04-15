#include <iostream>

using namespace std;

int n;
int board[1000002];
int score[1000002];

int findUnion(int u) {
    if (u == board[u]) return u;
    return board[u] = findUnion(board[u]);
}

void mergeUnion(int u, int v) {
    u = findUnion(u);
    v = findUnion(v);
    if (u < v) {
        board[v] = u;
        score[u] += score[v];
    }
    else if (v < u) {
        board[u] = v;
        score[v] += score[u];
    }
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    for (int i = 1; i <= 1000002; i++)
        board[i] = i;
    cin >> n;
    char mode;
    int a, b, c;
    fill(score, score + 1000002, 1);
    for (int i = 1; i <= n; i++) {
        cin >> mode;
        if (mode == 'I') {
            cin >> a >> b;
            mergeUnion(a, b);
        }
        else {
            cin >> c;
            cout << score[findUnion(c)] << '\n';
        }
    }
    // for (int i = 1; i <= 3; i++) 
    //     cout << "board[" << i << "] : " << board[i] << ", score[" << i << "] : " << score[i] << '\n';
    return 0;
}