#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

const int N = 3e7 + 5;

ll fac[N], inv[N];

ll fast_pow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void init() {
    fac[0] = 1;
    for (int i = 1; i < N; i++) fac[i] = fac[i - 1] * i % MOD;
    inv[N - 1] = fast_pow(fac[N - 1], MOD - 2);
    for (int i = N - 2; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % MOD;
}

ll C(int n, int m) {
    if (n < m || m < 0) return 0;
    return fac[n] * inv[m] % MOD * inv[n - m] % MOD;
}

int main() {
    init();
    int n, m; cin >> n >> m;
    int odd = n / 2 + 1, even = n + 1 - odd;
    ll x1 = C(odd + m, m), x2 = C(even + m, m);
    ll y1 = C(odd + m - 1, m), y2 = C(even + m - 1, m);
    cout << ((x1 * y2 % MOD + x2 * y1 % MOD - y1 * y2 % MOD) % MOD + MOD) % MOD << '\n';
    return 0;
}