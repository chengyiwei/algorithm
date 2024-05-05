#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > g;
vector<int> dep;
vector<array<int, 20> > fa;

int n, rt, t0;
int max_dep;

void dfs(int u, int f, int dp) {
    max_dep = max(max_dep, dep[u] = dp);
    fa[u][0] = f;
    for (int i = 1; i < 20; i++)
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for (auto &v : g[u]) {
        if (v == f) continue;
        dfs(v, u, dp + 1);
    }
}

int lca(int x, int y) {
    if (dep[x] < dep[y]) swap(x, y);
    for (int i = 19; i >= 0; i--)
        if (dep[x] - (1 << i) >= dep[y])
            x = fa[x][i];
    if (x == y) return x;
    for (int i = 19; i >= 0; i--)
        if (fa[x][i] != fa[y][i])
            x = fa[x][i], y = fa[y][i];
    return fa[x][0];
}

int dis(int x, int y) { return dep[x] + dep[y] - 2 * dep[lca(x, y)]; }

int main() {
    // freopen ("E.in", "r", stdin);
    cin >> n;
    g.assign(n + 1, vector<int>());
    dep.resize(n + 1); fa.resize(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cin >> rt >> t0;
    dfs(rt, 0, 0);
    vector<int> id (n + 1);
    for (int i = 1; i <= n; i++) id[i] = i;
    auto cmp = [&](int x, int y) {return dep[x] < dep[y];};
    sort (id.begin() + 1, id.end(), cmp);
    int pos = 2, max_tim = 2 * n;
    vector<int> log_dep (max_tim + 1);
    int d1 = rt, d2 = rt;
    auto insert = [&] (int x) {
        int d1_x = dis(d1, x), d2_x = dis(d2, x);
        if (d1_x > d2_x) { d2 = x; return d1_x; }
        else { d1 = x; return d2_x; }
    };

    for (int i = 1; i <= max_dep; i++) {
        while (pos <= n && dep[id[pos]] == i)
            log_dep[i] = max(log_dep[i], insert(id[pos++]));
    }
    for (int i = max_dep + 1; i <= max_tim; i++)
        log_dep[i] = log_dep[i - 1];
    for (int k = 1; k <= n; k++) {
        auto check = [&] (int t) {
            int l = log_dep[t] / 2 + (log_dep[t] & 1);
            if (1ll * k * (t - t0) >= 1ll * l) return true;
            return false;
        };
        int l = t0 - 1, r = max_tim;
        while (l + 1 < r) {
            int mid = (l + r) >> 1;
            if (check(mid)) r = mid;
            else l = mid;
        }
        cout << r << ' ';
    }
    return 0;
}