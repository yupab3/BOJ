#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    stack<int>  S1;
	stack<int>	S2;
	stack<int>	S3;
    int         num;
    long long   count;
    int         n;

    cin >> n;
    count = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        S1.push(num);
    }
	num = 0;
	while (S1.empty() == 0)
	{
		if (S3.empty())
		{
			S2.push(-1);
		}
		else if (S3.top() > S1.top())
		{
			S2.push(S3.top());
		}
		else if (S3.top() <= S1.top())
		{
			while (S3.empty() == 0 && S3.top() <= S1.top())
			{
				S3.pop();
			}
			if (S3.empty() == 0)
			{
				S2.push(S3.top());
			}
			else
			{
				S2.push(-1);
			}
		}
		S3.push(S1.top());
		S1.pop();
	}
	// while (S1.empty() == 0)
	// {
	// 	S4 = S3;
	// 	while (S4.empty() == 0 && S1.top() >= S4.top())
	// 	{
	// 		S4.pop();
	// 	}
	// 	if (S4.empty())
	// 	{
	// 		S2.push(-1);
	// 		S3.push(S1.top());
	// 		S1.pop();
	// 	}
	// 	else
	// 	{
	// 		S2.push(S4.top());
	// 		S3.push(S1.top());
	// 		S1.pop();
	// 	}
	// }
	while (S2.empty() == 0)
	{
		cout << S2.top();
		S2.pop();
		if (S2.empty() == 0)
		{
			cout << " ";
		}
	}
}