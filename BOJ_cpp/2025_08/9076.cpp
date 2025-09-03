#include <iostream>
#include <algorithm>

using namespace std;

int n[7];

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    cin >> t;
    while (t > 0) {
        for(int i = 1; i <= 5; ++i)
            cin >> n[i];
        sort(n + 1, n + 6);
        if (abs(n[2] - n[3]) >= 4 || abs(n[2] - n[4]) >= 4) cout << "KIN\n";
        else cout << n[2] + n[3] + n[4] << '\n';
        --t;
    }
}