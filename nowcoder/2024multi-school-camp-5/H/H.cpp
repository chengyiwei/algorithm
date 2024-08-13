#include <bits/stdc++.h>
using namespace std;
const int MAXN = 45;

vector<int> g[MAXN];
int vis[MAXN];

int dfs(int u) {
    vector<int> p;
    for (auto v : g[u]) {
        if (vis[v]) continue;
        vis[v] = u;
        p.push_back(v);
    }
    int res = 1;
    for (auto v : p) res = max(res, dfs(v) + 1);
    for (auto v : p) if (vis[v] == u) vis[v] = 0;
    return res;
}


int main() {
    freopen ("H.in", "r", stdin);
    ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v); g[v].push_back(u);
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        vis[i] = i;
        res = max(res, dfs(i));
        vis[i] = 0;
    }
    cout << res << '\n';
    return 0;
}