#include <iostream>
#include <queue>
#include <utility>
using namespace std;

queue<pair<int, int> > Q;
string	board[102];
bool	rg_b[102][102];
bool	r_g_b[102][102];
int		dx[4] = {1, 0, -1 ,0};
int		dy[4] = {0, 1, 0, -1};
int		count_rg_b, count_r_g_b;

int	main(void)
{
	int	N;
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> board[i];
	}
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (rg_b[i][j] == 0){
				Q.push({i, j});
				rg_b[i][j] = 1;
				count_rg_b++;
			}
			while (!Q.empty())
			{
				auto cur = Q.front(); Q.pop();
				for (int dir = 0; dir < 4; dir++){
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];
					if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
					if (rg_b[nx][ny] == 1) continue;
					if ((board[cur.first][cur.second] != 'B' && board[nx][ny] == 'B')
						|| (board[cur.first][cur.second] == 'B' && board[nx][ny] != 'B')) continue;
					rg_b[nx][ny] = 1;
					Q.push({nx, ny});
				}
			}
			if (r_g_b[i][j] == 0){
				Q.push({i, j});
				r_g_b[i][j] = 1;
				count_r_g_b++;
			}
			while (!Q.empty())
			{
				auto cur = Q.front(); Q.pop();
				for (int dir = 0; dir < 4; dir++){
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];
					if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
					if (r_g_b[nx][ny] == 1) continue;
					if ((board[cur.first][cur.second] == 'B' && board[nx][ny] == 'B')
					|| (board[cur.first][cur.second] == 'G' && board[nx][ny] == 'G')
					|| (board[cur.first][cur.second] == 'R' && board[nx][ny] == 'R')){
						r_g_b[nx][ny] = 1;
						Q.push({nx, ny});
					}
				}
			}
		}
	}
	cout << count_r_g_b << ' ' << count_rg_b;
}