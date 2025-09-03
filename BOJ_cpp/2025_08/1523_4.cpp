#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, h;
int board[200002];
vector<int> cur;
vector<pair<int, int>> vecT;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> h >> n;
    int r, c;
    for (int i = 1; i <= n; ++i) {
        cin >> r >> c;
        vecT.push_back({-1 * c, i});
    }
    sort(vecT.begin(), vecT.end());
    int i = n;
    for (auto [en, num] : vecT) {
        board[num] = i;
        --i;
    }
    cout << "YES\n";
    for (int i = 1; i <= n; ++i)
        cout << board[i] << ' ';
    return 0;
}