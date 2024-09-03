#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;
int main() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<vector<ll>> dp(n + 1, vector<ll>(2, -INF));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = max({dp[i - 1][0], dp[i - 1][1] + a[i] * 2});
        dp[i][1] = max({dp[i - 1][1], dp[i - 1][0] + a[i]});
    }
    cout << max(dp[n][0], dp[n][1]) << '\n';
    return 0;
}