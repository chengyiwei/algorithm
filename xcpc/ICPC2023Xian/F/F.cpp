#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int MAXN = 50005;
constexpr ll MOD = 998244353;

string K;
ll P, X;
ll Fac[MAXN], Inv[MAXN];

ll qpow(ll a, ll b, ll mod = MOD) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}

ll C(ll n, ll m) {
    if (m == 0) return 1;
    ll ret = Fac[n] * Inv[m] % P * Inv[n - m] % P;
    return ret;
}


int rev[MAXN], limit, bit;

void NTT (vector<ll> &a, int op) {
    for (int i = 0; i < limit; i++)
        if (i < rev[i]) swap(a[i], a[rev[i]]);
    
    for (int m = 2; m <= limit; m <<= 1) {
        ll gn = qpow(3, (MOD - 1) / m); 
        if (op == -1) gn = qpow(gn, MOD - 2);
        for (int i = 0; i < limit; i += m) {
            ll gk = 1;
            for (int j = 0; j < m / 2; j++) {
                ll x = a[i + j], y = gk * a[i + j + m / 2] % MOD;
                a[i + j] = (x + y) % MOD;
                a[i + j + m / 2] = (x - y + MOD) % MOD;
                gk = gk * gn % MOD;
            }
        }
    }
}

void convolution(vector<ll> A, vector<ll> B, vector<ll> &C) {
    int n = A.size() - 1, m = B.size() - 1;
    limit = 1, bit = 0;
    while (limit <= n + m) limit <<= 1, bit += 1;
    for (int i = 0; i < limit; i++)
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (bit - 1));

    A.resize(limit), B.resize(limit); C.resize(limit);
    for (int i = n + 1; i < limit; i++) A[i] = 0;
    for (int i = m + 1; i < limit; i++) B[i] = 0;
    
    NTT(A, 1), NTT(B, 1);


    for (int i = 0; i < limit; i++)
        C[i] = A[i] * B[i] % MOD;
    NTT(C, -1);
    ll inv = qpow(limit, MOD - 2);
    for (int i = 0; i < limit; i++)
        C[i] = C[i] * inv % MOD;
}

int main() {
    freopen ("F.in", "r", stdin);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);
    std::cin >> K >> P >> X;
    
    int rt = 1;
    while (true) {
        bool ok = true;
        int v = 1;
        for (int i = 1; i < P - 1; i++) {
            v = v * rt % P;
            if (v == 1) {
                ok = false;
                break;
            }
        }
        if (ok) break;
        rt += 1;
    }

    vector<ll> lg(P, 0);
    for (int i = 0, v = 1; i < P - 1; i++) {
        lg[v] = i;
        v = v * rt % P;
    }

    Fac[0] = Inv[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        Fac[i] = Fac[i - 1] * i % P;
        Inv[i] = qpow(Fac[i], P - 2, P);
    }

    vector<ll> a(P - 1, 0), ret(P - 1, 0); ret[0] = 1;

    for (int i = 0; i < P; i++)
        for (int j = i; j < P; j++) {
            ll C_ = C(j, i) % P;
            a[lg[C_]] += 1;
        }


    // for (int i = 0; i < P - 1; i++)
    //     cout << a[i] << " ";
    // cout << '\n';
    
    for (int i = K.size() - 1; ~i; i--) {
        if (K[i] == '1') {
            convolution(a, ret, ret);
            for (int j = P - 1; j < limit; j++) ret[j - (P - 1)] = (ret[j] + ret[j - (P - 1)]) % MOD;
            ret.resize(P - 1);
        }
        convolution(a, a, a);
        for (int j = P - 1; j < limit; j++) a[j - (P - 1)] = (a[j] + a[j - (P - 1)]) % MOD;
        a.resize(P - 1);
    }

    cout << ret[lg[X]] << '\n';
    return 0;
}