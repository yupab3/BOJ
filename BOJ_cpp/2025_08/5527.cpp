#include <iostream>
#include <vector>

using namespace std;

// 구간 여러개 구해서 3개를 합쳤을 때 가장 길어지는 구간 찾기
// 10
// 1 0 0 0 0 1 0 1 0 1 
// 1 2 1 1 1 2 3 4 5 6 
// 2 1 1 6 // 연속된 3개가 가장 큰 값 찾기

// 1 1 0 0 0 1 0 1 0 1 
// 1 1 2 1 1 2 3 4 5 6 
// 1 2 1 6 // 연속된 3개가 가장 큰 값 칮기

bool light[100002];
int  cur[100002];

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> light[i];
    cur[1] = 1;
    vector<int> score;
    for (int i = 2; i <= n; ++i) {
        if (light[i - 1] ^ light[i]) cur[i] = cur[i - 1] + 1;
        else {
            score.push_back(cur[i - 1]);
            cur[i] = 1;
        }
    }
    score.push_back(cur[n]);
    int ans = 0;
    if (score.size() < 3) {
        for (int i = 0; i < score.size(); ++i)
            ans += score[i];
    }
    else {
        for (int i = 0; i < score.size() - 2; ++i)
            ans = max(ans, score[i] + score[i + 1] + score[i + 2]);
    }
    cout << ans << '\n';
}