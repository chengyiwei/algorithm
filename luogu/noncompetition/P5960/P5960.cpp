#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

int main() {
    int n, m; cin >> n >> m;
    vector<vector<pii>> g(n + 1);
    for (int i = 1; i <= m; i++) {
        int x, y, c; cin >> x >> y >> c;
        g[y].push_back({x, c});
    }
    for (int i = 1; i <= n; i++) g[0].push_back({i, 0});

    vector<int> dis(n + 1, INF), vis(n + 1, 0), cnt(n + 1, 0);
    
    auto spfa = [&]() -> bool {
        queue<int> q;
        q.push(0); vis[0] = 1; dis[0] = 0; cnt[0] = 1;
        while (!q.empty()) {
            int u = q.front(); q.pop(); vis[u] = 0;
            for (auto [v, w] : g[u]) {
                if (dis[v] > dis[u] + w) {
                    dis[v] = dis[u] + w;
                    if (!vis[v]) {
                        q.push(v); vis[v] = 1;
                        if (++cnt[v] > n) return false;
                    }
                }
            }
        }
        return true;
    };

    if (spfa()) {
        for (int i = 1; i <= n; i++) 
            cout << dis[i] << ' ';
    }
    else 
        printf ("NO\n");
    return 0;
}