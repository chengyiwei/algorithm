#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n; ll k; cin >> n >> k;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin() + 1, a.end());
    ll dn = 0, have = 0, ans = 0;
    for (int i = 1, j; i <= n;) {
        j = i;
        while (j <= n && a[j] == a[i]) j++;
        int len = j - i;
        if ((a[i] - dn) * (n - i + 1) + have >= k) {
            ll now = k - have;
            ans += now;
            cout << ans << '\n';
            return;
        }
        ans += len + (a[i] - dn) * (n - i + 1);
        have += (a[i] - dn) * (n - i + 1);
        dn = a[i];
        i = j;
    }
    cout << ans << '\n';
}

int main() {
    freopen ("B.in", "r", stdin);
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr); cout.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}