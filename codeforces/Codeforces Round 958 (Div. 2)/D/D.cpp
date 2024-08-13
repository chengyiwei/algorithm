#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll inf = 0x3f3f3f3f3f3f3f3f;  // 4611686018427387903
const int tp = 31;
const int maxn = 3e5 + 5;
ll dp[maxn][tp];
void solve() {
    int n; cin >> n;
    vector<ll> w(n + 1, 0);
    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < tp; j++) dp[i][j] = 0;
    }

    auto dfs = [&] (auto &&dfs, int u, int fa) -> void {
        for (int v : g[u]) {
            if (v == fa) continue;
            dfs(dfs, v, u);
        }
        for (int j = 0; j < tp; j++) {
            for (int v : g[u]) {
                if (v == fa) continue;
                ll now = inf;
                for (int j_ = 0; j_ < tp; j_++) {
                    if (j == j_) continue;
                    now = min(now, dp[v][j_]);
                }
                dp[u][j] += now;
            }
            dp[u][j] += w[u] * (j + 1);
        }
    };

    ll ans = inf;
    dfs (dfs, 1, 1);
    for (int i = 0; i < tp; i++) ans = min(ans, dp[1][i]);
    cout << ans << '\n';
}

int main() {
    freopen ("D.in", "r", stdin);
    freopen ("D.out", "w", stdout);
    ios::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}