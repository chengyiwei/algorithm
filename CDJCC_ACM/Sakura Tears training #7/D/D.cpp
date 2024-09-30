#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    int m = *max_element(a.begin() + 1, a.end());
    vector<int> dp(m + 1, 0), cnt(m + 1, 0);
    for (int i = 1; i <= n; i++) cnt[a[i]] += 1;
    for (int i = 1; i <= m; i++) {
        dp[i] += cnt[i];
        for (int j = 2; i * j <= m; j++)
            dp[i * j] = max(dp[i * j], dp[i]);
    }
    cout << n - *max_element(dp.begin() + 1, dp.end()) << '\n';
}

int main() {
    freopen ("D.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}