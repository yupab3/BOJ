#include <iostream>

using namespace std;

size_t arr[10005];

int main()
{
    ios::sync_with_stdio(0);
    std::cin.tie(0);

    int k, n;
    cin >> k >> n;
    size_t cnt, ans, m_len = 0;
    for (int i = 1; i <= k; i++)
    {
        cin >> arr[i];
        m_len = max(arr[i], m_len);
    }
    size_t left = 1, right = m_len + 1;
    while (1)
    {
        cnt = 0;
        ans = (right + left) / 2;
        for (int i = 1; i <= k; i++)
        {
            cnt += arr[i] / ans;
        }
        if (left == right - 1)
            break ;
        else if (cnt >= n)
            left = ans;
        else if (cnt < n)
            right = ans;
    }
    cout << ans << '\n';
}