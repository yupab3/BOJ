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
    int         count;
    int         n;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        if (S1.empty())
        {
            S1.push(num);
            S2.push(i + 1);
            cout << "0 ";
        }
        else
        {
            while (S1.empty() == 0 && S1.top() < num)
            {
                S1.pop();
                S2.pop();
            }
            if (i == n - 1)
            {
                if (S1.empty())
                {
                    cout << "0";
                }
                else
                {
                    cout << S2.top();
                }
            }
            else
            {
                if (S1.empty())
                {
                    cout << "0 ";
                }
                else
                {
                    cout << S2.top() << " ";
                }
            }
            S1.push(num);
            S2.push(i + 1);
        }
    }
}