#include <iostream>
#include <algorithm>

using namespace std;

int px[100002];
int py[100002];

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> px[i] >> py[i];
    sort(px, px + m + 1);
    sort(py, py + m + 1);
    int x = px[m/2 + 1];
    int y = py[m/2 + 1];
    int ans = 0;
    for (int i = 1; i <= m; i++)
        ans += abs(x - px[i]) + abs(y - py[i]);
    cout << ans << '\n';
}