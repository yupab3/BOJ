#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;
    string str1, str2;
    for (int i = 1; i <= n; ++i) {
        int idx = 0;
        cin >> str1 >> str2;
        for (int j = 0; j < str2.size(); ++j) {
            str2[j] = str2[j] + str1[idx] - 'A';
            if (str2[j] > 'Z') str2[j] -= 'Z' - 'A' + 1;
            if (++idx == str1.size()) idx = 0;
        }
        cout << "Ciphertext: " << str2 << '\n';
    }
    return 0;
}