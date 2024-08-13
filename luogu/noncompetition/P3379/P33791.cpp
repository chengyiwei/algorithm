#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;

vector<int> g[maxn];

int dep[maxn << 1], lg[maxn << 1], st[maxn << 1][25], dfn[maxn], tot;
int E[maxn << 1];

void dfs (int u, int fa) {
    dfn[u] = ++tot; E[tot] = u;
    dep[u] = dep[fa] + 1;
    for (auto v : g[u]) {
        if (v == fa) continue;
        dfs(v, u);
        E[++tot] = u;
    }
}

void build_st() {
    lg[0] = -1;
    for (int i = 1; i <= tot; i++) lg[i] = lg[i >> 1] + 1;

    for (int i = 1; i <= tot; i++) st[i][0] = E[i];
    for (int j = 1; j <= 20; j++) {
        for (int i = 1; i + (1 << j) - 1 <= tot; i++) {
            int x = st[i][j - 1], y = st[i + (1 << (j - 1))][j - 1];
            st[i][j] = dep[x] < dep[y] ? x : y;
        }
    }
}

int lca (int u, int v) {
    if (dfn[u] > dfn[v]) swap(u, v);
    int l = dfn[u], r = dfn[v];
    int k_ = lg[r - l + 1];
    int x = st[l][k_], y = st[r - (1 << k_) + 1][k_];
    return dep[x] < dep[y] ? x : y;
}

int main() {
    freopen ("P3379.in", "r", stdin);
    ios::sync_with_stdio(false);
    int n, m, rt; cin >> n >> m >> rt;
    for (int i = 1; i < n; i++) {
        int x, y; cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(rt, 0);
    build_st();
    while (m--) {
        int x, y; cin >> x >> y;
        cout << lca(x, y) << endl;
    }
    return 0;
}