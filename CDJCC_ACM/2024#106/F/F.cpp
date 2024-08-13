#include <bits/stdc++.h>
using namespace std;
typedef __int128 ll;
const ll TT = 998244353;

ll n, siz;

ll read() {
    ll x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}

void print(ll x) {
    if (x < 0) { putchar('-'); x = -x; }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
} 

ll qpow (ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % TT;
        a = a * a % TT;
        b >>= 1;
    }
    return res;
}

ll dfs (ll p) {
    if (p == 1) return n;
    if (p % 2 == 0) {
        ll cur = dfs(p / 2);
        return (cur + qpow(10, siz * (p / 2)) * cur) % TT;
    }
    else {
        ll cur = dfs(p / 2);
        return (cur + qpow(10, siz * (p / 2)) * cur + n * qpow(10, siz * (p - 1))) % TT;
    }
}

ll log10(ll x) {
    ll ret = 0;
    do {
        x /= 10;
        ret++;
    } while (x);
    return ret;
}

int main() {
    n = read();
    siz = log10(n);
    ll ret = dfs(n);
    print(ret);
}