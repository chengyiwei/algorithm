#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int main() {
    freopen ("F.in", "r", stdin);
    int n, m, k; cin >> n >> m >> k;
    vector<vector<pii> > g(n + 1);
    for (int i = 1; i <= m; i++) {
        int u,v; cin >> u >> v;
        g[u].push_back({v, i});
        g[v].push_back({u, i});
    }

    int Y = 0;
    vector<int> ans, vis(n + 1, 0), cur(n + 1, 0);
    function<void(int)> dfs = [&](int u) {
        vis[u] = 1;
        for (auto [v, id] : g[u]) {
            if (vis[v]) continue;
            dfs (v);
            if (cur[v] == 0 && Y < k) { 
                Y -= cur[u] + cur[v];
                cur[u] ^= 1; cur[v] ^= 1;
                Y += cur[u] + cur[v];
                ans.push_back(id);
            }
        }
    };

    for (int i = 1; i <= n; i++) 
        if (!vis[i]) dfs(i);
    
    if (Y != k) cout << "No" << endl;
    else {
        cout << "Yes" << endl;
        cout << ans.size() << endl;
        for (auto x : ans) cout << x << " ";
        cout << endl;
    }
    return 0;
}