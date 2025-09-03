#include <iostream>

using namespace std;

int n;
int oarr[1002];
int asc[1002];
int desc[1002];
int ascCnt[1002];
int descCnt[1002];

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> oarr[i];
    // copy(oarr, oarr + 1002, asc);
    // copy(oarr, oarr + 1002, desc);
    // sort(asc, asc + n);
    // sort(desc, desc + n, [](int a, int b){return a > b;});
    fill(asc, asc + n, 1e9);
    fill(desc, desc + n, 1e9);
    int idx;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        idx = lower_bound(asc, asc + n, oarr[i]) - asc;
        // cout << "asc idx : " << idx << ", asc[" << idx << "] : " << asc[idx] << ", oarr[" << i << "] : " << oarr[i] << '\n';
        asc[idx] = oarr[i];
        ascCnt[i] = idx + 1;
        idx = lower_bound(desc, desc + n, oarr[n - i - 1]) - desc;
        // cout << "desc idx : " << idx << ", desc[" << idx << "] : " << desc[idx] << ", oarr[" << n - i - 1 << "] : " << oarr[n - i - 1] << '\n';
        desc[idx] = oarr[n - i - 1];
        descCnt[n - i - 1] = idx;
    }
    for (int i = 0; i < n; ++i)
        ans = max(ans, ascCnt[i] + descCnt[i]);
    cout << ans << '\n';
    return 0;
}