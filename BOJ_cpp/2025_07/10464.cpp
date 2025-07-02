#include <iostream>

using namespace std;

int t;

long getXOR(long trgt) {
    long result = 1;
    long gab = (trgt - 2) / 4;
    for (long i = 2 + gab * 4; i <= trgt; ++i)
        result ^= i;
    if (trgt == 0) return 0;
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> t;
    long a, b;
    for (long i = 1; i <= t; ++i) {
        cin >> a >> b;
        long ans = getXOR(a - 1) ^ getXOR(b);
        cout << ans << '\n';
    }
}
