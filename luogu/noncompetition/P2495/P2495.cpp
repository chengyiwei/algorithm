#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 1e6 + 5;
int n, q;
vector<pair<int, int>> g[MAXN];

int mi[MAXN], in[MAXN], out[MAXN];
int dfn = 0;
void init(int u, int fa) {
    in[u] = ++dfn;
    for (auto [v, w] : g[u]) {
        if (v == fa) continue;
        mi[v] = min(mi[u], w);
        init(v, u);
    }
    out[u] = dfn;
}

int f[MAXN][21], dep[MAXN];
void dfs_lca(int u, int fa) {
    f[u][0] = fa; dep[u] = dep[fa] + 1;
    for (int i = 1; i <= 20; i++)
        f[u][i] = f[f[u][i - 1]][i - 1];
    for (auto [v, w] : g[u]) {
        if (v == fa) continue;
        dfs_lca(v, u);
    }
}

int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    for (int i = 20; i >= 0; i--)
        if (dep[f[u][i]] >= dep[v]) u = f[u][i];
    if (u == v) return u;
    for (int i = 20; i >= 0; i--)
        if (f[u][i] != f[v][i]) u = f[u][i], v = f[v][i];
    return f[u][0];
}

int isp(int u, int v) {
    return in[u] <= in[v] && out[u] >= out[v];
}

bool cmp(int u, int v) {
    return in[u] < in[v];
}

int vis[MAXN];
vector<pair<int,int>> vg[MAXN];

void build(vector<int> &node) {
    sort(node.begin(), node.end(), cmp);
    set<int> st; for (int x : node) st.insert(x);
    for (int i = 1; i < (int)node.size(); i++) st.insert(lca(node[i - 1], node[i]));
    node.clear(); for (int x : st) node.push_back(x);
    sort(node.begin(), node.end(), cmp);
    stack<int> stk;
    for (int v : node) {
        while (!stk.empty() && !isp(stk.top(), v)) stk.pop();
        if (!stk.empty()) vg[stk.top()].push_back({v, mi[v]});
        stk.push(v);
    }
}

int dp[MAXN];
void dfs_dp (int u) {
    dp[u] = 0;
    for (auto [v, w] : vg[u]) {
        dfs_dp(v);
        if (vis[v]) dp[u] += w;
        else dp[u] += min(dp[v], w);
    }
}

signed main() {
    freopen ("in.in", "r", stdin);
    // freopen ("out.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    memset(mi, 0x3f, sizeof mi);
    init(1, 0);
    dfs_lca(1, 0);
    int q; cin >> q;
    while (q--) {
        int k; cin >> k;
        vector<int> node(k);
        for (int i = 0; i < k; i++) 
            cin >> node[i], vis[node[i]] = 1;
        node.push_back(1);
        build(node);
        dfs_dp(1);
        cout << dp[1] << endl;
        for (int x : node) vg[x].clear(), vis[x] = 0;
    }
    return 0;
}