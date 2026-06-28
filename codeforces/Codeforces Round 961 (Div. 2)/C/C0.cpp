#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const ll TT = 998244353;
const ld l = 1.0;
ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % TT;
        a = a * a % TT;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n; cin >> n;
    vector<ll> a(n + 1), cnt(n + 1, 0), b(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i]; b[1] = a[1];
    for (int i = 2; i <= n; i++) {
        if (a[i] == 1 && a[i - 1] != 1) {cout << -1 << '\n'; return ;}
        ll now = a[i];
        while (now < b[i - 1]) {
            now = now * now;
            cnt[i] += 1;
        }
        b[i] = now;
    }
    ll ans = 0;
    // for (int i = 1; i <= n; i++) cout << cnt[i] << ' ';
    for (int i = 1; i <= n; i++) ans += cnt[i];
    cout << ans << '\n';
}

int main() {
    freopen ("C.in", "r", stdin);
    freopen ("C0.out", "w", stdout);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}