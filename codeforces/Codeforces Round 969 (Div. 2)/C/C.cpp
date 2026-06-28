#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int main() {
    freopen ("C.in", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n, a, b; cin >> n >> a >> b;
        int g = __gcd(a, b);
        vector<int> c(n + 1);
        for (int i = 1; i <= n; i++) cin >> c[i];
        for (int i = 1; i <= n; i++) c[i] = c[i] % g;
        auto c_ = c;
        sort(c_.begin() + 1, c_.end());
        c_.erase(unique(c_.begin() + 1, c_.end()), c_.end());
        int m = c_.size() - 1;
        int ans = INF;
        for (int i = 1; i <= m; i++) {
            int pre = (i == 1) ? m : i - 1;
            int now = (c_[pre] - c_[i] + g) % g;
            ans = min(ans, now);
        }
        cout << ans << '\n';
    }
    return 0;
}