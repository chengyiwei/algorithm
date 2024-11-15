#include <bits/stdc++.h>
using namespace std;

int M;

vector<int> get_p () {
    int m = sqrt(M);
    vector<int> vis(m + 1, 0);
    vector<int> p;
    for (int i = 2; i <= m; i++) {
        if (!vis[i]) p.push_back(i);
        for (int j = 2; i * j <= m; j++)
            vis[i * j] = 1; 
    }
    return p;
}

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
        // cout << from << " " << to << " " << cap << " " << cost << '\n';
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

vector<pair<int, int>> get_factor(int x, vector<int> &p) {
    vector<pair<int, int>> res;
    for (int i = 0; i < p.size(); i++) {
        int k = 0;
        while (x % p[i] == 0) x /= p[i], k += 1;
        if (k) res.push_back({p[i], k});
    }
    if (x != 1) res.push_back({x, 1});
    return res;
}

int main() {
    // freopen ("K.in", "r", stdin);
    int n; cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];
    M = *max_element(a.begin() + 1, a.end());

    auto p = get_p();

    map<int, int> mp; mp[1] = 0;
    vector<pair<int, int>> Y; 
    vector<pair<int, int>> X;

    for (int i = 1; i <= n; i++) {
        int x = a[i];
        auto f = get_factor(x, p);
        int sum_k = 0;
        for (int j = 0; j < f.size(); j++)
            sum_k += f[j].second;
        X.push_back({x, sum_k});

        function<void(int, int, int)> dfs = [&] (int pos, int sum_k, int x) {
            Y.push_back({x, sum_k});
            if (pos == f.size()) return;
            for (int k = 0; k <= f[pos].second; k++) {
                dfs(pos + 1, sum_k + k, x);
                x *= f[pos].first;
            }
        };

        dfs(0, 0, 1);
    }

    sort(Y.begin(), Y.end());
    Y.erase(unique(Y.begin(), Y.end()), Y.end());

    EdmondsKarp ek; ek.init(X.size() + Y.size() + 3);
    int S = X.size() + Y.size(), T = a.size() + Y.size();
    
    for (int i = 0; i < X.size(); i++) {
        for (int j = 0; j < Y.size(); j++) {
            if (X[i].first % Y[j].first == 0) {
                ek.add_e(i, j + X.size(), 1, -(X[i].second - Y[j].second));
            }
        }
    }

    for (int i = 0; i < X.size(); i++)
        ek.add_e(S, i, 1, 0);

    for (int i = 0; i < Y.size(); i++)
        ek.add_e(X.size() + i, T, 1, 0);

    auto [flow, cost] = ek.min_cost_max_flow(S, T);

    cout << -cost << "\n";
    return 0;
}