#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll TT = 998244353;

ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % TT;
        a = a * a % TT;
        b >>= 1;
    }
    return res;
}

int main() {
    int n, m; cin >> n >> m;
    const ll _m = qpow(m - 1, TT - 2);
    for (int i = 1; i <= m; i++) {
        int x = i;
        ll p = ( (m - x) * _m % TT + TT) % TT;
        ll q = qpow(p, n);
        printf("%lld ", q);
    }
    return 0;
}