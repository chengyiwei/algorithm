#include <bits/stdc++.h>
using namespace std;

struct Tarjan {
    int n, dfn_cnt, scc_cnt;
    vector<int> dfn, low, scc, in_st, siz;
    stack<int> st;
    vector<vector<int>> g;

    void init (int n_, vector<vector<int>> &g_) {
        n = n_; g = g_;
        dfn_cnt = scc_cnt = 0;
        dfn.resize(n + 1); low.resize(n + 1); scc.resize(n + 1); siz.resize(n + 1);
        while (!st.empty()) st.pop(); in_st.assign(n + 1, 0);
    }

    void tarjan (int u) {
        low[u] = dfn[u] = ++dfn_cnt; 
        st.push(u); in_st[u] = 1;
        for (int i = 0; i < g[u].size(); i++) {
            int &v = g[u][i];
            if (!dfn[v]) {
                tarjan(v);
                low[u] = min(low[u], low[v]);
            }else if (in_st[v])
                low[u] = min(low[u], dfn[v]);
        }
        if (dfn[u] == low[u]) {
            scc_cnt += 1;
            while (st.top() != u) {
                int x = st.top(); st.pop();
                in_st[x] = 0; scc[x] = scc_cnt; siz[scc_cnt] += 1;
            }
            int x = st.top(); st.pop();
            in_st[x] = 0; scc[x] = scc_cnt; siz[scc_cnt] += 1;
        }
    }
};

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
    }
    Tarjan tarjan; tarjan.init(n, g);
    for (int i = 1; i <= n; i++)
        if (!tarjan.dfn[i])
            tarjan.tarjan(i);
    
    vector<int> du(tarjan.scc_cnt + 1, 0);
    for (int u = 1; u <= n; u++)
        for (int v : g[u])
            if (tarjan.scc[u] != tarjan.scc[v])
                du[tarjan.scc[u]] += 1;
    int ans = 0, cnt = 0;
    for (int i = 1; i <= tarjan.scc_cnt; i++)
        if (!du[i]) {
            cnt += 1;
            ans += tarjan.siz[i];
        }
    cout << (cnt == 1 ? ans : 0) << '\n';
    return 0;
}