#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<ll>> a(n + 5, vector<ll>(m + 5, 0));
    vector<vector<ll>> dp(n + 5, vector<ll>(m + 5, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    
    for (int i = 1; i <= n; i++) {
        vector<ll> pre(m + 5, 0), pre_max(m + 5, 0), suf(m + 5, 0), suf_max(m + 5, 0);
        for (int j = 1; j <= m; j++) {
            pre[j] = max(pre[j - 1] + a[i][j], a[i][j]);
            if(j == 1) pre_max[j] = pre[j] + dp[i - 1][j];
            else pre_max[j] = max(pre_max[j - 1] + a[i][j], pre[j] + dp[i - 1][j]);
        }
        for (int j = m; j >= 1; j--) {
            suf[j] = max(suf[j + 1] + a[i][j], a[i][j]);
            if(j == m) suf_max[j] = suf[j] + dp[i - 1][j];
            else suf_max[j] = max(suf_max[j + 1] + a[i][j], suf[j] + dp[i - 1][j]);
        }
        for (int j = 1; j <= m; j++) {
            dp[i][j] = max(pre[j] + suf_max[j], pre_max[j] + suf[j]) - a[i][j];
        }
    }
    ll ans = *max_element(dp[n].begin() + 1, dp[n].end());
    cout << ans << '\n';
}

int main() {
    freopen ("I.in", "r", stdin);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}