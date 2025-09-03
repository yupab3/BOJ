#include <iostream>
#include <stack>

using namespace std;

int dist, moved;
int m;
int md[102], t[102], cnt[102];
int bf[102];

// 현재 내 정비소에서 갈 수 있는 정비소를 모두 방문하며 그 정비소의 기존 시간보다 빠르게 갈 수 있는지 확인
// 되면 갱신하고 bf를 자신으로 변경

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> dist >> m;
    for (int i = 1; i <= m + 1; ++i) {
        cin >> md[i];
        md[i] += md[i - 1];
        bf[i] = i - 1;
    }
    for (int i = 1; i <= m; ++i)
        cin >> t[i];
    // for (int i = 0; i <= m + 1; ++i)
    //     cnt[i] = 2147483647;
    fill(cnt, cnt + 102, 2147483647);
    cnt[0] = 0;
    int cur = 0;
    while (cur < m + 1) {
        for (int i = cur + 1; i <= m + 1; ++i) {
            if (md[i] - md[cur] <= dist) {
                if (cnt[cur] + t[i] < cnt[i]) {
                    cnt[i] = cnt[cur] + t[i];
                    bf[i] = cur;
                }
            }
            else break ;
        }
        ++cur;
    }
    int idx = m + 1;
    stack<int> stk;
    while (bf[idx] > 0) {
        stk.push(bf[idx]);
        idx = bf[idx];
    }
    if (stk.size()) cout << cnt[m + 1] << '\n' << stk.size() << '\n';
    else cout << cnt[m + 1] << '\n' << stk.size();
    while (stk.size()) {
        cout << stk.top() << ' ';
        stk.pop();
    }
    return 0;
}