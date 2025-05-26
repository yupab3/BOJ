#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;
    int cnt = 0;
    int cur = n;
    for (int i = 2; i <= n; i++) {
        while (cur >= i && cur % i == 0) {
            cur /= i;
            cnt++;
        }
        if (i > cur) break ;
    }
    if (cnt <= 1) {
        cout << 0;
        return 0;
    }
    int pNo = 1;
    int two = 2;
    while (cnt > two) {
        two *= 2;
        pNo++;
    }
    cout << pNo;
}