#include <iostream>

using namespace std;

// 토네이도가 이동한 곳에 있는 모래를 진행 방향으로 55% 이동시킴 나머지는 비율 맞춰서 이동
// 계산에서 소수점 아래는 버린다
// 모래가 격자 밖으로 나갈 수 있다. 격자 밖으로 나간 모래의 총량을 구하자.

// 좌 하 우 상 순으로 움직이며 우, 상으로 이동한 뒤에 이동거리를 1 늘린다.

int n;
int dist = 1, dir = 0, ans;
int A[502][502]; // 모래의 양
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

void    printA() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << A[i][j] << ' ';
        }
        cout << '\n';
    }
}

int    dust(int x, int y, int mount) {
    if (x < 1 || n < x || y < 1 || n < y) return mount;
    A[x][y] += mount;
    return mount;
}

void    tornado(int x, int y, int mount) {
    int cur = 0;
    cur += dust(x + dx[dir] * 2, y + dy[dir] * 2, mount * 5 / 100);
    cur += dust(x + dx[dir] + dx[(dir + 1) % 4], y + dy[dir] + dy[(dir + 1) % 4], mount / 10);
    cur += dust(x + dx[dir] + dx[(dir + 3) % 4], y + dy[dir] + dy[(dir + 3) % 4], mount / 10);
    cur += dust(x + dx[(dir + 1) % 4], y + dy[(dir + 1) % 4], mount * 7 / 100);
    cur += dust(x + dx[(dir + 3) % 4], y + dy[(dir + 3) % 4], mount * 7 / 100);
    cur += dust(x + dx[(dir + 1) % 4] * 2, y + dy[(dir + 1) % 4] * 2, mount * 2 / 100);
    cur += dust(x + dx[(dir + 3) % 4] * 2, y + dy[(dir + 3) % 4] * 2, mount * 2 / 100);
    cur += dust(x - dx[dir] + dx[(dir + 1) % 4], y - dy[dir] + dy[(dir + 1) % 4], mount / 100);
    cur += dust(x - dx[dir] + dx[(dir + 3) % 4], y - dy[dir] + dy[(dir + 3) % 4], mount / 100);
    cur += dust(x + dx[dir], y + dy[dir], mount - cur);
}

void    move(int &x, int &y) {
    for (int i = 1; i <= dist; ++i) {
        x = x + dx[dir];
        y = y + dy[dir];
        if (x == 1 && y == 0) break ;
        tornado(x, y, A[x][y]);
        A[x][y] = 0;
    }
    if (dir & 1) ++dist;
    dir = (dir + 1) % 4;
}

int countDust() {
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)
            sum += A[i][j];
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)
            cin >> A[i][j];
    }
    ans = countDust();
    int x = n / 2 + 1;
    int y = x;
    while (x != 1 || y != 0) {
        move(x, y);
    }
    ans -= countDust();
    cout << ans << '\n';
    return 0;
}