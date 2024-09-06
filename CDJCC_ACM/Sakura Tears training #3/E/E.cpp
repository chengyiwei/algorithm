#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5005;
typedef long long ll;
const int MOD = 1e9 + 7;

ll fac[MAXN], inv[MAXN];

ll qpow (ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void init_() {
    fac[0] = 1;
    for (int i = 1; i < MAXN; i++)
        fac[i] = fac[i - 1] * i % MOD;
    inv[MAXN - 1] = qpow(fac[MAXN - 1], MOD - 2);
    for (int i = MAXN - 2; i >= 0; i--)
        inv[i] = inv[i + 1] * (i + 1) % MOD;
}

ll C(int n, int m) {
    if (n < m) return 0;
    return fac[n] * inv[m] % MOD * inv[n - m] % MOD;
}

void solve() {
    int n; cin >> n;
    ll ans = 1;
    for (int k = 1; k <= n; k++) {
        if (2 * k + 1 > n) {
            ans = (ans + (2 * k + 1) * C(n, k) % MOD) % MOD;
        }
        else {
            for (int mex = k + 1; mex <= 2 * k + 1; mex++) {
                ans += 1ll * mex * C(mex - 1, mex - (k + 1)) % MOD * C(n - mex, k - (mex - (k + 1))) % MOD;
                ans %= MOD;
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    freopen ("E.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    init_();
    int T; cin >> T;
    while (T--) solve();
    return 0;
}