#include <iostream>
#include <algorithm>

using namespace std;


// 도시 N개, 연결된 선로 N - 1개
// 현금가 Ai, IC카드결제 Bi, 철도 i에서 사용 가능한 카드 가격 Ci, 카드는 무제한
// 앞 뒤 방향 나눠서 정리
// 시작 끝 노드로 저장한 뒤 압축
// 압축은 끝 노드가 시작노드인 출발점 찾아서 하나로 합치기, 합칠 땐 제일 큰 놈부터? 재귀적으로 합칠지?
// 저장은 set

// 그냥 출발 끝만 구분하고 방향은 상관없음.
// 이 방식으로 접근하면 압축 필요 x

int n, m;
int st[100002];
int en[100002];

// int compressQueue(int dest, bool isRecursive) {
//     int src = dest;
//     priority_queue<int, vector<int>, greater<int>> tmp;
//     while (forwardDir[src].size()) {
//         dest = forwardDir[src].top();
//         forwardDir[src].pop();
//         dest = compressQueue(dest, true);
//         if (isRecursive) return dest;
//         tmp.push(dest);
//     }
//     if (src == dest) return dest;
//     forwardDir[src] = tmp;
//     tmp = {};
//     while (backwardDir[src].size()) {
//         dest = backwardDir[src].top();
//         backwardDir[src].pop();
//         dest = compressQueue(dest, true);
//         if (isRecursive) return dest;
//         tmp.push(dest);
//     }
//     if (src == dest) return dest;
//     backwardDir[src] = tmp;
// }

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> n >> m;
    int dest, src = 0;
    for (int i = 1; i <= m; i++) {
        cin >> dest;
        if (src == 0) src = dest;
        else if (src < dest) {
            st[src]++;
            en[dest]++;
            src = dest;
        }
        else {
            en[src]++;
            st[dest]++;
            src = dest;
        }
    }
    long cnt = 0, ans = 0, Ai, Bi, Ci;
    for (int i = 1; i <= n - 1; i++) {
        cin >> Ai >> Bi >> Ci;
        cnt += st[i] - en[i];
        // cout << "cnt : " << cnt << ", st[" << i << "]: " << st[i] << ", en[" << i << "]: " << en[i] << '\n'; 
        ans += min(Ai * cnt, Ci + Bi * cnt);
    }
    cout << ans << '\n';
}