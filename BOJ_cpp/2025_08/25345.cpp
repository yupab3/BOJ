#include <iostream>

using namespace std;

// 입력을 정렬한 다음 N - (N - (0)) + 0번째를 뒤로 넘겼을 경우 N - (N - (0)) + 0 가지의 경우의 수가 가능함
// 입력을 정렬한 다음 N - (N - (1)) + 1 번째를 뒤로 넘겼을 경우 N - (N - (1)) 번째가 가지는 경우의 수가 가능함
// 입력을 정렬한 다음 N - (N - (N - 1)) + 1 번째를 뒤로 넘겼을 경우 N - (N - (N - 1)) 번째가 가지는 경우의 수가 가능함

// DP[1] = 1;
// DP[2] = DP[1] + 1;
// DP[3] = DP[2] + DP[1] + 1;
// DP[4] = DP[3] + DP[2] + DP[1] + 1;
// DP[5] = DP[4] + DP[3] + DP[2] + DP[1] + 1;

// dp[1] -> 1번째 값을 오른쪽 끝으로 옮겼을 때 만들 수 있는 경우의 수
// 2000까지 구해놓고
// n개 중에 k개 뽑는 가짓수만 구하면 끝 n C k

long    n, k, sum, dummy;
long    cases[2002][2002];
long    dp[2002];



int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> dummy;
    dp[1] = 1;
    for (int i = 2; i <= 2000; ++i) {
        sum += dp[i - 1] % 1000000007;
        dp[i] = (sum + 1) % 1000000007;
    }
    cases[1][0] = 1;
    cases[1][1] = 1;
    for (int i = 2; i <= 2000; ++i) {
        for (int j = 0; j <= i; ++j)
            cases[i][j] = (cases[i - 1][j - 1] + cases[i - 1][j]) % 1000000007;
    }
    cout << cases[n][k] * dp[k] % 1000000007 << '\n';
    return 0;
}