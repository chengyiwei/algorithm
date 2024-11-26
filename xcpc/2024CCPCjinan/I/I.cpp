#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<vector<int>> g(n + 1);
    vector<pair<int, int>> in;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        in.push_back({u, v});
        g[u].push_back(v); g[v].push_back(u);
    }

    vector<int> siz_son(n + 1, 0);
    vector<array<int, 2>> dp(n + 1);
    vector<pair<int, int>> ans;

    function<void(int, int)> dfs = [&] (int u, int fa) {
        dp[u][0] = dp[u][1] = 0;
        for (int v : g[u]) if (v != fa) {
            dfs(v, u);
            siz_son[u] += 1;    
        }
        if (siz_son[u] % 2 == 0) { // 儿子节点是偶数个
            dp[u][0] = 1;
            for (auto v : g[u]) if (v != fa) {
                if (dp[v][1] == 1)
                    dp[u][1] = 1;
            }
        }
        else { // 儿子节点是奇数个
            dp[u][1] = 1; 
            for (auto v : g[u]) if (v != fa) { 
                if (dp[v][1] == 1) 
                    dp[u][0] = 1;
            }
        }
    };

    function<int(int, int, int)> dfs2 = [&] (int u, int fa, int op) {
        if (op == 1) { // 需要往上连一个
            vector<int> son;
            int flg = 0;
            if (siz_son[u] % 2 == 0) {
                for (int i = 0; i < g[u].size(); i++) {
                    int v = g[u][i];
                    if (v == fa) continue;
                    if (dp[v][1] == 1 && flg == 0) {
                        int x = dfs2(v, u, 1);
                        ans.push_back({u, x});
                        flg = 1;
                    }
                    else son.push_back(v);
                }
            }
            else for (int v : g[u]) if (v != fa) son.push_back(v);
            assert(son.size() % 2 == 1);
            int res = (dp[son[0]][0] == 1? dfs2(son[0], u, 0): dfs2(son[0], u, 1));
            for (int i = 1; i + 1 < son.size(); i += 2) {
                int x = (dp[son[i]][0] == 1? dfs2(son[i], u, 0): dfs2(son[i], u, 1));
                int y = (dp[son[i + 1]][0] == 1? dfs2(son[i + 1], u, 0): dfs2(son[i + 1], u, 1));
                ans.push_back({x, y});
            }
            return res;
        }
        else { // 不连
            vector<int> son;
            if (siz_son[u] % 2 == 1) {
                int flg = 0;
                for (int i = 0; i < g[u].size(); i++) {
                    int v = g[u][i];
                    if (v == fa) continue;
                    if (dp[v][1] == 1 && flg == 0) {
                        int x = dfs2(v, u, 1);
                        ans.push_back({u, x});
                        flg = 1;
                    }
                    else son.push_back(v);
                }
            }
            else for (int v : g[u]) if (v != fa) son.push_back(v);
            assert(son.size() % 2 == 0);
            for (int i = 0; i + 1 < son.size(); i += 2) {
                int x = (dp[son[i]][0] == 1 ? dfs2(son[i], u, 0): dfs2(son[i], u, 1));
                int y = (dp[son[i + 1]][0] == 1? dfs2(son[i + 1], u, 0): dfs2(son[i + 1], u, 1));
                ans.push_back({x, y});
            }
            return u;
        }
    };

    dfs(1, 0);
    if (dp[1][0] == 0) {cout << "-1" << "\n"; return;}

    dfs2(1, 0, 0);
    cout << ans.size() << "\n";
    for (auto [u, v] : ans) cout << u << " " << v << "\n";
}

int main() {
    // freopen ("I.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}