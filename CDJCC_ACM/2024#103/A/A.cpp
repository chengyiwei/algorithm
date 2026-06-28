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

ll inv(ll x) {
    return qpow(x, TT - 2);
}

ll add (ll a, ll b) {
    return ((a + b) % TT + TT) % TT;
}

ll mul (ll a, ll b) {
    return (a * b % TT + TT) % TT;
}

int main() {
    ll n, x;
    cin >> n >> x;
    if (x == 1) {
        cout << mul(mul(n, (n + 1)), inv(2)) << endl;
        return 0; 
    }
    ll sum1 = mul(mul(add(qpow(x, n - 1), -1) , inv(x - 1)), qpow(x, 2));
    ll up = add(add(mul(n, qpow(x, n + 1)), -x), -sum1);
    ll dn = add(x, -1);
    ll ans = mul(up, inv(dn));
    cout << ans << endl;
    return 0;
}