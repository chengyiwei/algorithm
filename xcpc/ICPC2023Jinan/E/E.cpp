#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
using namespace std;

const int INF = 0x3f3f3f3f;
inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}

struct Edge {
    int from, to, cap, flow;
    Edge(int u, int v, int c, int f) : from(u), to(v), cap(c), flow(f) {};
};

struct Dinic {
    int n, m, s, t;
    vector<Edge> edges;
    vector<vector<int>> g;
    vector<int> d, cur;

    void init (int n_) {
        n = n_; edges.clear();
        g.assign(n, vector<int>());
        d.resize(n); cur.resize(n);
    }

    void add_e (int from, int to, int cap) {
        edges.push_back(Edge(from, to, cap, 0));
        edges.push_back(Edge(to, from, 0, 0));
        m = edges.size();
        g[from].push_back(m - 2);
        g[to].push_back(m - 1);
    }

    bool bfs() {
        vector<int> vis(n, 0);
        queue<int> q; q.push(s); d[s] = 0; vis[s] = 1;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int i = 0; i < g[u].size(); i++) {
                Edge &e = edges[g[u][i]];
                if (!vis[e.to] && e.cap > e.flow) {
                    vis[e.to] = 1;
                    d[e.to] = d[u] + 1;
                    q.push(e.to);
                }
            }
        }
        return vis[t];
    }

    int dfs (int x, int a) {
        if (x == t || a == 0)
            return a;
        int flow = 0, f;
        for (int &i = cur[x]; i < g[x].size(); i++) {
            Edge &e = edges[g[x][i]];
            if (d[x] + 1 == d[e.to] && (f = dfs(e.to, min(a, e.cap - e.flow))) > 0) {
                e.flow += f;
                edges[g[x][i] ^ 1].flow -= f;
                flow += f;
                a -= f;
                if (a == 0)
                    break;
            }
        }
        return flow;
    }

    int max_flow (int s_, int t_) {
        s = s_, t = t_;
        int flow = 0;
        while (bfs()) {
            fill(cur.begin(), cur.end(), 0);
            flow += dfs(s, INF);
        }
        return flow;
    }
};

void solve() {
    int n, m; n = read(); m = read();
    int s = 0, t = 2 * n + 1;
    Dinic dinic;
    dinic.init(2 * n + 2);
    for (int i = 1; i <= m; i++) {
        int u = read(), v = read();
        dinic.add_e(u, v + n, 1);
    }
    for (int i = 1; i <= n; i++) {
        dinic.add_e(s, i, 1);
        dinic.add_e(i + n, t, 1);
    }
    int max_flow = dinic.max_flow(s, t);
    // cout << dinic.max_flow(s, t) << endl;
    int cnt_1 = 0, cnt_2 = 0;
    vector<int> vis(2 * n + 2, 0);
    queue<int> q; q.push(s); vis[s] = 1; vis[t] = 1;
    auto &g = dinic.g;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (1 <= u && u <= n) cnt_1 += 1;
        for (auto i : g[u]) {
            int to = dinic.edges[i].to;
            int remain = dinic.edges[i].cap - dinic.edges[i].flow;
            if (remain > 0 && !vis[to]) {
                vis[to] = 1;
                q.push(to);
            }
        }
    }

    fill(vis.begin(), vis.end(), 0); q.push(t); vis[s] = 1; vis[t] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (n + 1 <= u && u <= 2 * n) cnt_2 += 1;
        for (auto i : g[u]) {
            int to = dinic.edges[i].to;
            int remain = dinic.edges[i ^ 1].cap - dinic.edges[i ^ 1].flow;
            if (remain > 0 && !vis[to]) {
                vis[to] = 1;
                q.push(to);
            }
        }
    }
    printf ("%lld\n", 1ll * cnt_1 * cnt_2);
}

int main() {
    freopen ("E.in", "r", stdin);
    int T = read();
    while (T--) solve();
    return 0;
}