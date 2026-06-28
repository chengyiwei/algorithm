#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n + 1);
    vector<pair<int, int>> e;
    vector<int> dis(n + 1, INF);
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        e.push_back({u, v});
    }
    for (int i = 1; i + 1 <= n; i++) {
        g[i].push_back(i + 1);
    }
    dis[1] = 0; queue<int> q; q.push(1);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto v : g[u]) {
            if (dis[v] == INF) {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }

    vector<int> pre(n + 1, 0);
    for (auto [u, v] : e) {
        int l = u + 1, r = v - dis[u] - 1 - 1;
        if (l > r) continue;
        pre[l]++; pre[r + 1]--;
    }

    int now = 0;
    for (int i = 1; i < n; i++) {
        now += pre[i];
        cout << (now == 0 ? "1" : "0");
    }
    cout << '\n';
}

int main() {
    freopen ("E.in", "r", stdin);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}