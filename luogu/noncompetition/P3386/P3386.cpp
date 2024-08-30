#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen ("P3386.in", "r", stdin);
    int n, m, e; cin >> n >> m >> e;
    vector<vector<int>> g(n + m + 1);
    vector<int> vis(n + m + 1, 0), match(n + m + 1, 0);
    for (int i = 1; i <= e; i++) {
        int x, y; cin >> x >> y;
        g[x].push_back(y + n);
        g[y + n].push_back(x);
    }
    int ans = 0;

    auto dfs = [&] (auto &&dfs, int u) -> bool  {
        for (int v : g[u]) {
            if (vis[v]) continue;
            vis[v] = 1;
            if (!match[v] || dfs(dfs, match[v])) { //如果没有被匹配或者 和son匹配的那个点 可以找到新的点匹配，那么son就和x匹配
                match[u] = v;
                match[v] = u;
                return true;
            }
        }
        return false;
    };

    for (int i = 1; i <= n; i++) {
        if (!match[i]) {
            fill(vis.begin(), vis.end(), 0);
            if (dfs(dfs, i)) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}