#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen ("F.in", "r", stdin);
    ios::sync_with_stdio(0);
    int n; cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> sz(n + 1), max_id(n + 1), ver;
    auto dfs = [&] (auto &&dfs, int u, int fa) -> void {
        sz[u] = 1;
        for (auto v : g[u]) {
            if (v == fa) continue;
            dfs(dfs, v, u);
            sz[u] += sz[v];
            if (sz[v] > sz[max_id[u]]) max_id[u] = v;
        }
        int w = max(sz[max_id[u]], n - sz[u]);
        if (w * 2 <= n) ver.push_back(u);
    };
    dfs(dfs, 1, 1);

    auto dfs2 = [&] (auto &&dfs2, int u, int fa, vector<int> &ans, int root) -> void {
        if (u != root) ans.push_back(u);
        for (auto v : g[u]) {
            if (v == fa) continue;
            dfs2(dfs2, v, u, ans, root);
        }
    };

    if (ver.size() == 1) {
        int root = ver[0];
        vector<int> ans;
        dfs2(dfs2, root, root, ans, root);
        ans.push_back(root);
        for (int i = 0; i < n / 2; i++)
            cout << ans[i] << " " << ans[i + n / 2] << '\n';
    }
    else {
        int root1 = ver[0], root2 = ver[1];
        vector<int> ans1, ans2;
        dfs2(dfs2, root1, root2, ans1, root1);
        ans1.push_back(root1);
        dfs2(dfs2, root2, root1, ans2, root2);
        ans2.push_back(root2);
        for (int i = 0; i < n / 2; i++)
            cout << ans1[i] << " " << ans2[i] << '\n';
    }
    return 0;
}