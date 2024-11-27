#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen ("E.in", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    
    vector<vector<int> > g(n + 1);
    
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v); g[v].push_back(u);
    }
    
    vector<array<int, 21> > F(n + 1);
    vector<int> f(n + 1), dep(n + 1, 0);
    vector<int> s_f(n + 1, 0), s(n + 1, 0);
    
    function<void(int, int)> dfs = [&](int u, int fa) {
        F[u][0] = fa; dep[u] = dep[fa] + 1;
        for (int v : g[u]) {
            f[u] ^= v;
            if (v == fa) continue;
            dfs(v, u);
        }
    };
    dfs(1, 0);

    function<void(int, int)> dfs2 = [&](int u, int fa) {
        s_f[u] = s_f[fa] ^ f[u];
        for (int v : g[u]) {
            if (v == fa) continue;
            dfs2(v, u);
        }
    };
    dfs2(1, 0);

    for (int j = 1; j <= 20; j++)
        for (int i = 1; i <= n; i++)
            F[i][j] = F[F[i][j - 1]][j - 1];

    function<int(int, int)> lca = [&] (int u, int v){
        if (dep[u] < dep[v]) swap(u, v);
        for (int i = 20; i >= 0; i--)
            if (dep[F[u][i]] >= dep[v]) u = F[u][i];
        if (u == v) return u;
        for (int i = 20; i >= 0; i--)
            if (F[u][i] != F[v][i]) u = F[u][i], v = F[v][i];
        return F[u][0];
    };

    
    while (q--) {
        int u, v; cin >> u >> v;
        int l = lca(u, v);
        int res = s_f[u] ^ s_f[v] ^ f[l] ^ u ^ v;
        cout << res << '\n';
    }
    return 0;
}