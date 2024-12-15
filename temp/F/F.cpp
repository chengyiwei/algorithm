#include <bits/stdc++.h>

const int INF = 0x3f3f3f3f;
using namespace std;

struct Dinic {
    struct Edge {
        int from, to, cap, flow;
    };
    int n, m, s, t;
    vector<Edge> edges;
    vector<vector<int>> g;
    vector<int> d, cur; // d 为层次，cur 为当前弧优化

    void init (int n_) {
        n = n_; edges.clear();
        d.assign(n, 0);
        g.assign(n, vector<int>());
    }

    void add_e (int from, int to, int cap) {
        edges.push_back(Edge{from, to, cap, 0});
        edges.push_back(Edge{to, from, 0, 0});
        m = edges.size();
        g[from].push_back(m - 2);
        g[to].push_back(m - 1);
    }

    bool bfs () {
        vector<int> vis (n, 0);
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
        return vis[t]; // 是否存在能到达汇点的路径
    }

    int dfs (int x, int a) { // a 表示从源点到 x 的可改进量
        if (x == t || a == 0) return a;
        int flow = 0, f;
        for (int &i = cur[x]; i < g[x].size(); i++) { // 当前弧优化，在 cur[x] 之前都没有增广成功
            Edge &e = edges[g[x][i]];
            if (d[x] + 1 == d[e.to] && (f = dfs(e.to, min(a, e.cap - e.flow))) > 0) {
                e.flow += f;
                edges[g[x][i] ^ 1].flow -= f;
                flow += f;
                a -= f;
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

int main() {
    freopen ("F.in", "r", stdin);
    int n, m, k; cin >> n >> m >> k;

    vector<int> a(n);
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        u -= 1, v -= 1;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    vector<int> vis(n, 0);
    for (int i = 1; i <= k; i++) {
        int x; cin >> x; x -= 1;
        vis[x] = 1;
    }

    Dinic dinic; dinic.init(4 * n + 3);
    int s = 4 * n + 1, t = 4 * n + 2;

    const auto id = [&] (int x, int y) {
        return x * 4 + y - 1;
    };

    for (int i = 0; i < n; i++) {
        for (int j = 1; j + 1 <= 3; j++) {
            dinic.add_e(id(i, j + 1), id(i, j), INF);
        }
    }

    for (int i = 0; i < n; i++) {
        if (vis[i] == 1) continue;
        if (a[i] > 1)
            dinic.add_e(s, id(i, a[i] - 1), INF);
        if (a[i] < 4)
            dinic.add_e(id(i, a[i]), t, INF);
    }

    for (int i = 0; i < n; i++) {
        int u = i;
        for (auto [v, w] : g[u]) {
            dinic.add_e(id(u, 1), id(v, 1), w);
            dinic.add_e(id(u, 2), id(v, 2), w);
            dinic.add_e(id(u, 3), id(v, 3), w);
            dinic.add_e(id(u, 2), id(v, 1), 6 * w);
            dinic.add_e(id(u, 3), id(v, 2), 6 * w);
            dinic.add_e(id(u, 3), id(v, 1), 12 * w);
        }
    }

    auto ans = dinic.max_flow(s, t);

    cout << ans << endl;
    return 0;
}