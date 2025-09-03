#include <iostream>
#include <vector>

using namespace std;

// 상하좌우 = 인접
// 1. 비어있는 칸 중에 인접한 칸에 좋아하는 학생이 많은 곳
// 2. 1이 많으면 그 중에 인접한 칸이 비어있는 칸이 가장 많은 곳
// 3. 2도 많으면 그 중에 행이 가장 위인 곳, 그것도 많으면 열이 가장 왼쪽인 곳

int n;
int board[22][22];
int score[22][22];
int vacant[22][22];
int favorite[402][4];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
vector<pair<int, int>> near[4];

void    printBoard() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << board[i][j] << ' ';
        } 
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> n;
    int num;
    for (int i = 1; i <= n * n; ++i) {
        cin >> num;
        fill(&score[0][0], &score[0][0] + 22 * 22, 0);
        fill(&vacant[0][0], &vacant[0][0] + 22 * 22, 0);
        for (int j = 0; j < 4; ++j)
            cin >> favorite[num][j];
        for (int j = 1; j <= n; ++j) {
            for (int k = 1; k <= n; ++k) {
                for (int l = 0; l < 4; ++l) {
                    for (int m = 0; m < 4; ++m) {
                        int nx = j + dx[m];
                        int ny = k + dy[m];
                        if (nx < 1 || n < nx || ny < 1 || n < ny) continue ;
                        if (favorite[num][l] == board[nx][ny])
                            ++score[j][k];
                    }
                }
                for (int l = 0; l < 4; ++l) {
                    int nx = j + dx[l];
                    int ny = k + dy[l];
                    if (nx < 1 || n < nx || ny < 1 || n < ny) continue ;
                    if (board[nx][ny] == 0)
                        ++vacant[j][k];
                }
            }
        }
        int bestScore = -1;
        int bestVacant = -1;
        int tx, ty;
        for (int j = 1; j <= n; ++j) {
            for (int k = 1; k <= n; ++k) {
                if (score[j][k] > bestScore) {
                    if (board[j][k]) continue ;
                    tx = j;
                    ty = k;
                    bestScore = score[j][k];
                    bestVacant = vacant[j][k];
                }
                else if (score[j][k] == bestScore && vacant[j][k] > bestVacant) {
                    if (board[j][k]) continue ;
                    tx = j;
                    ty = k;
                    bestVacant = vacant[j][k];
                }
            }
        }
        board[tx][ty] = num;
    }
    int ans = 0;
    for (int j = 1; j <= n; ++j) {
        for (int k = 1; k <= n; ++k) {
            int cnt = 0;
            for (int l = 0; l < 4; ++l) {
                for (int m = 0; m < 4; ++m) {
                    int nx = j + dx[m];
                    int ny = k + dy[m];
                    if (nx < 1 || n < nx || ny < 1 || n < ny) continue ;
                    if (favorite[board[j][k]][l] == board[nx][ny])
                        ++cnt;
                }
            }
            int cur = 0;
            if (cnt > 0) cur = 1;
            while (cnt > 1) {
                cur *= 10;
                --cnt;
            }
            ans += cur;
        }
    }
    cout << ans << '\n';
    return 0;
}