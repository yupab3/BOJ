#include <iostream>

using namespace std;

long a, d, q, l, r;

// 유클리드 돌릴 때 a와 b를 최소와 최대를 넣으면 안되고 최소와 그 다음값을 넣어야 중간값을 포함한 최대공약수가 나온다.
long euclid(long a, long b) {
    long tmp;
    while (b != 0) {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> a >> d >> q;
    int query;
    long initNum, middleNum;
    for (int i = 1; i <= q; i++) {
        cin >> query >> l >> r;
        initNum = a + (l - 1) * d;
        middleNum = a + l * d;
        if (query == 1)
            cout << (r - l + 1) * a + r * (r - 1) * d / 2 - (l - 1) * (l - 2) * d / 2 << '\n';
        else if (l == r)
            cout << euclid(initNum, initNum) << '\n';
        else
            cout << euclid(initNum, middleNum) << '\n';
    }
}