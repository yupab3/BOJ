#include <iostream>

using namespace std;

long     n, m;
long    h[1000002];

bool    checkM(long v) {
    long res = 0;
    for (int i = 1; i <= n; ++i) {
        if (h[i] <= v) continue ;
        res += h[i] - v;
    }
    if (res >= m) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> h[i];
    }
    long st = 0, en = 1e9;
    while (st < en) {
        long mid = (st + en + 1) / 2;
        if(checkM(mid)) st = mid;
        else en = mid - 1;
    }
    cout << en << '\n';
}