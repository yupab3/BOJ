#include <iostream>

using namespace std;

// 파괴를 일으킴 방향은 상하좌우, 거리도 주어짐
// 구슬을 앞으로 당김
// 4개 이상 연속되는 구슬은 폭발함
// 4개 이상 연속되는 구슬이 없을 때 까지 반복
// 남은 구슬을 그룹으로 묶고 1~3개짜리 그룹을 전부 2개짜리로 만듦, 이때 첫 번째 구슬은 그룹의 갯수를, 두 번째 구슬은 그룹을 구성하는 구슬의 숫자를 의미함

// 터지는 칸은 방향을 기준으로 달라지는데, 상 : +3, 하 : -1, 좌 : -3, 우 : +1
// 매 라운드 홀수 x 4 - 상하좌우값 이 더하며 계산된다.

int n, m, ans = 0;
int line[49 * 49 + 2];
int board[52][52];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int factor[4] = {3, -1, -3, +1};

bool explodeNum(int idx) {
    bool    excuted = false;
    int tmp, cnt = 1;
    for (int i = 1; i <= idx; i++) {
        tmp = i;
        if (line[i] != line[i + 1]) cnt = 1;
        while (line[tmp] != 0 && line[tmp] == line[tmp + 1]) {
            ++tmp;
            ++cnt;
        }
        if (cnt >= 4) {
            ans += line[i] * (tmp - i + 1);
            for (int j = i; j <= tmp; j++)
                line[j] = -1;
            i = tmp;
            excuted = true;
        }
        cnt = 1;
    }
    return excuted;
}

int pullNum(int idx) {
    int tmp, windowSize = 0;
    for (int i = 1; i <= idx; i++) {
        tmp = i;
        while (line[tmp++] == -1)
            ++windowSize;
        if (line[i] == -1) {
            for (int j = i; j <= idx - windowSize; j++)
                line[j] = line[j + windowSize];
            for (int j = idx - windowSize + 1; j <= idx; j++)
                line[j] = 0;
            idx -= windowSize;
        }
        windowSize = 0;
    }
    return idx;
}

int pushNum(int idx) {
    int subLine[49 * 49 + 2];
    int cnt = 1, subIdx = 1;
    for (int i = 1; i <= idx; i++) {
        if (line[i] == line[i + 1]) ++cnt;
        else {
            if (subIdx == n * n) break ;
            subLine[subIdx++] = cnt;
            if (subIdx == n * n) break ;
            subLine[subIdx++] = line[i];
            cnt = 1;
        }
    }
    for (int i = 1; i <= subIdx - 1; i++)
        line[i] = subLine[i];
    return subIdx;
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cin >> board[i][j];
    }
    int idx = 1;
    int cx = (n + 1) / 2;
    int cy = (n + 1) / 2;
    board[cx][cy] = 500;
    cy--;
    line[idx++] = board[cx][cy];
    cx++;
    line[idx++] = board[cx][cy];
    cy++;
    line[idx++] = board[cx][cy];
    ++cy;
    int gap = 3;
    while (board[cx][cy]) {
        ++cx;
        for (int i = 0; i < 4; i++) {
            for (int j = 1; j <= gap; j++) {
                cx = cx + dx[i];
                cy = cy + dy[i];
                if (cx < 1 || cy < 1 || n < cx || n < cy || board[cx][cy] == 0) break ;
                line[idx++] = board[cx][cy];
            }
            if (cx < 1 || cy < 1 || n < cx || n < cy || board[cx][cy] == 0) break ;
        }
        if (cx < 1 || cy < 1 || n < cx || n < cy || board[cx][cy] == 0) break ;
        ++cy;
        gap += 2;
    }
    idx--;
    int d, s;
    while (m--) {
        cin >> d >> s;
        int trgt = 0, windowSize = 0;
        for (int i = 1; i <= 2 * s - 1; i+=2) {
            trgt += factor[d - 1] + i * 4;
            line[trgt] = -1;
        }
        idx = pullNum(idx);
        while (explodeNum(idx))
            idx = pullNum(idx);
        idx = pushNum(idx);
    }
    cout << ans << '\n';
}