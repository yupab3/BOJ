#include <iostream>
#include <string>

using namespace std;

int n, ans;
char trgt[3] = {'B', 'L', 'D'};
int pill[1502][1502];
string input;

void    dfs(int st, int en, int cnt, char trgtNum) {
    if (st > en) {
        ans = max(ans, cnt);
        return ;
    }
    if (pill[st + 1][en] == 0 && input[st] == trgt[trgtNum]) {
        dfs(st + 1, en, cnt + 1, (trgtNum + 1) % 3);
        pill[st + 1][en] = cnt + 1;
    }
    if (pill[st][en - 1] == 0 && input[en] == trgt[trgtNum]) {
        dfs(st, en - 1, cnt + 1, (trgtNum + 1) % 3);
        pill[st][en - 1] = cnt + 1;
    }
    ans = max(pill[st + 1][en], pill[st][en - 1]);
    return ;
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> n >> input;
    dfs(0, input.size() - 1, 0, 0);
    cout << ans << '\n';
}