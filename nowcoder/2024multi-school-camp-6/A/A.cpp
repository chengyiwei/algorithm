#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<vector<pair<int, int>>> g(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({v, w}); g[v].push_back({u, w});
    }
    vector<int> dep(n + 1); dep[1] = 1;
    vector<double> f(n + 1); f[1] = 0; // f 表示前缀 0 的最大占比
    vector<array<int, 2>> cnt(n + 1); cnt[0] = {0, 0}; 

    function<void(int, int)> dfs1 = [&] (int u, int fa) {
        if (u != 1) 
            f[u] = max(1.0 * f[u], 1.0 * cnt[u][0] / (cnt[u][0] + cnt[u][1]));
        for (auto [v , w] : g[u]) {
            if (v == fa) continue;
            dep[v] = dep[u] + 1;
            cnt[v] = cnt[u]; cnt[v][w] += 1;
            f[v] = f[u];
            dfs1 (v, u);
        }
    };

    vector<double> dp(n + 1); // dp 表示走到 u 的最优解
    function<void(int, int)> dfs2 = [&] (int u, int fa) {
        if (dep[u] & 1) dp[u] = 1;
        else dp[u] = 0;
        int flg = 0;
        for (auto [v, w] : g[u]) {
            if (v == fa) continue;
            dfs2(v, u);
            flg = 1;
            if (dep[u] & 1) dp[u] = min(dp[u], dp[v]);
            else dp[u] = max(dp[u], dp[v]);
        }
        if (!flg) dp[u] = f[u];
    };

    dfs1(1, 0);
    dfs2(1, 0);
    cout << fixed << setprecision(10) << 1 - dp[1] << '\n';
}

int main() {
    freopen ("A.in", "r", stdin);
    ios::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}