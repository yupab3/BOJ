#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
// check is the node visited already
// check how many node visited

#define si pair<size_t, int>

bool                                            visit[1002];
vector<si>                                      node[1002];
size_t                                          ans;
int                                             n;

void    prim()
{
    priority_queue<si, vector<si>, greater<si> >    stock;
    for (auto trgt : node[1])
        stock.push(trgt);
    while (!stock.empty())
    {
        int     n_node = stock.top().second;
        size_t  n_cost = stock.top().first;
        // cout << n_cost << ", " << n_node << '\n';
        stock.pop();
        if (visit[n_node]) continue ;
        visit[n_node] = 1;
        ans += n_cost;
        for (auto trgt : node[n_node])
            if (!visit[trgt.second]) stock.push(trgt);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    int cost;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> cost;
            if (cost) node[i].push_back({cost, j});
        }
    }
    visit[1] = 1;
    prim();
    cout << ans << '\n';
    return (0);
}