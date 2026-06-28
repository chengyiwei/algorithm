#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll MOD = 998244353;

ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void solve() {
    
    int n, q; cin >> n >> q;
    vector<vector<int>> mp(n + 1);
    for (int i = 2; i <= n; i++) {
        int f; cin >> f;
        mp[f].push_back(i); mp[i].push_back(f);
    }

    vector<int> dep(n + 1, 0);
    vector<array<int, 21>> f(n + 1);

    vector<ll> g(n + 1, 0);

    function<void(int, int)> dfs1 = [&] (int u, int fa) {
        dep[u] = dep[fa] + 1;
        f[u][0] = fa;
        for (int j = 1; j <= 20; j++) {
            f[u][j] = f[f[u][j - 1]][j - 1];
        }
        ll g_u = 1;
        for (int v : mp[u]) {
            if (v == fa) continue;
            dfs1(v, u);
            g_u = (g_u * (g[v] + 1)) % MOD;
        }
        g[u] = g_u;
    };

    dfs1(1, 0);

    function<int(int, int)> lca = [&] (int x, int y) {
        if (dep[x] < dep[y]) swap(x, y);
        for (int j = 20; j >= 0; j--) {
            if (dep[f[x][j]] >= dep[y]) x = f[x][j];
        }
        if (x == y) return x;
        for (int j = 20; j >= 0; j--) {
            if (f[x][j] != f[y][j]) x = f[x][j], y = f[y][j];
        }
        return f[x][0];
    };

    map<pair<int, int>, ll> b;
    function<ll(int, int)> dfs3 = [&] (int u, int fa) {
        if (b.count({u, fa})) return b[{u, fa}];
        ll res = 1;
        for (int v : mp[u]) {
            if (v == fa) continue;
            res = res * (dfs3(v, u) + 1) % MOD;
        }
        return b[{u, fa}] = res;
    };

    vector<ll> s_g(n + 1, 0), h(n + 1, 0);
    function<void(int, int)> dfs2 = [&] (int u, int fa) {
        s_g[u] = (s_g[fa] + g[u]) % MOD;
        if (u == 1) h[u] = g[u];
        else if (g[u] + 1 != MOD) h[u] = (h[fa] * qpow(g[u] + 1, MOD - 2) % MOD + 1) % MOD * g[u] % MOD;
        else h[u] = (dfs3(fa, u) + 1) * g[u] % MOD;
        for (int v : mp[u]) {
            if (v == fa) continue;
            dfs2(v, u);
        }
    };

    dfs2(1, 0);

    for (int i = 1; i <= n; i++) {
        // cout << i << " " << g[i] << ' ' << s_g[i] << ' ' << h[i] << '\n';
    }

    while (q--) {
        int u, v; cin >> u >> v;
        int l = lca(u, v);
        ll ans = ((s_g[u] + s_g[v] - 2 * s_g[l] + h[l]) % MOD + MOD) % MOD;
        cout << ans << '\n';
    }

}

int main() {
    freopen ("E.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}