#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string input;
    cin >> input;
    int tmp = 0;
    for (int i = 0; i < input.length(); ++i)
        tmp = (tmp * 10 + input[i] - '0') % 20000303;
    cout << tmp << '\n';
    return 0;
}