#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

typedef pair<int, int> pii;
typedef long long ll;

vector<int> dij (int s, vector<vector<pii>> &g) {
    int n = g.size();
    vector<int> dis(n + 1, INF);
    vector<int> vis(n + 1, 0);
    dis[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto [v, w] : g[u]) {
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                pq.push({dis[v], v});
            }
        }
    }
    return dis;
}

int main() {
    ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    vector<vector<pii>> g1(n + 1), g2(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        g1[u].push_back({v, w});
        g2[v].push_back({u, w});
    }
    auto dis1 = dij(1, g1), dis2 = dij(1, g2);
    ll ans = 0;
    for (int i = 2; i <= n; i++)
        ans += dis1[i] + dis2[i];
    cout << ans << endl;
    return 0;
}