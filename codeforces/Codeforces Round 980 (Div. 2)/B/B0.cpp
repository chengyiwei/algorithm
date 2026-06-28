#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n; ll k; cin >> n >> k;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin() + 1, a.end());
    ll L = 0, R = 1e9 + 10;

    ll ans = 0;

    auto check = [&] (ll mid) {
        ll cnt = 0, ret = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] < mid) cnt += a[i], ret += a[i] + 1;
            else cnt += mid, ret += mid;
        }
        if (cnt >= k) {
            return true;
        }
        return false;
    };

    while (L + 1 < R) {
        ll mid = (R - L) / 2 + L;
        if (check(mid)) R = mid;
        else L = mid;
    }

    for (int i = 1; i <= n; i++) 
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