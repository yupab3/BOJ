#include <iostream>
#include <algorithm>

using namespace std;

int n;
int board[100002];

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> board[i];
    sort(board + 1, board + n + 1, [](int a, int b){ return a > b; });
    int maxVal = board[1], cur = board[1];
    long ans = 0;
    for (int i = 2; i <= n; ++i) {
        if (cur) {
            if (cur < board[i]) {
                ans += cur;
                cur = 0;
            }
            else {
                ans += board[i];
                cur = cur - board[i];
            }
        }
        ans += board[i];
    }
    if (cur) ans += 1;
    cout << ans << '\n';
    return 0;
}