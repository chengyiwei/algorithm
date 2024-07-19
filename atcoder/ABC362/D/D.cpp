#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> pii;
typedef long long ll;
const int inf = 1e18;
signed main() {
    ios::sync_with_stdio(false);
    int n, m ; cin >> n >> m;
    vector<int> a(n + 1);
    vector<vector<pii>> g(2 * n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        g[i].push_back({i + n, a[i]});
    }
    for (int i = 1; i <= m; i++) {
        int u, v , w; cin >> u >> v >> w;
        g[u + n].push_back({v, w});
        g[v + n].push_back({u, w});
    }
    vector<int> dis(2 * n + 1, inf);
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, 1}); dis[1] = 0;
    while (!q.empty()) {
        auto [d, u] = q.top(); q.pop();
        if (dis[u] < d) continue;
        for (auto [v, w] : g[u]) {
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q.push({dis[v], v});
            }
        }
    }
    for (int i = 2; i <= n; i++)
        cout << dis[i + n] << " ";
    return 0;
}