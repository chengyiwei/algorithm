#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll m, k, h; cin >> m >> k >> h;
    
    if (h == 0) {cout << 0 << "\n"; return ;}

    ll L = 0, R = h;

    auto check = [&] (ll x) -> bool {
        if (x < m) return x >= h;
        if (m == k) return true;
        ll add = ((x - m) + (m - k)) / (m - k) * k;
        return add + x >= h;
    };

    while (L + 1 < R) {
        ll mid = (L + R) >> 1;
        if (check(mid)) R = mid;
        else L = mid;
    }

    cout << R << "\n";
}

int main() {
    freopen ("I.in", "r", stdin);
    ios::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}