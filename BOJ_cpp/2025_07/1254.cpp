#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string input;
    cin >> input;
    
    int idx = 0;
    while (idx < input.size()) {
        int st = idx;
        int en = input.size() - 1;
        while (st < en) {
            if (input[st] == input[en]) {
                ++st;
                --en;
            }
            else break ;
        }
        if (st >= en)
            break;
        ++idx;
    }
    for (int i = idx  - 1; i >= 0; --i)
        input += input[i];
    cout << input.size() << '\n';
    return 0;
}