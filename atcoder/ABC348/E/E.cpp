#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
int main() {
    freopen ("E.in", "r", stdin);
    freopen ("E.out", "w", stdout);
    int N; cin >> N;
    vector<vector<int> > g(N + 1, vector<int>());
    vector<ll> c(N + 1); ll c_sum = 0;
    for (int i = 1; i < N; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v); g[v].push_back(u);
    }
    for (int i = 1; i <= N; i++) {
        cin >> c[i]; c_sum += c[i];
    }
    vector<ll> dp(N + 1, 0);
    vector<ll> sz(N + 1, 0), dis(N + 1, 0);
    function<void(int, int)> dfs_1 = [&] (int u, int fa) {
        sz[u] = c[u];
        for (auto v : g[u]) {
            if (v == fa) continue;
            dis[v] = dis[u] + 1;
            dfs_1(v, u);
            sz[u] += sz[v];
        }
    };
    dfs_1(1, 0);
    for (int i = 1; i <= N; i++)
        dp[1] += c[i] * dis[i];
    function<void(int, int)> dfs_2 = [&] (int u, int fa) {
        for (auto v : g[u]) {
            if (v == fa) continue;
            dp[v] = dp[u] - sz[v] + (c_sum - sz[v]);
            dfs_2(v, u);
        }
    };
    dfs_2(1, 0);
    ll ans = *min_element(dp.begin() + 1, dp.end());
    cout << ans << '\n';
    return 0;
}