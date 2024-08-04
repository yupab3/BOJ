#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    ssize_t n, m;
    cin >> n >> m;
    cout << abs(n - m) << '\n';
    return (0);
}