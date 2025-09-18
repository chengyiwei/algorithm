#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;

void solve() {
    int n; cin >> n;
    vector<long long> Fac(n + 1, 1);

    for (int i = 1; i <= n; i++) Fac[i] = (Fac[i - 1] * i) % MOD;

    vector<vector<int>> g(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v); g[v].push_back(u);
    }

    vector<int> dep(n * 2 + 1, 0), lg(n * 2 + 1, 0);
    vector<array<int, 21>> st(n * 2 + 1, array<int, 21>());
    int tot = 0;
    vector<int> E(n * 2 + 1, 0), dfn(n + 1, 0);

    function<void(int, int)> dfs = [&] (int u, int fa) {
        dfn[u] = ++tot; E[tot] = u;
        dep[u] = dep[fa] + 1;
        for (int &v : g[u]) {
            if (v == fa) continue;
            dfs(v, u);
            E[++tot] = u;
        }
    };

    function<void(void)> build = [&] {
        lg[0] = -1;
        for (int i = 1; i <= tot; i++) lg[i] = lg[i >> 1] + 1;

        for (int i = 1; i <= tot; i++) st[i][0] = E[i];
        for (int j = 1; j <= 20; j++) {
            for (int i = 1; i + (1 << j) - 1 <= tot; i++) {
                int x = st[i][j - 1], y = st[i + (1 << (j - 1))][j - 1];
                st[i][j] = dep[x] < dep[y] ? x : y;
            }
        }
    };

    function<int(int, int)> lca = [&] (int u, int v) -> int {
        if (dfn[u] > dfn[v]) swap(u, v);
        int l = dfn[u], r = dfn[v];
        int _ = lg[r - l + 1];
        int x = st[l][_], y = st[r - (1 << _) + 1][_];
        return dep[x] < dep[y] ? x : y;
    };

    const int rt = 1;
    dfs(rt, 0);
    build();

    long long sum = 0;

    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++) {
            int len = dep[i] + dep[j] - 2 * dep[lca(i, j)] + 1;
            // cout << i << ' ' << j << ' ' << len << '\n';
            sum += ((Fac[len] - 2 * Fac[len - 1] + Fac[len - 2]) % MOD + MOD) % MOD;
            sum %= MOD;
        }

    cout << sum + 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
