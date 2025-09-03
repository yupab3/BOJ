#include <iostream>
#include <cmath>

using namespace std;

// 펠린드롬 전부 구한 다음 소수 판별
// 펠린드롬을 어떻게 구할 것인가?
// 처음 끝 만들고 그다음 차수로 이동
// 11 22 33 44 55 66 77 88 99
// 101 111 121 131 141 151 161 171 181 191
// 202 212 222 232 242 252 262 272 282 292
// 100자릿수 m = 2, c = 0 시작

int a, b, num;
bool redFlag;

void checkAns(int num) {
    bool check = true ;
    for (int i = 2; i <= sqrt(num); ++i)
        if (num % i == 0) check = false;
    if (check) cout << num << '\n';
}

void getP(int cur, int m, int c, bool check) {
    if ((m % 2 && c == m / 2 + 1) || (m % 2 == 0 && c == m / 2)) {
        if (cur < a) return ;
        else if (b < cur) {
            redFlag = true ;
            return ;
        }
        checkAns(cur);
        return ;
    }
    for (int i = 0; i <= 9; ++i) {
        if (check && i == 0) continue ;
        cur += i * pow(10, c);
        if (c < m / 2) cur += i * pow(10, m - c - 1);
        getP(cur, m, c + 1, false);
        if (redFlag) break ;
        cur -= i * pow(10, c);
        if (c < m / 2) cur -= i * pow(10, m - c - 1);
    }
    return ;
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> a >> b;
    for (int i = 1; i <= 8; ++i)
        getP(0, i, 0, true);
    cout << "-1\n";
    return 0;
}