#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;

void solve() {
    int n; cin >> n; int m; cin >> m;
    vector<ll> a(n), s(2 * n);
    for (int i = 0; i < n; i++) cin >> a[i];
    s[0] = a[0];
    for (int i = 1; i < n; i++) s[i] = s[i - 1] + a[i];
    for (int i = n; i < 2 * n; i++) s[i] = s[i - 1] + a[i - n];

    auto calc = [&] (int x) -> ll {
        if (x == -1) return 0;
        int cnt = (x + 1) / n;
        int rem = (x + 1) % n;
        ll ret = 0;
        ret += cnt * s[n - 1];
        ret += s[cnt + rem - 1] - (cnt - 1 < 0 ? 0 : s[cnt - 1]);
        return ret;
    };

    while (m--) {
        int l, r; cin >> l >> r; l--; r--;
        cout << calc(r) - calc(l - 1) << '\n';
    }
}

signed main() {
    freopen ("A.in", "r", stdin);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}