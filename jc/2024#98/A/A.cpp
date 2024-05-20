#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll TT = 10007;

const int maxn = 1e3 + 5;
ll Fac[maxn], Inv[maxn];

ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % TT;
        a = a * a % TT;
        b >>= 1;
    }
    return res;
}

ll C(ll n, ll m) {
    if (n < m) return 0;
    return Fac[n] * Inv[m] % TT * Inv[n - m] % TT;
}

int main() {
    Fac[0] = 1;
    for (int i = 1; i < maxn; i++)
        Fac[i] = Fac[i - 1] * i % TT;
    Inv[maxn - 1] = qpow(Fac[maxn - 1], TT - 2);
    for (int i = maxn - 2; i >= 0; i--)
        Inv[i] = Inv[i + 1] * (i + 1) % TT;
    ll k, n, m, a, b; cin >> a >> b >> k >> n >> m;
    ll ret = 0;
    ret = C(k, n) * qpow(a, n) % TT * qpow(b, m) % TT;
    cout << ret << endl;
    return 0;
}