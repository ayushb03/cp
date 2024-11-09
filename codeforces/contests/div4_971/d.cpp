#include<bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        set<int> y1, y0;
        for(int i = 0; i < n; ++i) {
            int x, y;
            cin >> x >> y;
            y == 0 ? y0.insert(x) : y1.insert(x);
        }
        int sz1 = y1.size();
        int sz0 = y0.size();
        ll ans = 0;
        for(const int& x : y1) {
            if(y0.find(x) != y0.end()) {
                ans += (sz1 + sz0 - 2); 
            }
            if(y0.find(x - 1) != y0.end() && y0.find(x + 1) != y0.end()) {
                ++ans;
            }
        }
        for(const int& x : y0) {
            if(y1.find(x - 1) != y1.end() && y1.find(x + 1) != y1.end()) {
                ++ans;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}