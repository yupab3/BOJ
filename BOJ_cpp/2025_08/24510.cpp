#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, ans = 0;
    cin >> n;
    string input;
    while (n--) {
        cin >> input;
        int cnt = 0, st = 0;
        while (input.find("for", st) != string::npos) {
            st = input.find("for", st) + 3;
            ++cnt;
        }
        st = 0;
        while (input.find("while", st) != string::npos) {
            st = input.find("while", st) + 5;
            ++cnt;
        }
        ans = max(ans, cnt);
    }
    cout << ans << '\n';
    return 0;
}