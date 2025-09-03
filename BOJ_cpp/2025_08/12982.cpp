#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// k개 담을 수 있는 박스는 미리 모두 담아두기
// 나머지를 0을 포함해서 모두 벡터에 저장한다.
// 1. 현재 색의 개수만큼 무조건 다채색 상자를 만들고 이전의 박스는 모두 단색 상자인 경우 -> 현재 색이 최적의 다채색 박스인 경우
// 2. 또는 이전의 모든 케이스 중 1.에 해당하는 값들의 최적값이 더 작은 경우 이 값을 채택.


int k;
vector<int> boxes;
int dp[100002];

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> k;
    int pickbox = 0, packbox = 0, box;
    for (int i = 1; i <= k; ++i) {
        cin >> box;
        packbox += box / k;
        boxes.push_back(box % k);
    }
    sort(boxes.begin(), boxes.end(), [](int a, int b) { return a > b; });
    dp[0] = boxes[0];
    if (boxes.empty()) { cout << packbox << '\n'; return 0; }
    int cnt = 0, bf = 0;
    for (int i = 1; i < boxes.size(); ++i) dp[i] = min(dp[i - 1], i + boxes[i]);
    cout << packbox + dp[k - 1] << '\n';
    return 0;
}