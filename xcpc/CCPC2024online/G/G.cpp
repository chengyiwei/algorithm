#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 0x3f3f3f3f3f3f3f3f;

struct Dinic {
    struct Edge {
        int from, to, cap, flow;
    };
    int n, m, s, t;
    vector<Edge> edges;
    vector<vector<int>> g;
    vector<int> d, cur;

    Dinic(int n) : n(n) {
        d.assign(n, 0);
        g.assign(n, vector<int>());
    }

    void add_edge(int from, int to, int cap) {
        edges.push_back({from, to, cap, 0});
        edges.push_back({to, from, 0, 0});
        m = edges.size();
        g[from].push_back(m - 2);
        g[to].push_back(m - 1);
    }

    bool bfs() {
        vector<int> vis(n, 0);
        queue<int> q; q.push(s); d[s] = 0; vis[s] = 1;
        while (!q.empty()) {
            int x = q.front(); q.pop();
            for (auto i : g[x]) {
                Edge &e = edges[i];
                if (vis[e.to] == 0 && e.cap > e.flow) {
                    vis[e.to] = 1;
                    d[e.to] = d[x] + 1;
                    q.push(e.to);
                }
            }
        }
        return vis[t];
    }

    int dfs(int x, int a) {
        if (x == t || a == 0) return a;
        int flow = 0, f;
        for (int &i = cur[x]; i < g[x].size(); i++) {
            Edge &e = edges[g[x][i]];
            if (d[x] + 1 == d[e.to] && (f = dfs(e.to, min(a, e.cap - e.flow)))) {
                e.flow += f;
                edges[g[x][i] ^ 1].flow -= f;
                flow += f; a -= f;
                if (a == 0) break;
            }
        }
        return flow;
    }

    int max_flow (int s, int t) {
        this->s = s; this->t = t;
        int flow = 0;
        while (bfs()) {
            cur.assign(n, 0);
            flow += dfs(s, INF);
        }
        return flow;
    }
};

signed main() {
    freopen ("G.in", "r", stdin);
    ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    int s = 0, t = n + m + 1;
    vector<int> a(n + 1), V(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> V[i];
    }
    int max1 = V[1], sum = 0;
    vector<array<int, 3>> e(m + 1);
    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        e[i] = {u, v, w};
        sum += w;
        if (u == 1 || v == 1) max1 += w;
    }
    max1 = min(max1, a[1]);

    Dinic dinic(n + m + 2);
    for (int i = 1; i <= m; i++) {
        auto [u, v, w] = e[i];
        dinic.add_edge(s, i, w);
        dinic.add_edge(i, m + u, w);
        dinic.add_edge(i, m + v, w);
    }
    for (int i = 1; i <= n; i++) {
        int tp = min(a[i], max1 - (i != 1));
        if (V[i] > tp) {cout << "NO" << endl; return 0;}
        dinic.add_edge(m + i, t, tp - V[i]);
    }

    int flow = dinic.max_flow(s, t);
    if (flow == sum) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}