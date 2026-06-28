#include <bits/stdc++.h>

constexpr int MAXN = 2e6 + 10, MOD = 998244353;
using ll = long long;

int n;
int a[MAXN], b[MAXN];

int qpow (int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = 1ll * res * a % MOD;
        a = 1ll * a * a % MOD;
        b >>= 1;
    }
    return res;
}

int limit, bit, rev[MAXN];

void change(int a[], int n) {
    for (int i = 0; i < n; i++)
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (bit - 1));
    for (int i = 0; i < n; i++)
        if (i < rev[i]) std::swap(a[i], a[rev[i]]);
}

void NTT(int a[], int op) {
    change(a, limit);
    for (int m = 2; m <= limit; m <<= 1) {
        ll gn = qpow(3, (MOD - 1) / m);
        if (op == -1) gn = qpow(gn, MOD - 2);
        for (int i = 0; i < limit; i += m) {
            ll gk = 1;
            for (int j = 0; j < (m >> 1); j++) {
                ll x = a[i + j], y = a[i + j + (m >> 1)] * gk % MOD;
                a[i + j] = (x + y) % MOD;
                a[i + j + (m >> 1)] = (x - y + MOD) % MOD;
            }
        }
    }
}

int main() {
    std::cin >> n;
    for (int i = 0; i <= n; i++) std::cin >> a[i];
    for (int i = 0; i <= n; i++) std::cin >> b[i];
    for (bit = 0, limit = 1; limit <= n << 1; bit++, limit <<= 1);
    
}