#include <iostream>
#include <vector>

using namespace std;

int n, m, k;
vector<int> req[100002];
int disable[100002];
int board[100002];

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        req[x].push_back(y);
        disable[y]++;
    }
    bool isLier = false;
    for (int i = 1; i <= k; i++) {
        int action, trgt;
        cin >> action >> trgt;
        if (action == 1) {
            if (disable[trgt] > 0) isLier = true;
            for (int sub : req[trgt])
                disable[sub]--;
            board[trgt]++;
        }
        else {
            if (board[trgt] == 0) isLier = true;
            board[trgt]--;
        }
    }
    if (isLier) cout << "Lier!\n";
    else cout << "King-God-Emperor\n";
    return 0;
}