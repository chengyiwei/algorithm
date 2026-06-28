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
    vector<ll> a(n + 1), cnt(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 2; i <= n; i++) {
        if (a[i] == 1 && a[i - 1] != 1) {cout << -1 << '\n'; return ;}
        if (a[i] <= a[i - 1]) {
            ll num = 0, now = a[i];
            while (now < a[i - 1]) {
                now = now * now;
                num += 1;
            }
            cnt[i] = cnt[i - 1] + num;
        }
        else {
            ll num = 0, now = a[i - 1];
            if (now == 1) continue;
            while (now <= a[i]) {
                now = now * now;
                num += 1;
            }
            num -= 1;
            cnt[i] = max(cnt[i - 1] - num, 0ll);
        }
    }
    ll ans = 0;
    // for (int i = 1; i <= n; i++) cout << cnt[i] << ' ';
    for (int i = 1; i <= n; i++) ans += cnt[i];
    cout << ans << '\n';
}

int main() {
    freopen ("C.in", "r", stdin);
    freopen ("C.out", "w", stdout);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}