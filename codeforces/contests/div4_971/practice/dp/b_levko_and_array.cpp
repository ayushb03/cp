#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;

const int MAXN = 2100;

int N, K;
int dp[MAXN];
int arr[MAXN];

bool f(ll x) {
    for (int i = 0; i < N; i++) {
        dp[i] = i; 
    }
    
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (abs(arr[j] - arr[i]) <= x * (i - j)) {
                dp[i] = min(dp[i], dp[j] + i - j - 1);
            }
        }
    }
    
    for (int i = 0; i < N; i++) {
        if (dp[i] + (N - 1 - i) <= K) {
            return true; // if we can achieve K or fewer removals
        }
    }
    
    return false;
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    ll lo = 0, hi = 1e10;
    
    while (lo < hi) {
        ll mid = (lo + hi) / 2;
        if (f(mid)) {
            hi = mid;  
        } else {
            lo = mid + 1; 
        }
    }
    
    cout << lo << '\n';
    return 0;
}
