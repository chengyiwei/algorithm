#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int, int> pii;
int n, m;
const int INF = 0x3f3f3f3f3f3f3f3f;

struct Edge {
    int from, to, w;
    Edge(int from, int to, int w) : from(from), to(to), w(w) {}
};


signed main() {
    freopen ("B.in", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    vector<Edge> edges;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        edges.emplace_back(u, v, w);
        g[u].push_back(edges.size() - 1);
    }

    //tarjan
    vector<int> dfn(n, -1), low(n, -1), scc(n, -1);
    vector<vector<int>> scc_g;
    stack<int> stk; vector<int> in_stk(n, 0);
    int cnt = 0;
    function<void(int)> tarjan = [&](int u) {
        dfn[u] = low[u] = ++cnt; stk.push(u); in_stk[u] = 1;
        for (auto e : g[u]) {
            int v = edges[e].to;
            if (dfn[v] == -1) { //没有访问过
                tarjan(v);
                low[u] = min(low[u], low[v]);
            }else if (in_stk[v]) {
                low[u] = min(low[u], dfn[v]);
            }
        }
        if (dfn[u] == low[u]) {
            int num = scc_g.size() - 1;
            vector<int> tmp;
            while (stk.top() != u) {
                tmp.emplace_back(stk.top());
                scc[stk.top()] = num;
                in_stk[stk.top()] = 0; stk.pop();
            }
            tmp.emplace_back(u);
            scc[stk.top()] = num; in_stk[stk.top()] = 0; stk.pop();
            scc_g.emplace_back(tmp);
        }
    };

    for (int i = 0; i < n; i++) 
        if (dfn[i] == -1) tarjan(i);
    
    vector<int> ans(n, 0);

    for (auto &a : scc_g) {
        vector<int> id(n, -1);
        for (int i = 0; i < a.size(); i++) id[a[i]] = i;

        int m = a.size();
        vector<Edge> new_edges;
        vector<vector<int>> new_g(m * 2 + 1);
    
        auto add_e = [&] (int u, int v, int w) {
            new_edges.emplace_back(u, v, w);
            new_g[u].push_back(new_edges.size() - 1);
        };

        for (auto &u : a) {
            for (auto &e : g[u]) {
                int v = edges[e].to, w = edges[e].w;
                if (scc[v] != scc[u]) continue;
                if (w % 2) {
                    add_e(id[u], id[v] + m, w);
                    add_e(id[u] + m, id[v], w);
                }
                else {
                    add_e(id[u], id[v], w);
                    add_e(id[u] + m, id[v] + m, w);
                }
            }
        }

        function<bool(int)> spfa = [&] (int s) {
            vector<int> dis(m * 2, INF), inq(m * 2, 0), cnt(m * 2, 0);
            queue<int> q; 
            q.push(s); dis[s] = 0; inq[s] = 1; cnt[s] = 1;
            while (q.size()) {
                int u = q.front(); q.pop(); inq[u] = 0;
                for (auto &e : new_g[u]) {
                    int v = new_edges[e].to, w = new_edges[e].w;
                    if (dis[v] > dis[u] + w) {
                        dis[v] = dis[u] + w;
                        if (!inq[v]) {
                            q.push(v); inq[v] = 1;
                            if (++cnt[v] > m) return true; //存在负环
                        }
                    }
                }
            }
            return false; //不存在负环
        };

        if (spfa(0)) {
 
            auto bfs = [&] (int s) { //判断是否存在从s到s+m的路径
                vector<int> vis(m * 2, 0);
                queue<int> q; q.push(s); vis[s] = 1;
                while (q.size()) {
                    int u = q.front(); q.pop();
                    for (auto &e : new_g[u]) {
                        int v = new_edges[e].to;
                        if (!vis[v]) {
                            vis[v] = 1; q.push(v);
                        }
                    }
                }
                return vis [s + m];
            };

            for (auto &u : a) {
                if (bfs(id[u]))
                    ans[u] = -INF;
                else 
                    ans[u] = 0;
            }
            continue;
        }

        //johnson
        int t = m * 2;
        vector<int> h(t + 1, INF);
        for (int i = 0; i < t; i++) add_e(t, i, 0);
        vector<int> inq(t + 1, 0); queue<int> q;
        q.push(t); h[t] = 0; inq[t] = 1;
        while (q.size()) {
            int u = q.front(); q.pop(); inq[u] = 0;
            for (auto &e : new_g[u]) {
                int v = new_edges[e].to, w = new_edges[e].w;
                if (h[v] > h[u] + w) {
                    h[v] = h[u] + w;
                    if (!inq[v]) {
                        q.push(v); inq[v] = 1;
                    }
                }
            }
        }

        for (auto &e : new_edges) e.w = e.w + h[e.from] - h[e.to];

        auto dij = [&] (int s) {
            vector<int> dis(t + 1, INF), vis(t + 1, 0);
            priority_queue<pii, vector<pii>, greater<pii>> pq;
            pq.push({0, s}); dis[s] = 0;
            while (pq.size()) {
                auto [d, u] = pq.top(); pq.pop();
                if (vis[u]) continue;
                vis[u] = 1;
                for (auto &e : new_g[u]) {
                    int v = new_edges[e].to, w = new_edges[e].w;
                    if (dis[v] > dis[u] + w) {
                        dis[v] = dis[u] + w;
                        pq.push({dis[v], v});
                    }
                }
            }
            return dis;
        };


        for (int i = 0; i < m; i++) {
            auto dis = dij(i);
            if (dis[i + m] == INF) // 不存在负环
                ans[a[i]] = 0;
            else
                ans[a[i]] = dis[i + m];
        }        
    }

    for (int i = 0; i < n; i++) 
        if (ans[i] == -INF) cout << "Haha, stupid Honkai" << '\n';
        else if (ans[i] == 0) cout << "Battle with the crazy Honkai" << '\n';
        else cout << ans[i] << '\n';

    return 0;
}