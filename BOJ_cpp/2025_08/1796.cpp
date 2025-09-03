#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dp[26][2];
vector<int> alp[26];

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    string input;
    cin >> input;
    for (int i = 0; i < input.size(); ++i)
        alp[input[i] - 'a'].push_back(i);
    for (int i = 0; i < 26; ++i)
        sort(alp[i].begin(), alp[i].end());
    int cursorL = 0, cursorR = 0;
    if (alp[0].size()) {
        dp[0][0] = alp[0].back() + alp[0].size();
        dp[0][1] = dp[0][0];
        cursorL = alp[0].back();
        cursorR = cursorL;
    }
    for (int i = 1; i < 26; ++i) {
        if (alp[i].empty()) {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = dp[i - 1][1];
            continue ;
        }
        int curL = alp[i].front();
        int curR = alp[i].back();
        dp[i][0] = min(dp[i - 1][0] + abs(cursorL - curR) + abs(curR - curL) + alp[i].size(),
                        dp[i - 1][1] + abs(cursorR - curR) + abs(curR - curL) + alp[i].size());
        dp[i][1] = min(dp[i - 1][0] + abs(cursorL - curL) + abs(curL - curR) + alp[i].size(),
                        dp[i - 1][1] + abs(cursorR - curL) + abs(curL - curR) + alp[i].size());
        cursorL = curL;
        cursorR = curR;
    }
    cout << min(dp[25][0], dp[25][1]) << '\n';
    return 0;
}