#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, c; cin >> n >> c;

    vector<ll> a(n + 1);
    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<array<ll, 2>> dp(n + 1, {0, 0});

    auto dfs = [&](auto &&dfs, int u, int f) -> void {
        for (auto v : g[u]) {
            if (v == f) continue;
            dfs(dfs, v, u);
            dp[u][1] += max(dp[v][0], dp[v][1] - 2 * c);
            dp[u][0] += max(dp[v][0], dp[v][1]);
        }

        dp[u][1] += a[u];
    };

    dfs(dfs, 1, 0);

    cout << max({0ll, dp[1][0], dp[1][1]}) << '\n';
}

int main() {
    freopen ("C.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}