#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    ssize_t a, b;
    cin >> a >> b;
    cout << (a + b) * (a - b) << '\n';
    return (0);
}