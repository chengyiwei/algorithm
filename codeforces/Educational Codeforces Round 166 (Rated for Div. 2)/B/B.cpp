#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e18;
void solve() {
    int n; cin >> n;
    vector<int> a(n + 2, 0), b(n + 2, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n + 1; i++) cin >> b[i];
    int add = inf, ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += abs(a[i] - b[i]);
        if (b[n + 1] <= max(a[i], b[i]) && b[n + 1] >= min(a[i], b[i]))
            add = 0;
        else 
            add = min(add, min(abs(b[n + 1] - max(a[i], b[i])), abs(b[n + 1] - min(a[i], b[i]))));
    }
    cout << ans + add + 1 << '\n';
}

signed main() {
    freopen ("B.in", "r", stdin);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}