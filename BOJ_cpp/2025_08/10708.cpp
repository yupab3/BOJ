#include <iostream>

using namespace std;

int trgt[102];
int score[102];

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, pred;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
        cin >> trgt[i];
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> pred;
            if (pred == trgt[i]) ++score[j];
            else ++score[trgt[i]];
        }
    }
    for (int i = 1; i <= n; ++i)
        cout << score[i] << '\n';
    return 0;
}