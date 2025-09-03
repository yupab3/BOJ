#include <iostream>
#include <algorithm>

using namespace std;

int ans = 1e9;
int team[6];
int input[14];
bool    vis[14];

int getIdx() {
    for (int i = 1; i <= 12; ++i)
        if (vis[i] == false) return i;
    return 1;
}

void    dfs(int depth, int teamnum) {
    if (depth == 13) {
        for (int i = 1; i <= 4; ++i) {
            for (int j = i + 1; j <= 4; ++j)
                ans = min(ans, abs(team[i] - team[j]));
        }
        return ;
    }
    cout << "I'm " << depth << ", my start idx : " << getIdx() << '\n';
    for (int i = getIdx(); i <= 12; ++i) {
        team[teamnum] += input[i];
        vis[i] = true ;
        if (depth % 3 == 0) dfs(depth + 1, teamnum + 1);
        else dfs(depth + 1, teamnum);
        vis[i] = false ;
        team[teamnum] -= input[i];
    }
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    for (int i = 1; i <= 12; ++i )
        cin >> input[i];
    dfs(1, 1);
    cout << ans << '\n';
    return 0;
}