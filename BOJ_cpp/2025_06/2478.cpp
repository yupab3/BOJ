#include <iostream>

using namespace std;

int n;
int k, p, q;
int board[502];
int mode[502]; // 1 - asc || 2 - desc

// 오름차순 중에 내림차순 찾기 문제

// 아래 둘 다 1개는 무조건 옮긴다는 가정 하에 시작해야 한다.

// 전체가 내림차순인 경우
// k = 1 초기화
// board[n - k] == 1이면 ++k; -> 두 번째 k는 1 or 2 만 갖는다.
// 범위 p, q (전체)를 뒤집는다.
// k = 1 초기화
// 1이 제일 앞에 올 때 까지 k를 카운트한다. -> 첫 번쨰 k다

// 부분이 내림차순이 경우
// k = 1 초기화
// board[1] == 1 && 1이 오름차순인 경우 좌측에 1이 없도록 한다.
// mode[n - k] == 2인 애들 전부 옮겨야함. 내림차순이 연속적이 될 때 까지 추가로 옮긴다.
// 범위 p, q를 뒤집고 좌측에 1이 있는지 확인한다.
// 1이 있다면 k, p, q를 1씩 증가시킨다. -> 이때 결과 k가 두 번째 k다.
// k = 1 초기화
// 1이 제일 앞에 올 때 까지 k를 카운트한다. 이게 첫 번쨰 k다

bool    isAsc() {
    for (int i = 1; i <= n; i++)
        if (mode[board[i]] == 1) return true;
    return false;
}

void    checkMode() {
    if (board[2] == board[1] + 1 || (board[1] == n && board[2] == 1)) mode[board[1]] = 1;
    else if (board[1] == board[n] + 1 || (board[n] == n && board[1] == 1)) mode[board[1]] = 1;
    else mode[board[1]] = 2;
    for (int i = 2; i < n; i++) {
        if (board[i + 1] == board[i] + 1 || (board[i] == n && board[i + 1] == 1)) mode[board[i]] = 1;
        else if (board[i] == board[i - 1] + 1 || (board[i - 1] == n && board[i] == 1)) mode[board[i]] = 1;
        else mode[board[i]] = 2;
    }
    if (board[1] == board[n] + 1 || (board[n] == n && board[1] == 1)) mode[board[n]] = 1;
    else if (board[n] == board[n - 1] + 1 || (board[n - 1] == n && board[n] == 1)) mode[board[n]] = 1;
    else mode[board[n]] = 2;
}

void    checkDesc() {
    while (mode[board[n - k]] == 2)
        ++k;
}

void    shiftArr() {
    int tmp[502];
    for (int i = 1; i <= k; ++i)
        tmp[i] = board[n - k + i];
    for (int i = n; i > k; --i)
        board[i] = board[i - k];
    for (int i = 1; i <= k; ++i)
        board[i] = tmp[i];
}

void    reverseArr() {
    for (int i = 1; i <= n; ++i) {
        if (!p && mode[board[i]] == 2) p = i;
        if (mode[board[i]] == 2) q = i;
    }
    int tmp[502];
    for (int i = p; i <= q; ++i)
        tmp[i] = board[i];
    int init = p;
    int tmpP = p;
    int tmpQ = q;
    while (init <= tmpQ) {
        board[tmpP] = tmp[tmpQ];
        ++tmpP;
        --tmpQ;
    }
    if (board[1] == 1) {
        ++k;
        ++p;
        ++q;
    }
}

void    checkFirstK() {
    int i;
    for (i = 1; i <= n; ++i)
        if (board[i] == 1) break ;
    k = n - i + 1;
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> board[i];
    checkMode();
    k = 1;
    int secK;
    if (isAsc()) {
        if (board[n] == 1 && mode[board[n]] == 1) ++k;
        checkDesc();
        shiftArr();
        reverseArr();
        secK = k;
        checkFirstK();
    }
    else {
        if (board[n - 1] == 1) ++k;
        secK = k;
        shiftArr();
        reverseArr();
        checkFirstK();        
    }
    cout << k << '\n' << p << ' ' << q << '\n';
    cout << secK << '\n';
}