#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int x, y, k;
        cin >> x >> y >> k;
        int mvx = ceil(1.0 * x / k);
        int mvy = ceil(1.0 * y / k);
        cout << max(2 * mvy, 2 * mvx - 1) << '\n';
    }
    return 0;
}