#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
    ll n, x; cin >> n >> x;
    vector<ll> a(n), b(n), c(n);
    ll cnt = 0, mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
        cnt += (b[i] - 1) * a[i];
        mx = max(mx, b[i] * a[i] - c[i]);
    }
    // cout << cnt << ' ' << mx << '\n';
    ll ans = 0;
    if (mx == 0) {
        if (x > cnt) ans = -1;
        else ans = 0;
    }
    else ans = (max(x - cnt, 0ll) + mx - 1) / mx;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}