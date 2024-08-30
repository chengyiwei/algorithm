#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;

struct Tarjan {
    int n; // index from 1
    vector<int> low, dfn;
    vector<pair<int, int>> bridge;
    int cnt;

    Tarjan(int n_) {
        n = n_;
        low.resize(n + 1); dfn.resize(n + 1);
        cnt = 0; bridge.clear();
    }

    void tarjan(int u, int fa = -1) {
        dfn[u] = low[u] = ++cnt;
        for (int v : g[u]) {
            if (v == fa) continue;
            if (!dfn[v]) {
                tarjan(v, u);
                low[u] = min(low[u], low[v]);
                if (low[v] > dfn[u]) bridge.push_back({u, v});
            } else {
                low[u] = min(low[u], dfn[v]);
            }
        }
    }
};

int main() {

}