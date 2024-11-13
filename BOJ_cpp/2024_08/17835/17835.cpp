#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define tt  pair<size_t, size_t>

priority_queue<tt, vector<tt>, greater<tt> >  q;
vector<tt>  node[100002];
size_t      d[100002];
int         n, m, k;

void    Dijkstra()
{
    while (q.size())
    {
        auto [cost, from] = q.top();
        q.pop();
        if (d[from] < cost) continue ;
        for(auto next : node[from])
        {
            int dest = next.second;
            int d_cost = next.first;
            if (d[dest] < d_cost + d[from]) continue ;
            // cout << cost << ", " << from << " -> " << dest << ", " << d_cost + d[from] << '\n';
            d[dest] = d_cost + d[from];
            q.push({d[dest], dest});
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    size_t from, to, cost;
    fill(&d[0], &d[100002], 1e15);
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        cin >> from >> to >> cost;
        node[to].push_back({cost, from});
    }
    for (int i = 0; i < k; i++)
    {
        cin >> from;
        d[from] = 0;
        q.push({0, from});
    }
    Dijkstra();
    size_t ans, tmp = 0;
    for (int i = 1; i <= n; i++)
    {
        if (tmp < d[i])
        {
            tmp = d[i];
            ans = i;
        }
    }
    cout << ans << '\n' << d[ans] << '\n';
    return (0);
}