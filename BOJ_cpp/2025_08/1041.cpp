#include <iostream>
#include <vector>

using namespace std;

bool    vis[7];

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long n;
    long dice[7];
    cin >> n;
    for (int i = 1; i <= 6; ++i)
        cin >> dice[i];
    long minOne = 1e9, minTwo = 1e9, minThree = 1e9, minFive = 1e9;
    for (int i = 1; i <= 6; ++i) {
        minOne = min(minOne, dice[i]);
        vis[i] = true;
        for (int j = 1; j <= 6; ++j) {
            if (vis[j] || i + j == 7) continue ;
            minTwo = min(minTwo, dice[i] + dice[j]);
            vis[j] = true;
            for (int k = 1; k <= 6; ++k) {
                if (vis[k] || i + k == 7 || j + k == 7) continue ;
                minThree = min(minThree, dice[i] + dice[j] + dice[k]);
                vis[k] = true;
                for(int l = 1; l <= 6; ++l) {
                    if (vis[l] || i + l == 7) continue ;
                    vis[l] = true;
                    for(int m = 1; m <= 6; ++m) {
                        if (vis[m] || i + m == 7) continue ;
                        minFive = min(minFive, dice[i] + dice[j] + dice[k] + dice[l] + dice[m]);
                    }
                    vis[l] = false;
                }
                vis[k] = false;
            }
            vis[j] = false;
        }
        vis[i] = false;
    }
    // cout << "minOne : " << minOne << ", minTwo : " << minTwo << ", minThree : " << minThree << ", minFive : " << minFive << '\n';
    if (n == 1) {
        cout << minFive << '\n';
        return 0;
    }
    long ans = minThree * 4L + minTwo * 4L + minTwo * (n - 2) * 8L + minOne * (n - 1) * (n - 2) * 4L + minOne * (n - 2) * (n - 2);
    cout << ans << '\n';
    return 0;
}