#include <iostream>

using namespace std;

int ans;
string str;

void solver(int left, int right, bool isdeleted)
{
    int cnt = 0;
    while (left < right)
    {
        if (str[left] == str[right])
        {
            ++left, --right;
        }
        else
        {
            if (isdeleted)
            {
                if (ans == -1)
                {
                    ans = 2;
                }
                return;
            }
            solver(left + 1, right, true);
            solver(left, right - 1, true);
            return;
        }
    }
    ans = isdeleted;
}

int main()
{
    ios::sync_with_stdio(0);
    std::cin.tie(0);

    int T;
    cin >> T;
    for(int i = 0; i < T; i++)
    {
        cin >> str;
        ans = (-1);
        solver(0, str.size() - 1, false);
        cout << ans << "\n";
    }
    return 0;
}