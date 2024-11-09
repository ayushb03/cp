#include <iostream>
using namespace std;

const int INF = 1e9;
int dp[31][31][51];

int solve(int x, int y, int k) {
    if (dp[x][y][k] || x * y == k || !k) return dp[x][y][k];

    int ans = INF;

    // Split horizontally
    for (int i = 1; i <= x - 1; ++i) {
        for (int j = 0; j <= k; ++j) {
            ans = min(ans, y * y + solve(i, y, k - j) + solve(x - i, y, j));
        }
    }

    // Split vertically
    for (int i = 1; i <= y - 1; ++i) {
        for (int j = 0; j <= k; ++j) {
            ans = min(ans, x * x + solve(x, y - i, k - j) + solve(x, i, j));
        }
    }

    return dp[x][y][k] = ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << solve(a, b, c) << '\n';
    }
}
