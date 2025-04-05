#include <iostream>

using namespace std;

int board[100002];
int diff[100002];

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> board[i];
    if (n <= 2) {
        cout << "0\n";
        return 0;
    }
    int ans = 1e9 + 2;
    for (int i = board[1] - 1; i <= board[1] + 1; i++) {
        for (int j = board[2] - 1; j <= board[2] + 1; j++) {
            int diff = i - j;
            int cur = 0;
            for (int k = 1; k <= n; k++) {
                if (abs(board[k] - (i - diff * (k - 1))) > 1) {
                    cur = 1e9 + 2;
                    break ;
                }
                else if (board[k] - (i - diff * (k - 1)) != 0)
                    cur++;
            }
            ans = min(ans, cur);
        }
    }
    if (ans == 1e9 + 2) cout << "-1\n";
    else cout << ans << '\n';
    return 0;
}
// 차이를 저장해둠
// a를 키우면 
// 차이가 2이상 차이나면 애초에 불가능
// 1만큼 차이나는 애들만 세주면 된다.
// 2일때 1차이 OK 3차이 OK 1이랑 3 만나도 ㄱㅊ 근데 0이랑 3차이 있으면 불가능
