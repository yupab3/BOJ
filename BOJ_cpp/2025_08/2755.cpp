#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string input;
    int n, cnt, totalCnt = 0, totalScore = 0, score;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> input >> cnt >> input;
        totalCnt += cnt;
        if (input[0] == 'A') score = 4000;
        else if (input[0] == 'B') score = 3000;
        else if (input[0] == 'C') score = 2000;
        else if (input[0] == 'D') score = 1000;
        else if (input[0] == 'F') score = 0000;
        if (input[1] == '+') score += 300;
        else if (input[1] == '-') score -= 300;
        totalScore += cnt * score;
    }
    totalScore /= totalCnt;
    if (totalScore % 10 > 4) totalScore += 10;
    totalScore /= 10;
    cout << totalScore / 100 << '.' << totalScore % 100;
    if (totalScore % 100 < 10) cout << '0';
    cout << '\n';
    return 0;
}