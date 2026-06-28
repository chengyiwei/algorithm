#include <bits/stdc++.h>
using namespace std;

int n, m, k;
vector<vector<int>> g;

bool dfs_augment(int u, vector<int>& matchR, vector<int>& vis) {
    for (int v : g[u]) {
        if (vis[v]) continue;
        vis[v] = 1;
        if (!matchR[v] || dfs_augment(matchR[v], matchR, vis)) {
            matchR[v] = u;
            return true;
        }
    }
    return false;
}

int base_matching(vector<int>& matchR) {
    matchR.assign(m + 1, 0);
    int res = 0;
    for (int u = 1; u <= n; u++) {
        vector<int> vis(m + 1, 0);
        if (dfs_augment(u, matchR, vis)) res++;
    }
    return res;
}

int solve_topdeg_only() {
    vector<int> baseMatchR;
    int base = base_matching(baseMatchR);
    int mx = min(m, n + 2);

    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 1);
    sort(ord.begin(), ord.end(), [&](int a, int b) {
        if (g[a].size() != g[b].size()) return g[a].size() > g[b].size();
        return a < b;
    });

    int K = n;
    int ans = base;

    for (int i = 0; i < K; i++) {
        int x = ord[i];
        vector<int> matchR = baseMatchR;
        int cur = base;

        for (int rep = 0; rep < 2; rep++) {
            vector<int> vis(m + 1, 0);
            if (dfs_augment(x, matchR, vis)) cur++;
        }

        ans = max(ans, cur);
    }

    return min(ans, mx);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    g.assign(n + 1, {});

    for (int i = 0; i < k; i++) {
        int u, v;
        cin >> u >> v;
        if (1 <= u && u <= n && 1 <= v && v <= m) {
            g[u].push_back(v);
        }
    }

    for (int u = 1; u <= n; u++) {
        sort(g[u].begin(), g[u].end());
        g[u].erase(unique(g[u].begin(), g[u].end()), g[u].end());
    }

    cout << solve_topdeg_only() << '\n';
    return 0;
}
/*
3 5 7
1 1
1 2
2 2
2 3
2 4
3 4
3 5
*/