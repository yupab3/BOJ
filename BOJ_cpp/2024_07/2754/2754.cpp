#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    string str;
    int ans1, ans2;
    cin >> str;
    if (str[0] == 'A')
        ans1 = 4;
    else if (str[0] == 'B')
        ans1 = 3;
    else if (str[0] == 'C')
        ans1 = 2;
    else if (str[0] == 'D')
        ans1 = 1;
    else if (str[0] == 'F')
    {
        cout << "0.0\n";
        return (0);
    }
    if (str[1] == '+')
        ans2 = 3;
    else if (str[1] == '0')
        ans2 = 0;
    else if (str[1] == '-')
    {
        ans1--;
        ans2 = 7;
    }
    cout << ans1 << "." << ans2 << '\n';
    return (0);
}