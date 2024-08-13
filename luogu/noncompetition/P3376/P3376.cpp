#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 0x3f3f3f3f;
struct EdmondsKarp {
    int n, m; // n 为点数，m 为边数
    struct Edge {
        int from, to, cap, flow; // 起点，终点，容量，流量
    };

    vector<Edge> edges; // 边表。edges[e] 和 edges[e^1] 互为反向边
    vector<vector<int>> g; // 邻接表，G[i][j] 表示节点 i 的第 j 条边在 edges 中的序号

    void init (int n_) {
        n = n_; edges.clear();
        g.assign(n, vector<int>());
    }

    void add_e (int from, int to, int cap) {
        edges.push_back(Edge{from, to, cap, 0});
        edges.push_back(Edge{to, from, 0, 0});
        m = edges.size();
        g[from].push_back(m - 2);
        g[to].push_back(m - 1);
    }

    int max_flow (int s, int t) {
        int flow = 0;
        vector<int> a, pre (n, 0); // a 为当前节点到源点的可改进量, pre 为当前节点的前驱的边的编号
        while (true) {
            a.assign(n, 0);
            queue<int> q; q.push(s); a[s] = INF;
            while (!q.empty()) {
                int x = q.front(); q.pop();
                for (auto i : g[x]) {
                    Edge &e = edges[i];
                    if (a[e.to] == 0  && e.cap > e.flow) { // 未访问过且残留网络中有剩余容量
                        pre[e.to] = i;
                        a[e.to] = min(a[x], e.cap - e.flow); // 更新到源点的可改进量
                        q.push(e.to);

                    }
                }
                if (a[t]) break; // 已经找到增广路
            }
            if (a[t] == 0) break; // 没有增广路
            for (int u = t; u != s; u = edges[pre[u]].from) { // 从汇点向源点更新流量
                edges[pre[u]].flow += a[t];
                edges[pre[u] ^ 1].flow -= a[t];
            }
            flow += a[t];
        }
        return flow;
    }
};

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

signed main() {
    freopen ("P3376.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, s, t; cin >> n >> m >> s >> t;
    Dinic ek; ek.init(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, c; cin >> u >> v >> c;
        ek.add_e(u, v, c);
    }
    cout << ek.max_flow(s, t) << '\n';
    return 0;
}