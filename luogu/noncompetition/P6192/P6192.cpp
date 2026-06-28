#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N, M, K; cin >> N >> M >> K;
    vector<vector<pair<int, int>>> g(N + 1);
    vector<vector<int>> dp(N + 1, vector<int>(1 << K, INF));
    vector<int> p(K + 1);
    for (int i = 1; i <= M; i++)  {
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({v, w}); g[v].push_back({u, w});
    }
    for (int i = 1; i <= K; i++) {
        cin >> p[i];
        dp[p[i]][1 << (i - 1)] = 0;
    }
    queue<int> q;
    vector<int> vis(N + 1, 0);
    for (int S = 0; S < (1 << K); S++) {
        for (int i = 1; i <= N; i++) {
            for (int S_ = S; S_; S_ = (S_ - 1) & S) {
                dp[i][S] = min(dp[i][S], dp[i][S_] + dp[i][S ^ S_]);
            }
            if (dp[i][S] < INF)
                q.push(i), vis[i] = 1;
        }
        while (!q.empty()) {
            int u = q.front(); q.pop(); vis[u] = 0;
            for (auto [v, w] : g[u]) {
                if (dp[v][S] > dp[u][S] + w) {
                    dp[v][S] = dp[u][S] + w;
                    if (!vis[v])
                        q.push(v), vis[v] = 1;
                }
            }
        }
    }
    cout << dp[p[1]][(1 << K) - 1] << '\n';
    return 0;
}