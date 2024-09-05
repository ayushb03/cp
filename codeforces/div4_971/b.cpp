#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        vector<int> ans;
        for(int i = 0; i < n; ++i) {
            cin >> s;
            ans.push_back(s.find('#') + 1);
        }
        for(auto it = ans.rbegin(); it != ans.rend(); ++it) {
            cout << *it << ' ';
        }
        cout << '\n';
    }
    return 0;
}