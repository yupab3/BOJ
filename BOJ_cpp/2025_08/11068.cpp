#include <iostream>
#include <deque>

using namespace std;

bool    checkAns(int n, int div) {
    deque<int> d;
    while (n > 0) {
        d.push_back(n % div);
        n /= div;
    }
    while (d.size()) {
        if (d.front() == d.back()) {
            if (d.size() == 1) return true ;
            d.pop_back();
            d.pop_front();
        }
        else return false ;
    }
    return true ;
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t, n;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cin >> n;
        bool    success = false;
        for (int j = 2; j <= 64; ++j)
            if (checkAns(n, j)) success = true ;
        if (success) cout << "1\n";
        else cout << "0\n";
    }
    return 0;
}