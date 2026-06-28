#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, m, k, b; cin >> n >> m >> k >> b;
    int ans1 = 0, ans2 = 0;
    for (int i = 1; i <= n; i++) {
        int now1 = 0, now2 = 0;
        for (int j = 1; j <= m; j++) {
            int x, x_; cin >> x; x_ = x;
            if (x_ < 1) x_ += 1;
            else x_ -= 1;
            now1 += x, now2 += x_;
        }
        if (now1 >= k) ans1 += 1;
        else {
            if (now2 >= k) ans2 += 1;
        }
    }

    cout << ans1 + min(ans2, b) << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
    return 0;
}