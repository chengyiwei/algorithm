#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n, m;
typedef pair<int, int> pii;
vector<pii> g[maxn];

int f[maxn][20], dep[maxn];
int a[maxn];

void dfs1 (int u, int fa) {
    f[u][0] = fa;
    for (auto e : g[u]) {
        int v = e.first;
        if (v != fa) {
            dep[v] = dep[u] + 1;
            dfs1(v, u);
        }
    }
}

void init() {
    for (int j = 1; j < 20; j++)
        for (int i = 1; i <= n; i++)
            f[i][j] = f[f[i][j - 1]][j - 1];
}

int lca (int u, int v) {
    if (dep[u] > dep[v]) swap(u, v);
    for (int j = 19; j >= 0; j--)
        if (dep[f[v][j]] >= dep[u])
            v = f[v][j];
    if (u == v) return u;
    for (int j = 19; j >= 0; j--)
        if (f[u][j] != f[v][j])
            u = f[u][j], v = f[v][j];
    return f[u][0];
}

int ans = 0;
int dfs2 (int u, int fa) {
    int ret = a[u];
    for (auto e : g[u]) {
        int v = e.first, id = e.second;
        if (v == fa) continue;
        int now = dfs2(v, u);
        if (now == m && id > ans)
            ans = id;
        ret += now;
    }
    return ret;
}

int main() {
    freopen ("H.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back({v, i});
        g[v].push_back({u, i});
    }
    dfs1(1, 0);
    init();
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        int l = lca(u, v);
        a[u]++; a[v]++; a[l] -= 2;
    }
    dfs2 (1, 0);
    printf ("%d\n", ans);
    return 0;
}