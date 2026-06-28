#include <bits/stdc++.h>
using namespace std;

const int TT = 998244353;
const int MAXN = 1e6 + 3;

vector<int> g[MAXN];
pair<int, int> a[MAXN];
int fa[MAXN], dep[MAXN];
int dsu_fa[MAXN], dsu_siz[MAXN], dsu_min_dep[MAXN], dsu_min_dep_id[MAXN];

int find(int x) {
    return dsu_fa[x] == x ? x : dsu_fa[x] = find(dsu_fa[x]);
}

void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    dsu_fa[x] = y;
    dsu_siz[y] += dsu_siz[x];
    if (dsu_min_dep[y] > dsu_min_dep[x]) {
        dsu_min_dep[y] = dsu_min_dep[x];
        dsu_min_dep_id[y] = dsu_min_dep_id[x];
    }
}

int qpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = 1ll * res * a % TT;
        a = 1ll * a * a % TT;
        b >>= 1;
    }
    return res;
}

bool check(int u, int v) {
    int u_rt = dsu_min_dep_id[find(u)], fa_rt = fa[u_rt];
    if (find(v) == find(fa_rt)) return true;
    return false;
}

int dfs(int u, int f) {
    fa[u] = f;
    int siz = 1;
    for (int v : g[u]) {
        if (v == f) continue;
        dep[v] = dep[u] + 1;
        siz += dfs(v, u);
    }
    return siz;
}

int main() {
    freopen ("G.in", "r", stdin);
    freopen ("G.out", "w", stdout);
    ios::sync_with_stdio(false);
    int n; cin >> n;

    for (int i = 1; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v); g[v].push_back(u);
    }

    dfs(1, 0);

    for (int i = 1; i <= n; i++) dsu_min_dep[i] = dep[i], dsu_min_dep_id[i] = i, dsu_fa[i] = i, dsu_siz[i] = 1;

    int ans = 1;


    for (int i = 1; i < n; i++) {
        auto [u, v] = a[i];
        if (check(u, v) == 0 && check(v, u) == 0) {
            cout << 0 << endl;
            return 0;
        }
        int siz_u = dsu_siz[find(u)], siz_v = dsu_siz[find(v)];
        merge(u, v);
        ans = 1ll * ans * siz_u % TT * siz_v % TT;
    }
    ans = qpow(ans, TT - 2);
    cout << ans << endl;
    return 0;
}