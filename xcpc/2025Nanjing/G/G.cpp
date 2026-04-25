#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1, 0), b(n + 1, 0);

    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    sort(a.begin() + 1, a.end());
    reverse(a.begin() + 1, a.end());
    sort(b.begin() + 1, b.end());

    vector<ll> sum_a(n + 1, 0), sum_b(n + 1,0);
    
    for (int i = 1; i <= n; i++) sum_a[i] = sum_a[i - 1] + a[i];
    for (int i = 1; i <= n; i++) sum_b[i] = sum_b[i - 1] + b[i];

    int q; cin >> q;

    while (q--) {
        int t; cin >> t;
        int l = 1, r = n + 1;
        while (l + 1 < r) {
            int mid = (r + l) / 2;
            if (a[mid] - t * b[mid] >= 0) l = mid;
            else r = mid;
        }
        cout << max(sum_a[l] - 1ll * t * sum_b[l], 0ll) << ' ';
    }
    cout << '\n';
}

signed main() {
    // freopen ("out.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) solve();
    return 0;
}