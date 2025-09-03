#include <iostream>

using namespace std;

int cnt[128];

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, t;
    cin >> t >> n;
    string input;
    for (int i = 1; i <= t; ++i) {
        fill(cnt, cnt + 128, 0);
        cin >> input;
        for (int j = 0; j < input.size(); ++j)
            ++cnt[input[j]];
        bool check = true ;
        for (int j = 1; j < input.size(); ++j) {
            if (cnt[input[j - 1]] > 1 && cnt[input[j]] > 1) check = false;
            else if (cnt[input[j - 1]] == cnt[input[j]]) check = false;
        }
        if (check) cout << "T\n";
        else cout << "F\n";
    }
    return 0;
}