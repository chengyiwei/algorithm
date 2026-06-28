#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll TT = 1e9 + 7;

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
    freopen ("A.in", "r", stdin);
    ios::sync_with_stdio(false);
    ll n, k; cin >> n >> k;
    vector<ll> f(k + 2, 0);
    for (int i = 1; i <= k + 1; i++) {
        ll now = qpow(i, k);
        f[i] = (f[i - 1] + now) % TT;
    }
    ll ans = 0;
    
}