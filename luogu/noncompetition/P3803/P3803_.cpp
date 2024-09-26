//NTT

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 5e6 + 10;
const int MOD = 998244353;

int n, m, a[MAXN], b[MAXN], limit, bit;
int rev[MAXN];

void NTT(vector<int> *a, int op) {

}

ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void NTT (int a[], int op) {
    for (int i = 0; i < limit; i++)
        if (i < rev[i]) swap(a[i], a[rev[i]]);
    for (int mid = 1; mid < limit; mid <<= 1) {
        ll gn = qpow(3, (MOD - 1) / (mid << 1));
        if (op == -1) gn = qpow(gn, MOD - 2);
        for (int j = 0, R = mid << 1; j < limit; j += R) {
            ll g = 1;
            for (int k = 0; k < mid; k++, g = g * gn % MOD) {
                ll x = a[j + k], y = g * a[j + k + mid] % MOD;
                a[j + k] = (x + y) % MOD;
                a[j + k + mid] = (x - y + MOD) % MOD;
            }
        }
    }
}

int main() {
    freopen ("P3803.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i <= n; i++) cin >> a[i];
    for (int i = 0; i <= m; i++) cin >> b[i];

    limit = 1;
    while (limit <= n + m) limit <<= 1, bit += 1;
    for (int i = 0; i < limit; i++) 
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (bit - 1));

    NTT(a, 1); NTT(b, 1);
    for (int i = 0; i < limit; i++) a[i] = 1ll * a[i] * b[i] % MOD;
    NTT(a, -1);
    ll inv = qpow(limit, MOD - 2);
    for (int i = 0; i <= n + m; i++) cout << a[i] * inv % MOD << ' ';
    cout << '\n';
}