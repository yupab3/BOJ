#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 10000쌍 입력 받아서 정렬때린 다음 중복 제거 후 좌표 압축
// 원본 좌표 쌍과 압축 좌표 쌍을 따로 저장
// ** 인덱스가 붙어있어도 사이에 좌표가 있는 경우 gap으로 관리!
// 맨 앞에 붙은 포스터부터 순차적으로 확인하며 붙인다. 갭을 어떻게 관리할지 알아야 하는데..
// 입력이
// 3
// 2 7
// 6 10
// 1 3

// 1 2 3 6 7 10
//      !   !
// 1 2 3 4 5 6
// 3과 5는 갭이 있음

// 입력 순서대로 그리면
// 1 3 그리기
// 4 6 그리기
// 2 5 그릴 때 갭이 있는지 확인..

// 1 3을 칠하기 전에 갭이 있는지 확인한다.
// 1, 2 없음 -> 패스, 3은 (3 -> 4) 구간에 갭이 있을 수 있으므로 이번 포스터를 칠할 때는 확인하지 않는다.
// 즉 시작점 부터 끝점 전까지 l ~ (r - 1) 까지의 갭을 확인한다.
// 현재 포스터 상황 111000 (0은 빈 구간, 인덱스 기준) // 1110000000 (입력값 기준)

// 4 6을 그릴 땐 4, 5 확인, 5가 있으므로 갭 표시를 없애면서 진행한다.
// 현재 포스터 상황 111222 (인덱스 기준) // 1110022222 (입력값 기준)

// 2 5를 그릴 땐 2, 3, 4, 5 확인, 2, 4는 원래 없었고, 5는 4 6을 붙이며 없어졌음. 3이 갭이 여전히 남아있으므로
// 1~6까지 모두 칠해져 있더라도 gap이 남아있으므로 카운트 한 뒤 3의 갭 표시를 없앰.
// 현재 포스터 상황 111222 (인덱스 기준) // 1113322222 (입력값 기준)

// 따라서 위 방법으로 좌표압축을 통해 사라지는 정보를 보완할 수 있다.

int     n;
vector<int> stIdx; // 각 포스터의 좌표압축한 시작점
vector<int> enIdx; // 각 포스터의 좌표압축한 끝점
vector<int> idxToValue; // 각 좌표의 인덱스를 원래 값으로 복원하는 벡터
vector<int> gap; // 좌표압축한 인덱스와 다음 인덱스 사이에 빈 공간을 체크하는 벡터
vector<int> parent; // 유니온 정보를 담고 있는 집합벡터

int findGap(int cur) {
    if (cur == gap[cur]) return cur;
    return gap[cur] = findGap(gap[cur]);
}

int findUnion(int cur) {
    if (cur == parent[cur]) return cur;
    return parent[cur] = findUnion(parent[cur]);
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> n;
    int a, b;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        idxToValue.push_back(a);
        idxToValue.push_back(b);
        stIdx.push_back(a);
        enIdx.push_back(b);
    }
    sort(idxToValue.begin(), idxToValue.end());
    idxToValue.erase(unique(idxToValue.begin(), idxToValue.end()), idxToValue.end());
    int ans = 0;
    for (int i = 0; i < stIdx.size(); ++i) {
        stIdx[i] = lower_bound(idxToValue.begin(), idxToValue.end(), stIdx[i]) - idxToValue.begin();
        enIdx[i] = lower_bound(idxToValue.begin(), idxToValue.end(), enIdx[i]) - idxToValue.begin();
    }
    for (int i = 0; i < idxToValue.size() - 1; ++i)
        gap.push_back(idxToValue[i + 1] - idxToValue[i] - 1 ? i : i + 1);
    gap.push_back(idxToValue.size() - 1);
    for (int i = 0; i < idxToValue.size(); ++i)
        parent.push_back(i);
    parent.push_back(idxToValue.size());
    for (int i = n - 1; i >= 0; --i) {
        bool flag = false;
        for (int j = findGap(stIdx[i]); j < enIdx[i]; j = gap[j]) {
            gap[j] = findGap(j + 1);
            flag = true ;
        }
        for (int j = findUnion(stIdx[i]); j <= enIdx[i]; j = parent[j]) {
            parent[j] = findUnion(j + 1);
            flag = true ;
        }
        if (flag) ++ans;
    }
    cout << ans << '\n';
    return 0;
}