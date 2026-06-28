#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N, M, X; cin >> N >> M >> X;
    vector<vector<pair<int, int>>> G(2 * N + 1), G_(2 * N + 1);
    for (int i = 1; i <= M ; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back({v, 1});
        G[v + N].push_back({u + N, 1});
    }
    for (int i = 1; i <= N; i++) {
        G[i + N].push_back({i, X});
        G[i].push_back({i + N, X});
    }

    vector<int> dist(2 * N + 1, 1e17);
    dist[1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    while (!pq.empty()) {// Dijkstra
        auto [d, u] = pq.top(); pq.pop();
        if (dist[u] < d) continue;
        for (auto [v, w] : G[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    int ans = min(dist[N], dist[2 * N]);
    cout << ans << '\n';
    return 0;
}