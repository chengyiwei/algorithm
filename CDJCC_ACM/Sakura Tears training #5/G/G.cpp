#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    freopen ("G.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<ll> a(2 * n + 1, 0), sum(2 * n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= 2 * n; i++) sum[i] = sum[i - 1] + a[i];
    bitset<200005> dp;
    dp[1] = 1;
    ll ans = 0;
    for (int i = 1; i <= 2 * n; i++) {
        dp |= dp << a[i];
        if (dp[i]) {
            ans = max(ans, sum[i] - i + 1);
            dp[i] = 0;
        }
    }
    cout << ans << '\n';
    return 0;
}