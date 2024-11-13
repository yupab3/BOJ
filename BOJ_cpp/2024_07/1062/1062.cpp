#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string>  words;
bool charset[26] = {false, };
int n, k;

int checkWords()
{
    int ans = 0;
    for (vector<string>::iterator it = words.begin(); it != words.end(); ++it)
    {
        std::string tmp = *it;
        int idx = 0;
        while (tmp[idx] != '\0')
        {
            if (charset[tmp[idx] - 97] == false)
                break ;
            idx++;
        }
        if (tmp[idx] == '\0')
            ans++;
    }
    return ans;
}

int solver(int idx, int cnt)
{
    int ans = 0;
    if (cnt == 0)
    {
        ans = checkWords();
        return ans;
    }
    for (int i = idx; i < 26; i++)
    {
        if (charset[i] == true)
            continue;
        charset[i] = true;
        ans = max(ans, solver(i + 1, cnt - 1));
        charset[i] = false;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    std::cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        string  tmp;
        cin >> tmp;
        words.push_back(tmp);
    }
    charset[0] = true;
    charset[2] = true;
    charset[8] = true;
    charset[13] = true;
    charset[19] = true;
    if (k < 5)
    {
        std::cout << "0\n";
        return 0;
    }
    std::cout << solver(0, k - 5) << '\n';
}