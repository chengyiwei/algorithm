#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;

void solve() {
    int n; cin >> n; ll m; cin >> m;
    map<int, ll> mp;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i], mp[a[i]] += 1;

    ll ans = 0;
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        ll cnt = min(it->second, m / it->first);
        ans = max(ans, cnt * it->first);

        auto nxt = next(it);
        if (nxt == mp.end()) continue;
        if (it -> first + 1 != nxt -> first) continue;
        if (it -> first * it->second + nxt->first * nxt->second <= m) {
            ans = max(ans, it->first * it->second + nxt->first * nxt->second);
            continue;
        }
        ll max_y = min(m / nxt->first, nxt->second), min_y = max(0ll, (m - it->first * it->second + nxt->first - 1) / nxt->first);
        ll k_up = (m - min_y) / it->first, k_dn = (m - max_y + it->first - 1) / it->first;
        if (k_up >= k_dn) {
            ll y = m - k_dn * it->first;
            ll x = min(it->second, (m - y * nxt->first) / it->first);
            ll now = x * it->first + y * nxt->first;
            ans = max(ans, now);
        }
        else {
            ll y = max_y;
            ll x = min(it->second, (m - y * nxt->first) / it->first);
            ll now = x * it->first + y * nxt->first;
            ans = max(ans, now);
        }
    }
    cout << ans << '\n';
}

signed main() {
    freopen ("B.in", "r", stdin);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}