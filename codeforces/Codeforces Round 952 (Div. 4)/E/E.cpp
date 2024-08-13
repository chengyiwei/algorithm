#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int x, y, z; cin >> x >> y >> z; int k; cin >> k;
    int ans = 0;
    for (int x_ = 1; x_ <= x; x_ += 1) {
        for (int y_ = 1; y_ <= y && x_ * y_ <= k; y_ += 1) {
            int z_ = k / (x_ * y_);
            if (x_ * y_ * z_ != k || z_ > z) continue;
            int now = (x - x_ + 1) * (y - y_ + 1) * (z - z_ + 1);
            ans = max(ans, now);
        }
    }
    cout << ans << '\n';
}

signed main() {
    freopen ("E.in", "r", stdin);
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}