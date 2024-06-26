#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve() {
    int n; cin >> n; ll ans = 0;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    map<pii, ll> mp;
    for (int i = 1; i <= n; i++) {
        ll now = 0;
        auto [up, dn] = pii(a[i], i);
        for (int k = 1; ; k++) {
            if (up * k > n || dn * k > n) break;
            now += mp[{up * k, dn * k}];
        }

        for (int k = 1; ; k++) {
            if (dn * k > n) break;
            mp[{dn * k, up}] += 1;
        }
        ans += now;
    }
    cout << ans << '\n';
}

int main() {
    freopen ("G.in", "r", stdin);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}