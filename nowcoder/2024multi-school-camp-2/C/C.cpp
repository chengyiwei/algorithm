#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen ("C.in", "r", stdin);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<array<int, 2>> a(n + 1);
    for (int j = 0; j < 2; j++)
        for (int i = 1; i <= n; i++) {
            char ch; cin >> ch;
            a[i][j] = ch == 'R';
        }
    int ans = 0;
    vector<array<int, 2>> dp(n + 1, {0, 0});
    for (int i = 1; i <= n; i++) {
        if (a[i][0] && a[i - 1][0]) dp[i][0] = max(dp[i - 1][0] + 1, dp[i][0]);
        if (a[i][1] && a[i - 1][1]) dp[i][1] = max(dp[i - 1][1] + 1, dp[i][1]);
        if (a[i][0] && a[i][1])
            dp[i] = {max(dp[i][1] + 1, dp[i][0]), max(dp[i][0] + 1, dp[i][1])};
        ans = max(ans, max(dp[i][0], dp[i][1]));
    }
    cout << ans << endl;
    return 0;
}