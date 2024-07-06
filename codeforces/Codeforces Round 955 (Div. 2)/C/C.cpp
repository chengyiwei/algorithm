#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;

void solve() {
    int n; ll l, r; cin >> n >> l >> r;
    vector<ll> a(n + 1), sum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    deque<int> dq;
    vector<int> dp(n + 1, 0);
    int pos = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        while (pos <= i && sum[i] - sum[pos] >= l) {
            while (!dq.empty() && dp[dq.back()] <= dp[pos]) {
                dq.pop_back();
            }
            dq.push_back(pos++);
        }
        while (!dq.empty() && sum[i] - sum[dq.front()] > r) {
            dq.pop_front();
        }
        dp[i] = dp[i - 1];
        if (!dq.empty()) {
            dp[i] = max(dp[i], dp[dq.front()] + 1);
        }
    }
    cout << dp[n] << '\n';
}

signed main() {
    freopen ("J.in", "r", stdin);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}