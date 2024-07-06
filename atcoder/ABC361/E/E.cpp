#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int, int> pii;

signed main() {
    freopen ("E.in", "r", stdin);
    ios::sync_with_stdio(0);
    int n, ans = 0; cin >> n;
    vector<vector<pii>> g(n + 1, vector<pii>());
    for (int i = 1; i < n; i++) {
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({v, w}); g[v].push_back({u, w});
        ans += 2 * w;
    }
    
    int max_x = 0;
    auto dfs = [&] (auto && dfs, int u, int f) -> int{
        int d1 = 0, d2 = 0;
        for (auto [v, w] : g[u]) {
            if (v == f) continue;
            int d = dfs(dfs, v, u) + w;
            if (d > d1) d2 = d1, d1 = d;
            else if (d > d2) d2 = d;
        }
        max_x = max(max_x, d1 + d2);
        return d1;
    };

    dfs(dfs, 1, 0);
    cout << ans - max_x << endl;
    return 0;
}