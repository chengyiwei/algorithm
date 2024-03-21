#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> pii;
const int INF = 1e18;
void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n + 1), d(m + 1), f(k + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> d[i];
    for (int i = 1; i <= k; i++) cin >> f[i];
    pii mx1 = {-1,0}, mx2 = {-1,0};
    for (int i = 1; i < n; i++) {
        int x = a[i + 1] - a[i];
        if (x > mx1.first) { mx2 = mx1; mx1 = {x, i}; }
        else if (x > mx2.first) { mx2 = {x, i}; }
    }
    if (mx1.first == mx2.first) {
        cout << mx1.first << '\n';
        return ;
    }
    // 把 pos1 的位置拆开
    int mid = (a[mx1.second] + a[mx1.second + 1]) / 2;
    sort (d.begin() + 1, d.end());
    sort (f.begin() + 1, f.end());
    int ret = mx1.first;
    for (int i = 1; i <= m; i++) {

        auto check = [&](int pos) {
            if (pos < 1 || pos > k) return INF;
            int x = d[i] + f[pos];
            if (!(x > a[mx1.second] && x < a[mx1.second + 1])) return INF;
            return max (x - a[mx1.second], a[mx1.second + 1] - x);
        };

        int pos = lower_bound(f.begin() + 1, f.end(), mid - d[i]) - f.begin();
        ret = min (ret, check(pos));
        ret = min (ret, check(pos - 1));
        ret = min (ret, check(pos + 1));
    }
    cout << max (mx2.first, ret) << '\n';
}

signed main() {
    freopen ("F.in", "r", stdin);
    int t; cin >> t;
    while (t--) solve();
}