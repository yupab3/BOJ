#include <iostream>
#include <set>
#include <algorithm>


using namespace std;

set<char>       node[130];
bool            choice[130];

void    bt(int trgt, char origin) {
    if (choice[trgt]) return ;
    choice[trgt] = true;
    for (char n_trgt : node[trgt]) {
        bt(n_trgt, origin);
    }
    node[origin].insert(trgt);
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    string input;
    cin >> n;
    cin.ignore();
    for (int i = 1; i <= n; i++) {
        getline(cin, input);
        // cout << "i : " << i << ", input : " << input << ", [0] : " << input[0] << ", [last] : " << input[input.size() - 1] << '\n';
        node[input[0]].insert(input[input.size() - 1]);
    }
    for (char i = 'A'; i <= 'Z'; i++) {
        choice[i] = true;
        for (char trgt : node[i]) {
            bt(trgt, i);
        }
        fill(choice, choice + 129, 0);
    }
    for (char i = 'a'; i <= 'z'; i++) {
        choice[i] = true;
        for (char trgt : node[i]) {
            bt(trgt, i);
        }
        fill(choice, choice + 129, 0);
    }
    int ans = 0;
    for (char i = 'A'; i <= 'Z'; i++) {
        for (char trgt : node[i]) {
            if (trgt == i) continue ;
            ans++;
        }
    }
    for (char i = 'a'; i <= 'z'; i++) {
        for (char trgt : node[i]) {
            if (trgt == i) continue ;
            ans++;
        }
    }
    cout << ans << '\n';
    for (char i = 'A'; i <= 'Z'; i++) {
        for (char trgt : node[i]) {
            if (trgt == i) continue ;
            cout << i << " => " << trgt << '\n';
        }
    }
    for (char i = 'a'; i <= 'z'; i++) {
        for (char trgt : node[i]) {
            if (trgt == i) continue ;
            cout << i << " => " << trgt << '\n';
        }
    }
}


// 단방향 노드
// 저장할 때 A부터 싹 순회하면서 저장 52번 * 10000번
// 출력할 때 저장된 거 정렬 때리고 출력