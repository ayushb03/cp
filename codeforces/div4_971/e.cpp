#include <bits/stdc++.h>
using ll = long long;
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        ll S = n * k + n * (n - 1) / 2;
        ll l = 1, r = n, ans = S, ls, rs, m;
        while (l <= r) {
            m = r - (r - l) / 2;
            ls = m * k + m * (m - 1) / 2;
            rs = S - ls;
            ans = min(ans, abs(ls - rs));
            if (ls < rs) {
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}