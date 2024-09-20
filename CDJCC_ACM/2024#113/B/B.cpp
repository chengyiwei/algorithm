#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin() + 1, a.end());
    ll pre = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = (ans + pre * a[i]) % MOD;
        pre = (pre + a[i]) % MOD;
    }
    ll cnt = 1ll * n * (n - 1) / 2; cnt %= MOD;
    cout << ans * qpow(cnt, MOD - 2) % MOD << endl;
}

int main() {
    freopen ("B.in", "r", stdin);
    ios::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}