#include <iostream>
#include <string>
#include <tuple>
#include <map>

using 	namespace std;

int					board[200002];
int					id_count[200002];
map<string, int>	id_db;

int	u_find(int u)
{
	if (board[u] == u) return u;
	return board[u] = u_find(board[u]);
}

void	u_merge(int	su, int sv)
{
	int	u = u_find(su);
	int	v = u_find(sv);
	if (u == v) return ;
	if (u < v)
	{
		board[v] = u;
		id_count[u] += id_count[v];
	}
	else
	{
		board[u] = v;
		id_count[v] += id_count[u];
	}
}

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int	n, f;
	cin >> f;
	string	str1, str2;
	for (int i = 1; i <= f; i++)
	{
		int	init_id = 1;
		cin >> n;
		fill(id_count, id_count + n * 2 + 1, 1);
		for (int j = 1; j <= n; j++)
		{
			cin >> str1 >> str2;
			if (id_db.find(str1) == id_db.end())
			{
				id_db.insert({str1, init_id});
				board[init_id] = init_id;
				init_id++;
			}
			if (id_db.find(str2) == id_db.end())
			{
				id_db.insert({str2, init_id});
				board[init_id] = init_id;
				init_id++;
			}
			// cout << sns.size() << '\n';
			u_merge(id_db[str1], id_db[str2]);
			// u_find(str1);
			// cout << sns.size() << '\n';
			cout << id_count[u_find(id_db[str1])] << '\n';
		}
		id_db.clear();
		fill(board, board + n * 2 + 1, 0);
	}
}