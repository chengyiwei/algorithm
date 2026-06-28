#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
struct EdmondsKarp {
    struct Edge {
        int from, to, cap, flow, cost;
    };
    int n, m;
    vector<Edge> edges;
    vector<vector<int>> g;

    void init(int n_) {
        n = n_; edges.clear();
        g.assign(n, vector<int>());
    }

    void add_e (int from, int to, int cap, int cost) {
        edges.push_back(Edge{from, to, cap, 0, cost});
        edges.push_back(Edge{to, from, 0, 0, -cost});
        m = edges.size();
        g[from].push_back(m - 2);
        g[to].push_back(m - 1);
    }

    bool bellmon_ford (int s, int t, int &flow, int &cost) {
        vector<int> dis (n, INF), a(n, 0), pre(n, 0), vis(n, 0); 
        // dis 为源点到当前点的最短距离, a 为当前节点到源点的可改进量, pre 为当前节点的前驱的边的编号, vis 为当前节点是否在队列中
        queue<int> q; q.push(s); dis[s] = 0; a[s] = INF;
        while (!q.empty()) {
            int x = q.front(); q.pop();
            vis[x] = 0;
            for (auto i : g[x]) {
                Edge &e = edges[i];
                if (e.cap > e.flow && dis[e.to] > dis[x] + e.cost) {
                    dis[e.to] = dis[x] + e.cost;
                    pre[e.to] = i;
                    a[e.to] = min(a[x], e.cap - e.flow);
                    if (!vis[e.to]) {q.push(e.to); vis[e.to] = 1;}
                }
            }
        }
        if (dis[t] == INF) return false;
        flow += a[t]; cost += dis[t] * a[t]; // 更新流量和费用
        for (int u = t; u != s; u = edges[pre[u]].from) {
            edges[pre[u]].flow += a[t];
            edges[pre[u] ^ 1].flow -= a[t];
        }
        return true;
    }

    pair<int, int> min_cost_max_flow(int s, int t) { // 返回最大流和最小费用
        int flow = 0, cost = 0;
        while (bellmon_ford(s, t, flow, cost));
        return {flow, cost};
    }
};

struct Dinic {
    int n, m, s, t;
    struct Edge {
        int from, to, cap, flow, cost;
    };
    vector<Edge> edges;
    vector<vector<int>> g;
    vector<int> d, cur, vis;

    void init(int n_) {
        n = n_; edges.clear();
        g.assign(n, vector<int>());
        d.resize(n); cur.resize(n); vis.resize(n);
    }

    void add_e(int from, int to, int cap, int cost) {
        edges.push_back(Edge{from, to, cap, 0, cost});
        edges.push_back(Edge{to, from, 0, 0, -cost});
        m = edges.size();
        g[from].push_back(m - 2);
        g[to].push_back(m - 1);
    }

    bool bellman_ford () {
        fill (d.begin(), d.end(), INF);
        fill (vis.begin(), vis.end(), 0);
        queue<int> q; q.push(s); d[s] = 0; vis[s] = 1;
        while (!q.empty()) {
            int x = q.front(); q.pop();
            vis[x] = 0;
            for (auto i : g[x]) {
                Edge &e = edges[i];
                if (e.cap > e.flow && d[e.to] > d[x] + e.cost) {
                    d[e.to] = d[x] + e.cost;
                    if (!vis[e.to]) {q.push(e.to); vis[e.to] = 1;}
                }
            }
        }
        return d[t] != INF;
    }

    int dfs (int x, int a) {
        if (x == t || a == 0) return a;
        int flow = 0, f;
        vis[x] = 1;
        for (int &i = cur[x]; i < g[x].size(); i++) {
            Edge &e = edges[g[x][i]];
            if (!vis[e.to] && d[x] + e.cost == d[e.to] && (f = dfs(e.to, min(a, e.cap - e.flow))) > 0) {
                e.flow += f; edges[g[x][i] ^ 1].flow -= f;
                flow += f;
                a -= f;
                if (a == 0) break;
            }
        }
        return flow;
    }

    pair<int, int> min_cost_max_flow(int s, int t) {
        this->s = s; this->t = t;
        int flow = 0, cost = 0;
        while (bellman_ford()) {
            fill(cur.begin(), cur.end(), 0);
            fill(vis.begin(), vis.end(), 0);
            while (int f = dfs(s, INF)) {
                flow += f;
                cost += f * d[t];
                fill(vis.begin(), vis.end(), 0);
            }
        }
        return {flow, cost};
    }
};

int main() {
    freopen ("P3381.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m, s, t; cin >> n >> m >> s >> t;
    Dinic ek; ek.init(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, c, w; cin >> u >> v >> c >> w;
        ek.add_e(u, v, c, w);
    }
    auto [flow, cost] = ek.min_cost_max_flow(s, t);
    cout << flow << ' ' << cost << '\n';
    return 0;
}