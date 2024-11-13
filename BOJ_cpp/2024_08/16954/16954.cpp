#include <iostream>
#include <string>
#include <queue>

using namespace std;

#define ii pair<int, int>

queue<ii>	q;

char	board[10][10];
int		dx[9] = {1, 1, 1, 0, -1, -1, -1, 0, 0};
int 	dy[9] = {-1, 0, 1, 1, 1, 0, -1, -1, 0};
bool	result = false;

void	bfs()
{
	while (q.size())
	{
		auto [cx, cy] = q.front();
		q.pop();
		// cout << cx << ", " << cy << '\n'; 
		if (cx == -1 && cy == -1)
		{
			for (int i = 8; i > 1; i--)
			{
				for (int j = 1; j <= 8; j++)
					board[i][j] = board[i - 1][j];
			}
			for (int i = 1; i <= 8; i++)
				board[1][i] = '.';
			// for (int i = 1; i <= 8; i++)
			// {
			// 	for (int j = 1; j <= 8; j++)
			// 		cout << board[i][j];
			// 	cout << '\n';
			// }
			if (q.size())
				q.push({-1, -1});
			continue ;
		}
		if (cx == 1 && cy == 8){
			result = true;
			break ;
		}
		if (board[cx][cy] == '#') 
		{
			// cout << "user in #\n";
			continue ;
		}
		for (int i = 0; i < 9; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 1 || 8 < nx || ny < 1 || 8 < ny) continue ;
			if (board[nx][ny] == '#') continue ;
			q.push({nx, ny});
		}
	}
}

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	for (int i = 1; i <= 8; i++)
	{
		string str;
		cin >> str;
		for (int j = 1; j <= 8; j++)
			board[i][j] = str[j - 1];
	}
	q.push({8, 1});
	q.push({-1, -1});
	bfs();
	cout << result << '\n';
	return (0);
}