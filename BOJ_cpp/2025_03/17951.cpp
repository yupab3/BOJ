#include <iostream>

using namespace std;

int x[100002];

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        x[i] += x[i - 1];
    }
    int term_min = 0;
    int term_max = x[n] / k;
    int term = term_max / 2;
    while (term_min <= term_max) {
        int div = 1;
        int st = 0;
        for (int i = 1; i <= n; i++) {
            if (x[i] - x[st] >= term) {
                div++;
                st = i;
            }
        }
        // cout << "div : " << div << '\n';
        if (div > k)
            term_min = term + 1;
        else
            term_max = term - 1;
        term = (term_min + term_max) / 2;
    }
    cout << term << '\n';
}