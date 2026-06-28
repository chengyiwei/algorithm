#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n, k, x; cin >> n >> k >> x;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    ll sum = 0;
    for (int i = 1; i <= n; i++) sum += a[i];
    ll cnt = (x - 1) / sum;
    ll ans = cnt * n;
    x -= cnt * sum;
    for (int i = n; i >= 1; i--) {
        if (x > a[i]) {
            x -= a[i];
            ans += 1;
        }
        else {
            break;
        }
    }
    cout << max(0ll, n * k - ans) << '\n';
    return;
}

int main() {
    // freopen ("B.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    while (T--) solve();
    return 0;
}