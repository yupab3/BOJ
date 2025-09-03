#include <iostream>
#include <algorithm>

using namespace std;

int l, n;
int s[52];

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> l;
    for (int i = 1; i <= l; ++i)
        cin >> s[i];
    cin >> n;
    sort(s + 1, s + l + 1);
    int idx = lower_bound(s + 1, s + l + 1, n) - s;
    if (s[idx] == n) {
        cout << "0\n";
        return 0;
    }
    cout << (n - s[idx - 1] - 1) * (s[idx] - n) + s[idx] - n - 1 << '\n';
    return 0;
}