#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
#define ii pair<int, int>

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    queue<ii>   q;
    int n, m, t, gram = 1000000;
    cin >> n >> m >> t;
    int map[105][105];
    int mx[4] = {-1, 1, 0, 0};
    int my[4] = {0, 0, -1, 1};
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cin >> map[i][j];
    }
    int chk[105][105];
    memset(chk, -1, sizeof(int) * 105 * 105);
    chk[1][1] = 0;
    if (map[1][1] == 2)
        gram = (n - 1) + (m - 1);
    q.push({1, 1});
    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = cx + mx[i];
            int ny = cy + my[i];
            if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
            if (chk[nx][ny] != -1 || map[nx][ny] == 1) continue;
            chk[nx][ny] = chk[cx][cy] + 1;
            if (map[nx][ny] == 2)
                gram = chk[nx][ny] + (n - nx) + (m - ny);
            q.push({nx, ny});
        }
    }
    if (gram != 1000000 && chk[n][m] == -1)
        chk[n][m] = gram;
    else
        chk[n][m] = min(gram, chk[n][m]);
    if (chk[n][m] == -1 || chk[n][m] > t)
        cout << "Fail\n";
    else
        cout << chk[n][m] << '\n';
}