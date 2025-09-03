#include <iostream>

using namespace std;

int n, t;
int board[100002];
int gap[100002];

// 갭을 기준으로 판단, 갭이 양수면 내리막 (좌측 값), 음수면 오르막 (우측 값) 뽑는다. 이 값이 [작업 대상]이 된다
// 큐에서 다음 갭이 몇인지 확인하고 그 값을 타겟으로 설정한다.
// [작업 대상]의 양쪽 갭 중 타겟과 가까운 쪽의 차이를 구해서 양 쪽 갭에서 뺀다. T에서는 한 번만 뺀다. (양쪽 동시에 줄어드니까)
// 양 쪽 갭을 큐에 다시 추가한다.
// 낮춘 수의 양쪽 갭을 다시 큐에 넣는다.

// 갭을 별도의 배열에 따로 저장해두고, 큐에서 작업 대상을 뽑았을 때 그 갭과 일치하지 않으면 버림
// 그 외에는 거기까지 한 번에 줄이면 된다.

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> n >> t;
    for (int i = 1; i <= n; ++i)
        cin >> board[i];
    for (int i = 1; i < n; ++i)
        gap[i] = board[i] - board[i + 1];
    
}