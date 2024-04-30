#include <bits/stdc++.h>
#define pb emplace_back
#define fst first
#define scd second
#define mkp make_pair
#define mems(a, x) memset((a), (x), sizeof(a))

using namespace std;
typedef long long ll;
typedef double db;
typedef unsigned long long ull;
typedef long double ldb;
typedef pair<ll, ll> pii;

const int maxn = 1000100;
const ll mod = 998244353;

inline ll qpow(ll b, ll p) {
    ll res = 1;
    while (p) {
        if (p & 1) {
            res = res * b % mod;
        }
        b = b * b % mod;
        p >>= 1;
    }
    return res;
}

ll n, pw[maxn], c[maxn], f[maxn], g[maxn], b[maxn], h[maxn];
char s[maxn];

struct node {
    ll pre, mul, len;
    node(ll a = 0, ll b = 0, ll c = 0) : pre(a), mul(b), len(c) {}
} a[maxn << 2];

inline node operator + (const node &a, const node &b) {
    node res;
    res.pre = (a.pre + b.pre + a.mul % mod * c[b.len] % mod) % mod;
    res.mul = (a.mul * pw[b.len] % mod + b.mul) % mod;
    res.len = a.len + b.len;
    return res;
}

inline void pushup(int x) {
    a[x] = a[x << 1] + a[x << 1 | 1];
}

void build(int rt, int l, int r) {
    if (l == r) {
        int x = (isdigit(s[l]) ? s[l] - '0' : 0);
        a[rt].pre = a[rt].mul = x;
        a[rt].len = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    pushup(rt);
}

node query(int rt, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) {
        return a[rt];
    }
    int mid = (l + r) >> 1;
    if (qr <= mid) {
        return query(rt << 1, l, mid, ql, qr);
    } else if (ql > mid) {
        return query(rt << 1 | 1, mid + 1, r, ql, qr);
    } else {
        return query(rt << 1, l, mid, ql, qr) + query(rt << 1 | 1, mid + 1, r, ql, qr);
    }
}

void solve() {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    pw[0] = 1;
    for (int i = 1; i <= n + 1; ++i) {
        pw[i] = pw[i - 1] * 10 % mod;
        b[i] = b[i - 1] + isdigit(s[i]);
        c[i] = (c[i - 1] + pw[i]) % mod;
    }
    build(1, 1, n);
    int p = n + 1, q = n + 1;
    ll ans = 0;
    for (int i = n; i; --i) {
        if (s[i] == '*') {
            p = i;
            continue;
        }
        if (s[i] == '+') {
            q = i;
            continue;
        }
        node u = query(1, 1, n, i, min(p, q) - 1);
        g[i] = u.pre;
        h[i] = u.mul;
        if (p < q) {
            g[i] = (g[i] + u.mul * g[p + 1]) % mod;
            h[i] = h[i] * h[p + 1] % mod;
        }
        f[i] = (g[i] + f[q + 1] + h[i] * (b[n] - b[q])) % mod;
        ans = (ans + f[i]) % mod;
    }
    printf("%lld\n", ans);
}

int main() {
    int T = 1;
    // scanf("%d", &T);
    while (T--) {
        solve();
    }
    return 0;
}
