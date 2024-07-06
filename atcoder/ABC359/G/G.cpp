#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<int> A;
typedef long long ll;
const int maxn = 2e5 + 5;
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
    for (int i = 1; i <= tot; i++)
        lg[i] = lg[i >> 1] + 1;
    for (int i = 1; i <= tot; i++)
        st[i][0] = E[i];
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

int dist (int u, int v) {
    return dep[u] + dep[v] - 2 * dep[lca(u, v)];
}

ll now, all;

void dfs_1 (int u, int fa, int col, vector<int> &siz) {
    siz[u] = 0;
    for (auto v : g[u]) {
        if (v == fa) continue;
        dfs_1(v, u, col, siz);
        siz[u] += siz[v];
    }
    if (A[u] == col) {
        siz[u] += 1;
    }
    now += 1ll * (all - siz[u]) * siz[u];
}



int main() {
    ios::sync_with_stdio(0);
    int n; cin >> n;
    g.assign(n + 1, vector<int>());
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v); g[v].push_back(u);
    }
    A.assign(n + 1, 0);
    vector<vector<int>> p(n + 1, vector<int>());
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        p[A[i]].push_back(i);
    }

    dfs(1, 0);
    build_st();

    const int B = sqrt(n);
    ll ans = 0;
    vector<int> siz(n + 1, 0);
    vector<ll>  R(n + 1, 0);
    for (auto &v : p) {
        if (v.empty()) continue;
        int col = A[v[0]]; now = 0, all = v.size();
        if (v.size() <= B) {
            for (int i = 0; i < v.size(); i++)
                for (int j = i + 1; j < v.size(); j++)
                    now += dist(v[i], v[j]);
        }
        else {
            dfs_1(1, 0, col, siz);
        }
        ans += now;
    }
    cout << ans << endl;
    return 0;
}