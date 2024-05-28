#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m; cin >> n >> m;
    vector<int> a(m + 1);
    for (int i = 1; i <= m; i++) cin >> a[i], a[i] %= n;
    vector<vector<int>> dp(m + 1, vector<int>(n, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= m; i ++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] |= dp[i - 1][(j - a[i] + n) % n];
            dp[i][j] |= dp[i - 1][(j + a[i]) % n];
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; i ++) {
        ans |= dp[i][0];
    }
    cout << (ans ? "YES" : "NO") << endl;
    return 0;
}