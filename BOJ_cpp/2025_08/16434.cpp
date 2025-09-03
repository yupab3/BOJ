#include <iostream>

using namespace std;

int     n;
long    Hmax, Hcur, Hatk;
int     t[123458];
int     a[123458];
int     h[123458];

void    doGame() {
    for (int i = 1; i <= n; ++i) {
        if (t[i] == 1) {
            if (h[i] <= Hatk) continue ;
            Hcur -= (h[i] / Hatk - (h[i] % Hatk == 0)) * a[i];
            if (Hcur < 0) {
                Hmax -= Hcur;
                Hcur = 0;
            }
        }
        else {
            Hatk += a[i];
            Hcur = min(Hmax, Hcur + h[i]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> n >> Hatk;
    for (int i = 1; i <= n; ++i) {
        cin >> t[i] >> a[i] >> h[i];
    }
    doGame();
    cout << Hmax + 1 << '\n';
    return 0;
}