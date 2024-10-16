#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    freopen ("F.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vector<vector<int>> g(n + 1);
    vector<array<int, 2>> edges;
    vector<int> du(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v); g[v].push_back(u);
        edges.push_back({u, v});
        du[u] += 1; du[v] += 1;
    }

    auto du_ = du;
    queue<int> q;
    vector<int> vis(n + 1, 0);
    for (int i = 1; i <= n; i++) if(du_[i] == 1) q.push(i), vis[i] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        vis[u] = 1;
        for (auto v : g[u]) {
            if (vis[v]) continue;
            du_[v] -= 1;
            if (du_[v] == 1) {q.push(v);}
        }
    }

    auto edges_ = edges; edges.clear();
    int cnt_du_5 = 0, cnt_du_4 = 0;
    for (auto [u, v] : edges_) {
        if (!vis[u] && !vis[v]) {
            edges.push_back({u, v});
        }
    }

    for (int i = 1; i <= n; i++) {
        if (du[i] == 5) cnt_du_5 += 1;
        if (du[i] == 4) cnt_du_4 += 1;
    }
    
    // for (auto [u, v] : edges) {
    //     cout << u << " " << v << '\n';
    // }

    auto sub = [&] (int x) {
        if (du[x] == 5) cnt_du_5 -= 1;
        if (du[x] == 4) cnt_du_4 -= 1;
        du[x] -= 1;
        if (du[x] == 5) cnt_du_5 += 1;
        if (du[x] == 4) cnt_du_4 += 1;
    };

    auto add = [&] (int x) {
        if (du[x] == 5) cnt_du_5 -= 1;
        if (du[x] == 4) cnt_du_4 -= 1;
        du[x] += 1;
        if (du[x] == 5) cnt_du_5 += 1;
        if (du[x] == 4) cnt_du_4 += 1;
    };
    
    ll num = 0;

    for (auto [u, v] : edges) {
        sub(u); sub(v);
        if (cnt_du_5 != 0)
            num += n;
        else 
            num += cnt_du_4;
        add(u), add(v);
    }
    
    cout << 1ll * edges.size() * n - num << '\n';
    
    return 0;
}