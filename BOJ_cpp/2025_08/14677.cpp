#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

// 주어지는 약을 순서대로 먹어야 한다.
// B -> L -> D 순서
// 앞에거 먹는 거, 뒤에거 먹는 거 각각 돌리기 

int n, ans = 0;
int dp[1502][1502];
char pill[1502];
char trgt[3] = {'B', 'L', 'D'};
queue<tuple<int, int, char, int>> q;

void    bfs() {
    while (q.size()) {
        auto [cl, cr, ctrgt, score] = q.front();
        q.pop();
        if (dp[cl][cr] >= score) continue ;
        dp[cl][cr] = max(dp[cl][cr], score);
        if (cl > cr) {
            ans = max(ans, score);
            break ;
        }
        if (pill[cl] != trgt[ctrgt] && pill[cr] != trgt[ctrgt]) {
            ans = max(ans, score);
            continue ;
        }
        if (pill[cl] == trgt[ctrgt]) q.push({cl + 1, cr, (ctrgt + 1) % 3, score + 1});
        if (pill[cr] == trgt[ctrgt]) q.push({cl, cr - 1, (ctrgt + 1) % 3, score + 1});
    }
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> n;
    string input;
    cin >> input;
    for (int i = 0; i < input.size(); ++i)
        pill[i + 1] = input[i];
    fill(&dp[0][0], &dp[0][0] + 1502 * 1502, -1);
    q.push({1, 3 * n, 0, 0});
    bfs();
    cout << ans << '\n';
    return 0;
}