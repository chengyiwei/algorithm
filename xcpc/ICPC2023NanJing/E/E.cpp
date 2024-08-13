#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

map<pair<int, int>, int> mp;

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

    bool bfs () {
        fill(d.begin(), d.end(), 0); fill(vis.begin(), vis.end(), 0);
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

    int dfs (int x, int a) {
        if (x == t || a == 0) return a;
        int flow = 0, f;
        vis[x] = 1;
        for (int &i = cur[x]; i < g[x].size(); i++) {
            Edge &e = edges[g[x][i]];
            if (!vis[e.to] && d[x] + 1 == d[e.to] && (f = dfs(e.to, min(a, e.cap - e.flow))) > 0) {
                e.flow += f; edges[g[x][i] ^ 1].flow -= f;
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
            fill(cur.begin(), cur.end(), 0);
            fill(vis.begin(), vis.end(), 0);
            flow += dfs(s, INF);
        }
        return flow;
    }

    bool bellmon_ford (int s, int t, int &flow, int &cost) {
        fill(d.begin(), d.end(), INF);
        vector<int> a(n, 0); vector<int> pre(n, 0);
        fill(vis.begin(), vis.end(), 0);
        queue<int> q; q.push(s); d[s] = 0; vis[s] = 1; a[s] = INF;
        while (!q.empty()) {
            int x = q.front(); q.pop();
            vis[x] = 0;
            for (auto i : g[x]) {
                Edge &e = edges[i];
                if (e.cap > e.flow && d[e.to] > d[x] + e.cost) {
                    d[e.to] = d[x] + e.cost;
                    pre[e.to] = i;
                    a[e.to] = min(a[x], e.cap - e.flow);
                    if (!vis[e.to]) {q.push(e.to); vis[e.to] = 1;}
                }
            }
        }
        if (d[t] == INF) return false; // 不存在增广路
        flow += a[t]; cost += a[t] * d[t];
        for (int i = t; i != s; i = edges[pre[i]].from) {
            edges[pre[i]].flow += a[t];
            edges[pre[i] ^ 1].flow -= a[t];
        }
        return true; // 存在增广路
    }

    pair<int, int> min_cost_max_flow(int s, int t) {
        int flow = 0, cost = 0;
        while (bellmon_ford(s, t, flow, cost));
        return {flow, cost};
    }
};


void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<vector<int>> row(n + 1, vector<int>(m + 1)), col(n + 1, vector<int>(m + 1));
    auto hsh = [&](int x, int y) {return (x - 1) * (m - 1) + y;};
    auto get = [&] (int h) {return make_pair((h - 1) / (m - 1) + 1, (h - 1) % (m - 1) + 1);};
    for (int i = 1; i <= n; i++)
        for (int j = 1; j < m; j++)
            cin >> row[i][j];
    for (int i = 1; i < n; i++)
        for (int j = 1; j <= m; j++)
            cin >> col[i][j];
    int S = 0, T = (n - 1) * (m - 1) + 1;
    Dinic dinic; dinic.init(T + 1 + 1);
    for (int j = 1; j <= m - 1; j++)
        dinic.add_e(S, hsh(1, j), row[1][j], 0), dinic.add_e(hsh(n - 1, j), T, row[n][j], 0);
    for (int i = 1; i <= n - 1; i++)
        for (int j = 1; j <= m - 1; j++) {
            if (i != 1) dinic.add_e(hsh(i, j), hsh(i - 1, j), row[i][j], 0); // 上
            if (i != n - 1) dinic.add_e(hsh(i, j), hsh(i + 1, j), row[i + 1][j], 0); // 下
            if (j != 1) dinic.add_e(hsh(i, j), hsh(i, j - 1), col[i][j], 0); // 左
            if (j != m - 1) dinic.add_e(hsh(i, j), hsh(i, j + 1), col[i][j + 1], 0); // 右
        }
    int D = dinic.max_flow(S, T);
    // cout << D << '\n';

    for (int j = 1; j <= m - 1; j++)
        dinic.add_e(S, hsh(1, j), INF, 1), dinic.add_e(hsh(n - 1, j), T, INF, 1);
    for (int i = 1; i <= n - 1; i++)
        for (int j = 1; j <= m - 1; j++) {
            if (i != 1) dinic.add_e(hsh(i, j), hsh(i - 1, j), INF, 1); // 上
            if (i != n - 1) dinic.add_e(hsh(i, j), hsh(i + 1, j), INF, 1); // 下
            if (j != 1) dinic.add_e(hsh(i, j), hsh(i, j - 1), INF, 1); // 左
            if (j != m - 1) dinic.add_e(hsh(i, j), hsh(i, j + 1), INF, 1); // 右
        }
    auto pre_edges = dinic.edges;
    auto ans_row = row, ans_col = col;
    int SS = T + 1; dinic.add_e(SS, S, k, 0); // 源点到 S 的流量为 k
    auto [_, ans] = dinic.min_cost_max_flow(SS, T);
    // cout << _ << " " << ans << '\n';
    cout << ans << '\n';
    for (int i = 0; i < dinic.edges.size(); i++) {
        auto &e = dinic.edges[i];
        if (e.cost != 1) continue;
        int f = e.flow - pre_edges[i].flow;
        if (f <= 0) continue;
        if (e.from == S) {
            auto [x, y] = get(e.to);
            ans_row[1][y] += f;
            continue;
        }
        if (e.to == T) {
            auto [x, y] = get(e.from);
            ans_row[n][y] += f;
            continue;
        }
        auto [x1, y1] = get(e.from);
        auto [x2, y2] = get(e.to);
        if (x1 == x2)
            ans_col[x1][max(y1, y2)] += f;
        else 
            ans_row[max(x1, x2)][y1] += f;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < m; j++)
            cout << ans_row[i][j] << " \n"[j == m - 1];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= m; j++)
            cout << ans_col[i][j] << " \n"[j == m];
    }
}

int main() {
    freopen ("E.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}