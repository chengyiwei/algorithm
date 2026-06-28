#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef pair<int, int> pii;
typedef tuple<int, int, int> t3;

const int INF = -1;
struct Edge {
    int from, to, c, l, idx;
    Edge(int from, int to, int c, int l, int idx) : from(from), to(to), c(c), l(l), idx(idx) {}
};

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<Edge> edges; int cnt = 0;
    vector<vector<int>> g(n + 1);
    vector<int> dis(n + 1, INF);
    for (int i = 0; i < m; i++) {
        int u, v, c, l; cin >> u >> v >> c >> l;
        edges.push_back(Edge(u, v, c, l, cnt++));
        g[u].push_back(cnt - 1);
        edges.push_back(Edge(v, u, c, l, cnt++));
        g[v].push_back(cnt - 1);
    }
    typedef priority_queue<t3, vector<t3>, greater<t3>> pq;
    vector<pq> p(m + 1);
    map<int, int> mp; mp[1] = 1;
    for (auto i : g[1]) {
        Edge &e = edges[i];
        p[e.c].push({e.l, e.to, 1});
    }
    for(int i = 1; i <= k; i++) {
        int C, L; cin >> C >> L;
        while (!p[C].empty()) {
            auto [d, u, idx] = p[C].top();
            if (d > L) break;
            p[C].pop();
            if (idx != 0 && idx != i) continue;
            if (dis[u] == 0 || mp.count(u)) continue;
            mp[u] = 1;
            for (auto j : g[u]) {
                Edge &e = edges[j];
                if (d + e.l > L) continue;
                if (e.c == C) p[e.c].push({d + e.l, e.to, i});
            }
        }
        for (auto [u, _] : mp) {
            dis[u] = 0;
            for (auto j : g[u]) {
                Edge &e = edges[j];
                p[e.c].push({e.l, e.to, 0});
            }
        }
        mp.clear();
    }
    for (int i = 1; i <= n; i++) {
        if (dis[i] == 0) cout << "1";
        else cout << "0";
    }
    cout << endl;
}

signed main() {
    freopen ("J.in", "r", stdin);
    freopen ("J.out", "w", stdout);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}