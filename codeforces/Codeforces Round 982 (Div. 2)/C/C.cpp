#include <bits/stdc++.h>
#define int long long
using namespace std;

using ll = long long;

void solve() {
    int n; cin >> n;
    vector<ll> a(n + 1);
    map<ll, vector<ll>> g; g.clear();

    auto add_e = [&](int u, int v) {
        g[u].push_back(v);
        // cout << u << " " << v << "\n";
    };

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 2; i <= n; i++) 
        add_e(a[i] + i - 1, a[i] + i - 1 + i - 1);

    ll ans = n;
    queue<ll> q;
    map<ll, int> vis;
    vis[n] = 1; q.push(n);
    while (!q.empty()) {
        ll u = q.front(); q.pop();
        ans = max(ans, u);
        for (ll v : g[u]) {
            if (!vis[v]) {
                vis[v] = 1;
                q.push(v);
            }
        }
    }

    cout << ans << "\n";
}

signed main() {
    freopen ("C.in", "r", stdin);

    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int T; cin >> T;
    while (T--) solve();
}