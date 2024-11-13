#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    string str;
    cin >> str;
    for (size_t i = 0; i < str.size(); i++)
    {
        if (isupper(str[i]))
            str[i] += 32;
        else
            str[i] -= 32;
    }
    cout << str << '\n';
    return (0);
}