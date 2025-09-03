#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, x1, x2, y1, y2;
    int maxX = 1e9, minX = 0, maxY = 1e9, minY = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x1 >> x2 >> y1 >> y2;
        maxX = min(maxX, x2);
        minX = max(minX, x1);
        maxY = min(maxY, y2);
        minY = max(minY, y1);
    }
    int gapX = maxX - minX;
    int gapY = maxY - minY;
    if (gapX < 0 || gapY < 0) cout << "0\n";
    else cout << gapX * gapY << '\n';
    return 0;
}