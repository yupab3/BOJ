#include <iostream>
#include <queue>
#include <utility>
using namespace std;

char board[1002][1002];
int dist_J[1002][1002];
int dist_F[1002][1002];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int R, C, ans = 20000000;

int main(void){
    queue<pair<int, int> > J;
    queue<pair<int, int> > F;
    cin >> R >> C;

    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            cin >> board[i][j];
            if (board[i][j] == 'F'){
                F.push({i, j});
                dist_F[i][j] = 1;
            }
            else if (board[i][j] == 'J'){
                J.push({i, j});
                dist_J[i][j] = 1;
            }
        }
    }
    while (!F.empty())
    {
        auto cur = F.front(); F.pop();
        for (int dir = 0; dir < 4; dir++){
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if (dist_F[nx][ny] >= 1 || board[nx][ny] == '#') continue;
            dist_F[nx][ny] = dist_F[cur.first][cur.second] + 1;
            F.push({nx,ny});
        }
    }
    while (!J.empty())
    {
        auto cur = J.front(); J.pop();
        for (int dir = 0; dir < 4; dir++){
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C){
                cout << dist_J[cur.first][cur.second];
                return (0);
            }
            if (dist_J[nx][ny] >= 1 || board[nx][ny] == '#') continue;
            if (dist_F[nx][ny] != 0 && dist_J[cur.first][cur.second] + 1 >= dist_F[nx][ny]) continue;
            dist_J[nx][ny] = dist_J[cur.first][cur.second] + 1;
            J.push({nx,ny});
        }
    }
    cout << "IMPOSSIBLE";
}
