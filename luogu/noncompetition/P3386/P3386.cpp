#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

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
    freopen ("P3386.in", "r", stdin);
    int n, m, e; cin >> n >> m >> e;
    Dinic dinic; dinic.init(n + m + 2);
    int S = 0, T = n + m + 1;
    for (int i = 1; i <= e; i++) {
        int x, y; cin >> x >> y;
        dinic.add_e(x, y + n, 1);
    }
    for (int i = 1; i <= n; i++) dinic.add_e(S, i, 1);
    for (int i = 1; i <= m; i++) dinic.add_e(i + n, T, 1);
    auto ans = dinic.max_flow(S, T);
    cout << ans << endl;
    return 0;

}