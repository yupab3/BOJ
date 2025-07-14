#include <iostream>
#include <queue>

using namespace std;

int n, m, dir = 3, x = 1, y = 1;
int board[1002][1002];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
queue<pair<int, int>> q;

void    printAns(int x, int y) {
    if (y < 1) cout << x << ' ';
    else if (n < x) cout << n + y << ' ';
    else if (m < y) cout << n + m + (n - x + 1) << ' ';
    else if (x < 1) cout << 2 * n + m + (m - y + 1) << ' ';
}

void    chgDir() {
    if (dir == 0) dir = 3;
    else if (dir == 3) dir = 0;
    else if (dir == 1) dir = 2;
    else dir = 1;
}

void    setXYDir(int cnt) {
    if (cnt <= n) {
        x = cnt;
        dir = 3;
        return ;
    }
    else x = n;
    cnt -= n;
    if (cnt <= m) {
        y = cnt;
        dir = 0;
        return ;
    }
    else y = m;
    cnt -= m;
    if (cnt <= n) {
        x = n - cnt + 1;
        dir = 2;
        return ;
    }
    else x = 1;
    cnt -= n;
    y = m - cnt + 1;
    dir = 1;
}

void    travel() {
    while (q.size()) {
        auto [cx, cy] = q.front();
        q.pop();
        if (board[cx][cy]) chgDir();
        int nx = cx + dx[dir];
        int ny = cy + dy[dir];
        if (nx < 1 || n < nx || ny < 1 || m < ny) {
            printAns(nx, ny);
            return ;
        }
        q.push({nx, ny});
    }
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr); 

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> board[i][j];
        }
    }

    for (int i = 1; i <= 2 * n + 2 * m; ++i) {
        setXYDir(i);
        // cout << "i : " << i << ", x : " << x << ", y : " << y << ", dir : " << dir << ", ans : ";
        q.push({x, y});
        travel();
    }
    return 0;
}