#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int	visited[1001][1001] = {0, };
int a, b, c, sum;

int	bfs()
{
	queue<pair<int, int> >	q;
    q.push(make_pair(min(min(a, b), c), max(max(a, b), c)));
	visited[min(min(a, b), c)][max(max(a, b), c)] = 1;
	while (!q.empty())
	{
		int ca = q.front().first;
		int cb = q.front().second;
		int cc = sum - ca - cb;
		q.pop();
		if (ca == cb && cb == cc)
			return (1);
		int	n_a[3] = {ca, cb, cc};
		int n_b[3] = {cb, cc, ca};
		for (int i = 0; i < 3; i++)
		{
			int na = n_a[i];
			int nb = n_b[i];
			if (na < nb)
			{
				nb -= na;
				na += na;
			}
			else if (na > nb)
			{
				na -= nb;
				nb += nb;
			}
			else
				continue ;
			int nc = sum - na - nb;
			int	ra = min(min(na, nb), nc);
			int	rb = max(max(na, nb), nc);

			if (visited[ra][rb] == 0)
			{
				visited[ra][rb] = 1;
				q.push(make_pair(ra, rb));
			}
		}
	}
	return (0);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

    cin >> a >> b >> c;
    sum = a + b + c;
	if (sum % 3 != 0)
		cout << 0 << '\n';
	else
		cout << bfs() << '\n';
	return (0);
}