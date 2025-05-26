#include <iostream>

using namespace std;

int n;
string input;
string str[52];
int dp[52];
int alpCur[255];
int alpTrgt[255];

void dynamic() {
    for (int i = 1; i <= input.length(); i++) {
        for (int j = 1; j <= n; j++) {
            fill(alpCur, alpCur + 255, 0);
            fill(alpTrgt, alpTrgt + 255, 0);
            if (i < str[j].length()) continue ;
            int cnt = 0;
            for (int k = 0; k < str[j].length(); k++) {
                if (input[i - str[j].length() + k] != str[j][k]) cnt++;
                alpCur[input[i - str[j].length() + k]]++;
                alpTrgt[str[j][k]]++;
            }
            bool invalid = false;
            for (int k = 0; k < 255; k++) {
                if (alpCur[k] != alpTrgt[k]) {
                    invalid = true;
                    break ;
                }
            }
            if (invalid) continue ;
            dp[i] = min(dp[i], dp[i - str[j].length()] + cnt);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> input;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> str[i];
    fill(dp, dp + 52, 1e9);
    dp[0] = 0;
    dynamic();
    if (dp[input.length()] == 1e9) cout << "-1\n";
    else cout << dp[input.length()] << '\n';
}