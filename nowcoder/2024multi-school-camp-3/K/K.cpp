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
    vector<int> d, cur;

    void init(int n_) {
        n = n_; edges.clear();
        d.assign(n, 0);
        g.assign(n, vector<int>());
    }

    void add_e(int from, int to, int cap) {
        edges.push_back({from, to, cap, 0});
        edges.push_back({to, from, 0, 0});
        m = edges.size();
        g[from].push_back(m - 2);
        g[to].push_back(m - 1);
    }

    bool bfs() {
        fill(d.begin(), d.end(), -1);
        queue<int> q; q.push(s); d[s] = 0;
        while (!q.empty()) {
            int x = q.front(); q.pop();
            for (auto i : g[x]) {
                Edge &e = edges[i];
                if (d[e.to] == -1 && e.cap > e.flow) {
                    d[e.to] = d[x] + 1;
                    q.push(e.to);
                }
            }
        }
        return d[t] != -1;
    }

    int dfs(int x, int a) {
        if (x == t || a == 0) return a;
        int flow = 0, f;
        for (int &i = cur[x]; i < g[x].size(); i++) {
            Edge &e = edges[g[x][i]];
            if (d[x] + 1 == d[e.to] && (f = dfs(e.to, min(a, e.cap - e.flow))) > 0) {
                e.flow += f;
                edges[g[x][i] ^ 1].flow -= f;
                flow += f;
                a -= f;
                if (a == 0) break;
            }
        }
        if (flow == 0) d[x] = -1; // 表示从 x 出发找不到增广路
        return flow;
    }

    int max_flow(int s, int t) {
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
    freopen ("K.in", "r", stdin);
    // freopen ("K.out", "w", stdout);
    int n, m, k; cin >> n >> m >> k;
    Dinic dinic; dinic.init(2 * n * k + 2); int S = 0, T = 2 * n * k + 1;

    auto get_id = [&] (int x, int j, int op) {
        return (x - 1) * k * 2 + j * 2 + op + 1;
    };

    auto inv_id = [&] (int id) {
        id--; int x = (id - 1) / 2 / k + 1, j = (id - 1) / 2 % k, op = (id - 1) % 2;
        return x;
    };
    
    vector<vector<int>> g(n + 1);
    vector<int> du_in(n + 1), du_out(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        du_out[u]++; du_in[v]++;
    }

    for (int i = 1; i <= n; i++) {
        if (du_in[i] == 0 || du_out[i] == 0) {
            if (du_in[i] == 0) dinic.add_e(S, get_id(i, 0, 1), INF);
            if (du_out[i] == 0) dinic.add_e(get_id(i, k - 1, 0), T, INF);
        }
        else {
            for (int j = 0; j < k; j++) {
                dinic.add_e(get_id(i, j, 0), get_id(i, j, 1), 1);
                if (j + 1 < k) dinic.add_e(get_id(i, j, 0), get_id(i, j + 1, 1), INF);
            }
        }

        int u = i;
        for (auto v : g[u]) {
            for (int j = 0; j < k; j++)
                dinic.add_e(get_id(u, j, 1), get_id(v, j, 0), INF);
        }
    }

    auto siz = dinic.max_flow(S, T);
    if (siz > n) {
        cout << -1 << '\n';
        return 0;
    }
    cout << siz << '\n';
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < k; j++) {
            if(dinic.d[get_id(i, j, 0)] != -1 && dinic.d[get_id(i, j, 1)] == -1) {
                // 说明断了 i 这个点
                ans.push_back(i);
            }
        }
    }
    for (auto x : ans) cout << x << ' ';
    return 0;
}