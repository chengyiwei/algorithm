#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll g(ll n, ll t, ll k) {
    ll d = (n + (k - 1) - 1) / (k - 1);
    ll x = ((k - 1) * d - n) / d + 1;
    if (x >= t) return n + t * d;
    return g(n + x * d, t - x, k);
}

ll f(ll n, ll k) {
    if (n == 1) return 1;
    ll d = (n  + k - 1) / k;
    if (d == 1) return n;
    ll tmp = k * (d - 1);
    ll t = (n - tmp + d - 1) / d;
    return g(f(n - t * d, k), t, k);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while (T--) {
        ll n, k; cin >> n >> k;
        cout << f(n, k) << '\n';
    };

    return 0;
}