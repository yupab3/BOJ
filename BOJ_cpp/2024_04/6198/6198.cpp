#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    stack<int>  S1;
    stack<int>  S2;
    int         num;
    long long   count;
    int         n;

    cin >> n;
    count = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        if (S1.empty())
        {
            S1.push(num);
            S2.push(i + 1);
        }
        else
        {
            while (S1.empty() == 0 && S1.top() <= num)
            {
                count += i - S2.top();
                S1.pop();
                S2.pop();
            }
            S1.push(num);
            S2.push(i + 1);
        }
    }
    while (S1.empty() == 0)
    {
        count += n - S2.top();
        S1.pop();
        S2.pop();
    }
    cout << count;
}