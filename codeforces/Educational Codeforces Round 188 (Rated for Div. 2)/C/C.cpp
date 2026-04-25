#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

ll lcm(ll a, ll b, ll c) {
    return lcm(a, lcm(b, c));
}

void solve() {
    ll a, b, c, m; cin >> a >> b >> c >> m;
    ll ans1 = m / a * 6 - m / lcm(a, b) * 3 - m / lcm(a, c) * 3 + m / lcm(a, b, c) * 2;
    ll ans2 = m / b * 6 - m / lcm(a, b) * 3 - m / lcm(b, c) * 3 + m / lcm(a, b, c) * 2;
    ll ans3 = m / c * 6 - m / lcm(a, c) * 3 - m / lcm(b, c) * 3 + m / lcm(a, b, c) * 2;
    cout << ans1 << ' ' << ans2 << ' ' << ans3 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}