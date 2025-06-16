#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n, k, gap = 1e9, h, w;
int tmp[102][102];
int rotTank[102][102];
int tank[102][102];
int chg[102][102];
bool    vis[102][102];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
queue<pair<int, int>> q;

void    bfs() {
    while (q.size()) {
        auto [cx, cy] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx < 1 || n < nx || ny < 1 || n < ny) continue ;
            if (!tank[nx][ny]) continue ;
            if ((tank[nx][ny] - tank[cx][cy]) / 5) chg[cx][cy] += (tank[nx][ny] - tank[cx][cy]) / 5;
            if (vis[nx][ny]) continue ;
            vis[nx][ny] = true;
            q.push({nx, ny});
        }
    }
}

bool    checkTank() {
    for (int i = 1; i <= n; i++) {
        if (tank[i][1]) h = i;
        if (tank[h][i]) w = i;
    }
    if (w > h) w = h;
    fill(&rotTank[0][0], &rotTank[0][0] + 102 * 102 - 1, 0);
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++)
            rotTank[i][j] = tank[i][j];
    }
    if (tank[1][w + h]) return true;
    return false;
}

void    applyChg() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            tank[i][j] += chg[i][j];
    }
    fill(&chg[0][0], &chg[0][0] + 102 * 102 - 1, 0);
}

void    moveTank() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 && j <= n - w) tank[i][j] = tank[i][j + w];
            else tank[i][j] = 0;
        }
    }
}

void    setTmp() {
    fill(&tmp[0][0], &tmp[0][0] + 102 * 102 - 1, 0);
    for (int i = 1; i <= (h + 1) / 2; i++) {
        for (int j = i; j <= h; j++) {
            tmp[i][j] = rotTank[j][h - i + 1];
            tmp[h - j + 1][i] = rotTank[i][j];
            tmp[h - i + 1][h - j + 1] = rotTank[h - j + 1][i];
            tmp[j][h - i + 1] = rotTank[h - i + 1][h - j + 1];
        }
    }
    for (int i = 1; i <= h; i++) {
        if (!tmp[1][i]) {
            for (int j = 1; j <= h; j++)
                tmp[j][i] = tmp[j + 1][i];
        }
    }
}

void    setTank() {
    for (int i = 1; i <= w; i++) {
        for (int j = 1; j <= h; j++)
            tank[i + 1][j] = tmp[i][j];
    }
}

void    stackTank() {
    setTmp();
    moveTank();
    setTank();
}

int checkGap() {
    int bigOne = 0;
    int smallOne = 1e9;
    for (int i = 1; i <= n; i++) {
        bigOne = max(bigOne, tank[1][i]);
        smallOne = min(smallOne, tank[1][i]);
    }
    return bigOne - smallOne;
}

void    straightenTank() {
    int newTank[102];
    fill(newTank, newTank + 102, 0);
    int idx = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            if (tank[j][i]) newTank[idx++] = tank[j][i];
    }
    fill(&tank[0][0], &tank[0][0] + 102 * 102 - 1, 0);
    for (int i = 1; i <= n; i++)
        tank[1][i] = newTank[i];
}

void    splitTank() {
    fill(&tmp[0][0], &tmp[0][0] + 102 * 102 - 1, 0);
    for (int i = 1; i <= n / 2; i++)
        tmp[1][i] = tank[1][n / 2 - i + 1];
    for (int i = 1; i <= n; i++) {
        if (i <= n / 2) tank[1][i] = tank[1][n / 2 + i];
        else tank[1][i] = 0;
        tank[2][i] = tmp[1][i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 2; j++) {
            if (i <= n / 4) tmp[j][i] = tank[2 - j + 1][n / 4 - i + 1];
            else tmp[j][i] = 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (i <= n / 4) {
            tank[1][i] = tank[1][n / 4 + i];
            tank[2][i] = tank[2][n / 4 + i];
        }
        else {
            tank[1][i] = 0;
            tank[2][i] = 0;
        }
        tank[3][i] = tmp[1][i];
        tank[4][i] = tmp[2][i];
    }
}

void    addFish() {
    int smallOne = 1e9;
    for (int i = 1; i <= n; i++) {
        smallOne = min(tank[1][i], smallOne);
    }
    for (int i = 1; i <= n; i++) {
        if (smallOne == tank[1][i]) tank[1][i]++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> tank[1][i];
    int t = 0;
    while (checkGap() > k) {
        addFish();
        while (checkTank())
            stackTank();
        q.push({1, 1});
        fill(&vis[0][0], &vis[0][0] + 102 * 102 - 1, false);
        vis[1][1] = true;
        bfs();
        applyChg();
        straightenTank();
        splitTank();
        q.push({1, 1});
        fill(&vis[0][0], &vis[0][0] + 102 * 102 - 1, false);
        vis[1][1] = true;
        bfs();
        applyChg();
        straightenTank();
        t++;
    }
    cout << t;
}