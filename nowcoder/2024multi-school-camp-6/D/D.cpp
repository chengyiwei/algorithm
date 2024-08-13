#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main() {
    freopen ("D.in", "r", stdin);
    ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n + 1);
    map<pii, int> mp, mp2;
    for (int i = 1; i <= m; i++) {
        string s; int u, v, w; cin >> u >> v; cin >> s;
        w = (s == "Lun");
        if (w == 1) {
            mp[{u, v}] = 1;
            g[u].push_back(v); g[v].push_back(u);
        }
        else {
            mp2[{u, v}] = 1;
        }
    }
    
    vector<int> dfn(n + 1, 0), low(n + 1, 0); int dfn_cnt = 0;
    vector<pair<int, int>> cut_bridge;

    function<void(int, int)> tarjan = [&] (int u, int fa) {
        dfn[u] = low[u] = ++dfn_cnt;
        for (auto v : g[u]) {
            if (!dfn[v]) {
                tarjan(v, u);
                low[u] = min(low[u], low[v]);
                if (low[v] > dfn[u]) cut_bridge.push_back({u, v});
            }
            else if (v != fa) low[u] = min(low[u], dfn[v]);
        }
    };

    for (int i = 1; i <= n; i++) if (!dfn[i]) tarjan(i, 0);
    for (auto [u, v] : cut_bridge) {
        mp.erase({u, v}); mp.erase({v, u});
    }

    vector<int> fa(n + 1);
    iota(fa.begin(), fa.end(), 0);

    function<int(int)> find = [&] (int x) -> int {
        return x == fa[x] ? x : fa[x] = find(fa[x]);
    };

    for (auto [x, _] : mp) {
        auto [u, v] = x;
        int fu = find(u), fv = find(v);
        if (fu == fv) continue;
        fa[fu] = fv;
    }

    for (auto [x, _] : mp2) {
        auto [u, v] = x;
        int fu = find(u), fv = find(v);
        if (fu == fv) continue;
        fa[fu] = fv;
        mp[{u, v}] = 1;
    }

    vector<int> hsh(n + 1, 0);
    for (int i = 1; i <= n; i++) hsh[find(i)]++;
    int cnt = 0;
    for (int i = 1; i <= n; i++) cnt += (hsh[i] > 0);
    if (cnt > 1) { cout << "NO" << endl; return 0;}

    cout << "YES" << '\n';
    cout << mp.size() << '\n';
    for (auto [u, v] : mp) {
        cout << u.first << ' ' << u.second << '\n';
    }
    return 0;
}