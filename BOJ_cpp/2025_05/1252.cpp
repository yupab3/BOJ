#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    string l, r;
    cin >> l >> r;
    
    stack<int> stk;
    int lLen = l.length();
    int rLen = r.length();
    int carry = 0;
    while (1) {
        int lNum = 0, rNum = 0;
        if (lLen) lNum = l[lLen-- - 1] - '0';
        if (rLen) rNum = r[rLen-- - 1] - '0';
        if (lNum && rNum) {
            if (carry)
                stk.push(1);
            else {
                carry = 1;
                stk.push(0);
            }
        }
        else if (lNum || rNum) {
            if (carry)
                stk.push(0);
            else
                stk.push(1);
        }
        else {
            if (carry) {
                carry = 0;
                stk.push(1);
            }
            else
                stk.push(0);
        }
        if (!(rLen || lLen)) break;
    }
    if (carry) stk.push(1);
    bool Zero = 1;
    while (stk.size()) {
        if (stk.top() == 0 && Zero && stk.size() > 1) {
            stk.pop();
            continue ;
        }
        else Zero = false;
        cout << stk.top();
        stk.pop();
    }
}
