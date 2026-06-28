#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll TT = 1e9 + 7;

ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % TT;
        a = a * a % TT;
        b >>= 1;
    }
    return res;
}


ll f (ll n, ll k) {
    ll cnt = 0;
    while ((cnt + 1) * k < 10) 
        cnt += 1;
    ll res = qpow(cnt + 1, n);
    return res;
}

void solve() {
    ll l, r, k; cin >> l >> r >> k;
    ll R = f(r, k), L = f(l, k);
    ll ans = (R - L + TT) % TT;
    cout << ans << '\n';
}


int main() {
    freopen ("G.in", "r", stdin);
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}