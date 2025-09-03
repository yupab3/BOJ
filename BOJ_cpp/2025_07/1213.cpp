#include <iostream>
#include <string>
#include <stack>

using namespace std;

int alp[128];

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string input;
    cin >> input;
    for (int i = 0; i < input.size(); ++i)
        ++alp[input[i]];
    int cnt = input.size();
    stack<char> stk;
    string ans = "";
    while (cnt) {
        int idx = 0;
        for (idx = 'A'; idx <= 'Z'; ++idx) {
            if (alp[idx] >= 2) break ;
        }
        if (idx > 'Z') {
            for (idx = 'A'; idx <= 'Z'; ++idx)
                if (alp[idx] >= 1) break ;
            if (idx > 'Z') break ;
            ans += (char)idx;
            alp[idx] -= 1;
            --cnt;
            break ;
        }
        else {
            ans += (char)idx;
            stk.push(idx);
            alp[idx] -= 2;
            cnt -= 2;
        }
    }
    while (stk.size()) {
        ans += stk.top();
        stk.pop();
    }
    if (cnt) cout << "I'm Sorry Hansoo\n";
    else cout << ans << '\n';
    return 0;
}