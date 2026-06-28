#include <bits/stdc++.h>
#define int long long
using namespace std;

constexpr int INF = 0x3f3f3f3f3f3f3f3f;
using pii = pair<int, int>;
const int MAXN = 2e5 + 5;
vector<pair<array<int, 2> , int>> g[MAXN][2];

void solve() {
    int n, m, h; cin >> n >> m >> h;

    for (int i = 1; i <= n; i++) g[i][0].clear(), g[i][1].clear();
    vector<int> a(h + 1);
    for (int i = 1; i <= h; i++) cin >> a[i];

    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        g[u][0].push_back({{v, 0}, w});
        g[v][0].push_back({{u, 0}, w});
        g[u][1].push_back({{v, 1}, w >> 1});
        g[v][1].push_back({{u, 1}, w >> 1});
    }
    for (int i = 1; i <= h; i++) {
        g[a[i]][0].push_back({{a[i], 1}, 0});
    }

    auto dij = [&] (int S) {
        vector<array<int, 2>> dis(n + 1, {INF, INF});
        priority_queue<pair<int, array<int, 2>>, vector<pair<int, array<int, 2>>>, greater<>> pq;
        pq.push({0, {S, 0}}); dis[S][0] = 0;
        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dis[u[0]][u[1]]) continue;
            for (auto [v, w] : g[u[0]][u[1]]) {
                if (dis[v[0]][v[1]] > dis[u[0]][u[1]] + w) {
                    dis[v[0]][v[1]] = dis[u[0]][u[1]] + w;
                    pq.push({dis[v[0]][v[1]], v});
                }
            }
        }
        return dis;
    };

    auto dis1 = dij(1), disn = dij(n);

    int ans = INF;
    for (int i = 1; i <= n; i++) {
        ans = min(ans, max(min(dis1[i][0], dis1[i][1]) , min(disn[i][0], disn[i][1])));
    }
    cout << (ans == INF ? -1 : ans) << '\n';
} 

signed main() {
    freopen ("B.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while (T--) solve();
    return 0;
}