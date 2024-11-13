#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int board[1002][1002];
int day[1002][1002];
int N, M;
int dx[4] = {1, 0, -1 , 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
    queue<pair<int, int> > Q;
    cin >> M >> N;
    for (int x = 0; x < N; x++){
        for (int y = 0; y < M; y++){
            cin >> board[x][y];
            if (board[x][y] == 1){
                Q.push({x, y});
            }
            if (board[x][y] == 0){
                day[x][y] = -1;
            }
        }
    }
    while (!Q.empty()){
        auto cur = Q.front();
        Q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M){
                continue;
            }
            if (day[nx][ny] >= 0){
                continue;
            }
            day[nx][ny] = day[cur.first][cur.second] + 1;
            Q.push({nx,ny});
        }
    }
    int ans = 0;
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < M; y++)
        {
            if (day[x][y] == -1){
                cout << "-1";
                return 0;
            }
            ans = max(ans, day[x][y]);
        }
    }
    cout << ans;
}