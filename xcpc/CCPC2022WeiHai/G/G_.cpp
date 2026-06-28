#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    freopen ("G.in", "r", stdin);
    ll x, n; cin >> x >> n;
    
    ll cnt = 0, x_ = x;
    while (x_) cnt += 1, x_ >>= 1;
    ll up = (1 << cnt);
    vector<ll> f(up + 1, 0);
    for (int i = 1; i <= up; i++) {
        f[i] = f[i - 1];
        if (__gcd((i * x) ^ x, x) == 1)
            f[i] += 1;
    }

    auto calc = [&] (ll r) {
        // if (up == 0) return 0ll;
        return f[up] * (r / up) + f[r % up];
    };

    while (n--) {
        ll l, r; cin >> l >> r;
        cout << calc(r) - calc(l - 1) << '\n';
    }
    return 0;
}