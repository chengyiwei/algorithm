#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    freopen ("P3806.in", "r", stdin);
    freopen ("P3806.out", "w", stdout);
    ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> g(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    
    vector<int> siz(n + 1, 0), max_son(n + 1, 0), vis(n + 1, 0);

    function<int(int)> get_root = [&] (int u) -> int{
        int res = 0;
        function<void(int, int)> dfs = [&] (int u, int fa) {
            siz[u] = 1; max_son[u] = 0;
            for (auto [v, w] : g[u]) {
                if (v == fa || vis[v]) continue;
                dfs(v, u);
                siz[u] += siz[v];
                max_son[u] = max(max_son[u], siz[v]);
            }
            max_son[u] = max(max_son[u], n - siz[u]);
            if (res == 0 || max_son[u] < max_son[res])
                res = u;
        };
        dfs(u, 0);
        return res;
    };

    function<vector<int>(int)> get_dis = [&](int u) -> vector<int>{
        vector<int> res;
        function<void(int, int, int)> dfs = [&] (int u, int fa, int d) {
            res.push_back(d);
            for (auto [v, w] : g[u]) {
                if (v == fa || vis[v]) continue;
                dfs(v, u, d + w);
            }
        };
        dfs(u, 0, 0);  
        return res;
    };
    
    function<ll(int, int)> solve = [&](int u, int k) -> ll {
        auto dis = get_dis(u);
        sort(dis.begin(), dis.end());
        vector<pair<int, int>> cnt;
        for (auto x : dis) {
            if (cnt.empty() || cnt.back().first != x) cnt.push_back({x, 1});
            else cnt.back().second++;
        }
        int res = 0;
        for (auto [x, y] : cnt) {
            if (k % 2 == 0 && x == k / 2) res += 1ll * y * (y - 1) / 2;
            else if (x < k / 2){
                auto it = lower_bound(cnt.begin(), cnt.end(), make_pair(k - x, 0));
                if (it != cnt.end() && it -> first == k - x)
                    res += 1ll * y * it -> second;
            }
        }
        return res;
    };

    function<ll(int, int)> dfs = [&](int u, int k) -> ll {
        int root = get_root(u);
        vis[root] = 1;
        ll res = solve(root, k);
        for (auto [v, w] : g[root]) {
            if (vis[v]) continue;
            res -= solve(v, k);
        }
        for (auto [v, w] : g[root]) {
            if (vis[v]) continue;
            res += dfs(v, k);
        }
        return res;
    };

    while (m--) {
        int k; cin >> k;
        ll ans = dfs(1, k);
        // cout << ans << '\n';
        cout << (ans ? "AYE" : "NAY") << '\n';
    }
    return 0;
}