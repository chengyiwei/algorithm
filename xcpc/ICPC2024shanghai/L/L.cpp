#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

void solve() {
    int N, M, K; cin >> N >> M >> K;
    vector<vector<int>> g(N + 1);
    vector<vector<int>> p(N + 1);
    for (int i = 1; i <= N; i++) {
        int k; cin >> k;
        for (int j = 0; j < k; j++) {
            int x; cin >> x;
            g[i].push_back(x);
        }
    }
    for (int i = 1; i <= M; i++) {
        int u, v; cin >> u >> v;
        p[u].push_back(v);
    }
    vector<int> dp(N + 1, INF);
    
    for (int i = 1; i <= K; i++) {
        int x; cin >> x;
        dp[x] = 0;
    }

    auto dfs = [&] (auto &&dfs, int u) -> void {
        if (g[u].size() == 0) return ;
        int nxt = -1;
        int cnt = 0;
        for (auto v : g[u]) {
            dfs(dfs, v);
            cnt += dp[v] == INF;
        }
        if (cnt == 0) {
            dp[u] = 0;
            for (auto v : g[u]) dp[u] += dp[v];
        }
        for (auto v : p[u]) {
            if (dp[v] == INF) continue;
            dp[u] = min(dp[u], dp[v] + 1);
        }
    };

    dfs(dfs, 1);
    cout << (dp[1] != INF ? dp[1] : -1) << "\n";
    // cout << INF << "\n";
}

int main() {
    freopen ("L.in", "r", stdin);
    ios::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}