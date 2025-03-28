#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> vec;
int board[502];

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> board[i];
    }
    int ans = 502;
    for (int k = 1; k < n; k++) {
        for (int i = k + 1; i <= n; i++) {
            int gab = board[i] - board[k];
            if (gab % (i - k) != 0) continue ;
            gab = gab / (i - k);
            int std_num = board[k];
            int cur_ans = 0;
            for (int j = 1; j <= n; j++) {
                if (board[j] != std_num + gab * (j - k)) cur_ans++;
            }
            ans = min(ans, cur_ans);
        }
    }
    cout << ans << '\n';
}