#include <iostream>
#include <set>

using namespace std;

// 물고기는 고유한 번호, 중복되는 방향으로 구성

// 1. 상어가 (0,0)에 있는 물고기 먹고 그 자리에서 시작

// 2. 낮은 번호부터 이동, 8방향, 이동 불가능한 구역은 상어가 있거나 경계 바깥쪽
// 3. 불가능한 경우 반시계 방향으로 45도 회전, 따라서 이동은 8방향, 이동은 서로의 위치를 교환하는 것, 8방향 모두 불가하면 이동 불가

// 물고기 이동 끝나면 상어 이동

// 4. 상어는 정해진 방향으로만 이동 가능, 먹으면 물고기의 방향으로 바뀜, 방향 내에 먹을 수 있는 물고기 없으면 ans max값 계산 후 탈출
// 2 ~ 4 반복

int ans = 0;
int sea[6][6];
int dir[18];
set<int> fishes;
int fx[18];
int fy[18];
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};

void    printSea() {
    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= 4; ++j)
            cout << sea[i][j] << ' ';
        cout << '\n';
    }
}

void    swapFish(int x1, int y1, int x2, int y2) {
    int tmpNum = sea[x1][y1];
    int tx = x1;
    int ty = y1;
    fx[sea[x1][y1]] = x2;
    fy[sea[x1][y1]] = y2;
    sea[x1][y1] = sea[x2][y2];
    fx[sea[x2][y2]] = tx;
    fy[sea[x2][y2]] = ty;
    sea[x2][y2] = tmpNum;
}

void    moveFishes(int sx, int sy) {
    for (int fish : fishes) {
        int fDir = dir[fish];
        int cx = fx[fish];
        int cy = fy[fish];
        int nx = cx + dx[fDir];
        int ny = cy + dy[fDir];
        bool    check = false;
        // cout << "fish : " << fish << ", cur : (" << cx << ", " << cy << "), ";
        while (nx < 1 || 4 < nx || ny < 1 || 4 < ny || (nx == sx && ny == sy)) {
            check = true ;
            dir[fish] = (dir[fish] + 1) % 8;
            nx = cx + dx[dir[fish]];
            ny = cy + dy[dir[fish]];
            if (dir[fish] == fDir) break ;
        }
        // cout << "next : (" << nx << ", " << ny << ")\n";
        if (check && dir[fish] == fDir) continue ;
        // cout << "dir[fish] : " << dir[fish] << ", fDir : " << fDir << '\n';
        // cout << "------ bf move ------\n";
        // printSea();
        swapFish(cx, cy, nx, ny);
        // cout << "------ af move ------\n";
        // printSea();
    }
}

void dfs(int sDir, int cnt, int sx, int sy) {
    // cout << "------ bf move ------\n";
    // printSea();
    moveFishes(sx, sy);
    int tmpDir[18];
    int tmpFx[18];
    int tmpFy[18];
    for (int i = 1; i <= 16; ++i) {
        tmpDir[i] = dir[i];
        tmpFx[i] = fx[i];
        tmpFy[i] = fy[i];
    }
    int tmpSea[6][6];
    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= 4; ++j)
            tmpSea[i][j] = sea[i][j];
    }
    // cout << "------ af move ------\n";
    // printSea();
    for (int i = 1; i <= 3; ++i) {
        int nsx = sx + i * dx[sDir];
        int nsy = sy + i * dy[sDir];
        // cout << "s : (" << sx << ", " << sy << "), ns : (" << nsx << ", " << nsy << "), i : " << i << ", dir : " << sDir << "\n";
        if (nsx < 1 || 4 < nsx || nsy < 1 || 4 < nsy) break ;
        if (sea[nsx][nsy] == 0) continue ;
        int bf = sea[nsx][nsy];
        sea[nsx][nsy] = 0;
        // cout << "Eat : " << bf << '\n';
        fishes.erase(bf);
        dfs(dir[bf], cnt + bf, nsx, nsy);
        for (int i = 1; i <= 16; ++i) {
            dir[i] = tmpDir[i];
            fx[i] = tmpFx[i];
            fy[i] = tmpFy[i];
        }
        for (int i = 1; i <= 4; ++i) {
            for (int j = 1; j <= 4; ++j)
                sea[i][j] = tmpSea[i][j];
        }
        fishes.insert(bf);
    }
    // cout << ans << ", " << cnt << '\n';
    ans = max(cnt, ans);
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int num;
    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= 4; ++j) {
            cin >> num >> dir[num];
            --dir[num];
            sea[i][j] = num;
            fx[num] = i;
            fy[num] = j;
            fishes.insert(num);
        }
    }
    int init = sea[1][1];
    sea[1][1] = 0;
    fishes.erase(init);
    dfs(dir[init], init, 1, 1);
    cout << ans << '\n';
    return 0;
}