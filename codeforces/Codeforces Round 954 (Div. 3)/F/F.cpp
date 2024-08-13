#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int n, m;
vector<vector<int> > g;
map<pii, int> mp;
struct Tarjan { //割边
    int n;
    vector<int> dfn, low; int dfn_cnt;
    vector<pii> cut_bridge;

    void init(int _n) {
        n = _n; dfn_cnt = 0;
        dfn.assign(n + 1, 0); low.assign(n + 1, 0);
        cut_bridge.clear();
    }

    void tarjan(int u, int fa) {
        dfn[u] = low[u] = ++dfn_cnt;
        for (auto v : g[u]) {
            if (v == fa) continue;
            if (!dfn[v]) {
                tarjan(v, u);
                low[u] = min(low[u], low[v]);
                if (low[v] > dfn[u])
                    cut_bridge.push_back({u, v}), mp[{u, v}] = mp[{v, u}] = 1;
            } else
                low[u] = min(low[u], dfn[v]);
        }
    }
};

ll ans = 0;
vector<int> vis;
int dfs (int u) {
    vis[u] = 1;
    int ret = 1;
    for (auto v : g[u]) {
        if (vis[v]) continue;
        int now = dfs(v);
        ret += now;
        if (mp.count({u, v}) || mp.count({v, u}))
            ans = max(ans, 1ll * now * (n - now));
    }
    return ret;
}

void solve() {
    cin >> n >> m;
    g.assign(n + 1, vector<int>()); mp.clear();
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    Tarjan tarjan;
    tarjan.init(n);
    tarjan.tarjan(1, 0);

    vis.assign(n + 1, 0); ans = 0;
    dfs(1);
    ll all = 1ll * n * (n - 1) / 2;
    cout << all - ans << '\n';
}

int main() {
    freopen ("F.in", "r", stdin);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}