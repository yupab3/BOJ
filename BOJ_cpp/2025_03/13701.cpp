#include <iostream>
#include <string>

using namespace std;

int dup[(1 << 20) + 2];

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int num = -1;
    while (cin >> num) {
        if (dup[num / 32] & (1 << (num % 32))) continue ;
        dup[num / 32] = dup[num / 32] | (1 << (num % 32));
        cout << num;
        cout << ' ';
    }
}