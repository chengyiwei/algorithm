#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen ("D.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m; m = n - m;
    vector<int> v(n + 1), s(n + 1);
    vector<pair<int, int>> p(m + 1); int cnt = 0;
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) {
        if (v[i] == 0) s[i] = 1;
        s[i] += s[i - 1];
        if (v[i] != 0) p[++cnt] = {v[i], s[i]};
    }

    vector<int> dp(m + 1, -1); dp[0] = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j] == -1) continue;
            int vi = abs(p[i].first), vj = abs(p[j].first), si = p[i].second, sj = p[j].second;
            if (p[j].first * p[i].first < 0) { // 不一样
                if (si - vj >= vi) dp[i] = max(dp[i], dp[j] + 1);
            }
            else {
                if (vj + si - sj >= vi) dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    // for (int i = 1; i <= m; i++) cout << dp[i] << ' ';
    // cout << '\n';

    int ans = 0;
    for (int i = 1; i <= m; i++) ans = max(ans, dp[i]);
    cout << ans << '\n';

    return 0;
}