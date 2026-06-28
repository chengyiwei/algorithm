#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
constexpr i64 MX = 1e12;

void solve() {
    i64 x, y, k; cin >> x >> y >> k;
    if (y == 1) {cout << -1 << '\n'; return ;}
    i64 n = x;
    while (n > 0) {
        i64 r = (k - 1) / (y - 1);
        if (r == 0) { cout << k << '\n';return ; }
        i64 a = min(((r + 1) * (y - 1) - k) / r + 1, n);
        n -= a; k += a * r;
        if (k > MX) {cout << -1 << '\n'; return ;}
    }
    cout << k << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) solve();
    return 0;
}