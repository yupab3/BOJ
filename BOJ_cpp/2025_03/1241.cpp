#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int board[1000002];
queue<int> q;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        board[num]++;
        q.push(num);
    }
    while (q.size()) {
        int num = q.front();
        q.pop();
        int ans = 0;
        for (int i = 1; i <= sqrt(num); i++) {
            if (num % i == 0) {
                ans += board[i];
                if (num / i != i) ans += board[num / i];
            }
        }
        cout << ans - 1<< '\n';
    }
}