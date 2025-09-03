#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t, x1, x2, y1, y2, r1, r2;
    cin >> t;
    while (t--) {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        int dist = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
        int gap = (r1 - r2) * (r1 - r2);
        int direct = (r1 + r2) * (r1 + r2);
        if (x1 == x2 && y1 == y2 && r1 == r2) cout << "-1\n";
        else if (x1 == x2 && y1 == y2) cout << "0\n";
        else if (dist > direct) cout << "0\n";
        else if (dist == direct) cout << "1\n";
        else if (dist < direct && dist == gap) cout << "1\n";
        else if (dist < direct && dist < gap) cout << "0\n";
        else cout << "2\n";
    }
    return 0;
}