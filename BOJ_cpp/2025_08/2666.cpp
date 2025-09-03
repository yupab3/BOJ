#include <iostream>
#include <vector>

using namespace std;

int n, ans = 1e9;
int door[22];
vector<int> visSeq;

void    cpDoor(int arr[]) {
    for (int i = 0; i < 22; ++i) {
        for (int j = 0; j < 1; ++j)
            arr[i] = door[i];
    }
}

void    restoreDoor(int arr[]) {
    for (int i = 0; i < 22; ++i) {
        for (int j = 0; j < 1; ++j)
            door[i] = arr[i];
    }
}

void    dfs(int l, int r, int idx, int bf) {
    if (idx == n) {
        ans = min(ans, door[bf]);
        return ;
    }
    int cur = visSeq[idx];
    int arr[22];
    cpDoor(arr);
    door[cur] = abs(cur - l) + door[bf];
    dfs(cur, r, idx + 1, cur);
    door[cur] = abs(cur - r) + door[bf];
    dfs(l, cur, idx + 1, cur);
    restoreDoor(arr);
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tmp, l, r;
    cin >> n >> l >> r >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> tmp;
        visSeq.push_back(tmp);
        door[i] = 1e9;
    }
    dfs(l, r, 0, 0);
    cout << ans << '\n';
}