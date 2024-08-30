#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 10;
int main() {
    freopen ("J.in", "r", stdin);
    ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> g(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    auto dijkstra = [&] (int s) {
        vector<int> dis(n + 1, INF);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> vis(n + 1, 0);
        dis[s] = 0;
        pq.push({0, s});
        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (vis[u]) continue;
            vis[u] = 1;
            for (auto [v, w] : g[u]) {
                int tmp = max(dis[u], w);
                if (tmp < dis[v]) {
                    dis[v] = tmp;
                    pq.push({dis[v], v});
                }
            }
        }
        return dis;
    };

    auto dis1 = dijkstra(1);
    auto disn = dijkstra(n);

    int ans = INF + INF;
    
    for (int u = 1; u <= n; u++) {
        for (auto [v, w] : g[u]) {
            if (w >= max(dis1[u], disn[v]))
                ans = min(ans, max(dis1[u], disn[v]) + w);
            if (w >= max(dis1[v], disn[u]))
                ans = min(ans, max(dis1[v], disn[u]) + w);
        }
    }
    cout << ans << '\n';
    return 0;
}