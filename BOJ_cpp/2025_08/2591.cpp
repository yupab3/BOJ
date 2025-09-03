#include <iostream>

using namespace std;

int dp[42];

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string input;
    cin >> input;
    dp[1] = 1;
    if ((input[0] - '0') * 10 + (input[1] - '0') <= 34 && input[1] - '0' != 0) dp[2] = 2;
    else dp[2] = 1;
    for (int i = 3; i <= input.size(); ++i) {
        if ((input[i - 2] - '0') != 0 && (input[i - 2] - '0') * 10 + (input[i - 1] - '0') <= 34) {
            dp[i] += dp[i - 2];
            if (input[i - 1] - '0' != 0) dp[i] += dp[i - 1];
        }
        else dp[i] = dp[i - 1];
    }
    cout << dp[input.size()] << '\n';
    return 0;
}