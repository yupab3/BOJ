#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n;
int rmNo[100002];
vector<pair<int, int>> lecBgn;
vector<pair<int, int>> lecEnd;
queue<int> eptRm;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> n;
    int no, st, en;
    for (int i = 1; i <= n; i++) {
        cin >> no >> st >> en;
        lecBgn.push_back({st, no});
        lecEnd.push_back({en, no});
    }
    sort(lecBgn.begin(), lecBgn.end());
    sort(lecEnd.begin(), lecEnd.end());
    int curRm = 1;
    auto sIt = lecBgn.begin();
    auto eIt = lecEnd.begin();
    while (sIt != lecBgn.end()) {
        if (sIt->first < eIt->first) {
            if (eptRm.empty()) {
                rmNo[sIt->second] = curRm;
                curRm++;
            }
            else {
                rmNo[sIt->second] = eptRm.front();
                eptRm.pop();
            }
            sIt++;
        }
        else {
            eptRm.push(rmNo[eIt->second]);
            eIt++;
        }
    }
    cout << curRm - 1 << '\n';
    for (int i = 1; i <= n; i++)
        cout << rmNo[i] << '\n';
}