#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int	box[102][102][102];
int	day[102][102][102];
int	dx[6] = {1, 0, 0, -1, 0, 0};
int	dy[6] = {0, 1, 0, 0, -1, 0};
int	dz[6] = {0, 0, 1, 0, 0, -1};
int	ans;

int	main(void){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int	M, N, H;
	queue<tuple<int, int, int> > Q;

	cin >> M >> N >> H;
	for (int i = 0; i < H; i++){
		for (int j = 0; j < N; j++){
			for (int k = 0; k < M; k++){
				cin >> box[i][j][k];
				if (box[i][j][k] == 1) Q.push({i, j, k});
			}
		}
	}
	while (!Q.empty()){
		auto cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 6; dir++){
			int nx = get<1>(cur) + dx[dir];
			int ny = get<2>(cur) + dy[dir];
			int nz = get<0>(cur) + dz[dir];
			if (nx < 0 || ny < 0 || nz < 0 || nx >= N || ny >= M || nz >= H) continue;
			if (box[nz][nx][ny] != 0) continue;
			day[nz][nx][ny] = day[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
			box[nz][nx][ny] = 1;
			Q.push({nz, nx, ny});
		}
	}
	for (int i = 0; i < H; i++){
		for (int j = 0; j < N; j++){
			for (int k = 0; k < M; k++){
				if (box[i][j][k] == 0){
					cout << "-1";
					return 0;
				}
				if (box[i][j][k] == 1){
					ans = max(ans, day[i][j][k]);
				}
			}
		}
	}
	cout << ans;
}