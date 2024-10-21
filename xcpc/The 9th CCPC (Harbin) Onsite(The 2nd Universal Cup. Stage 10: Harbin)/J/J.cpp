#include <bits/stdc++.h>

int main() {
    freopen ("J.in", "r", stdin);
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    int n, m; std::cin >> n >> m;
    std::vector<std::pair<int, int>> edges;
    std::vector<std::vector<int>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v; std::cin >> u >> v;
        edges.push_back({u, v});
        g[u].push_back(v); g[v].push_back(u);
    }

    std::function<int(int)> sg = [&](int u) {
        if (u == 0) return 0;
        if (u & 1) return 1;
        else return 2;
    };

    std::vector<int> from(n + 1, 0), siz(n + 1, 0);
    std::function<void(int, int, int)> dfs = [&](int u, int fa, int frm) {
        from[u] = frm;
        siz[u] = 1;
        for (int v : g[u]) {
            if (v == fa) continue;
            dfs(v, u, frm);
            siz[u] += siz[v];
        }
    };

    int cnt = 0, SG = 0;
    for (int i = 1; i <= n; i++) if (siz[i] == 0) {
        dfs(i, 0, i); cnt += 1;
        SG = SG ^ sg(siz[i]);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int now_sg = SG ^ sg(siz[from[i]]);
        for (auto v : g[i]) {
            if (siz[v] > siz[i]) continue;
                now_sg = now_sg ^ sg(siz[v]);
        }
        now_sg = now_sg ^ sg(siz[from[i]] - siz[i]);
        if (now_sg == 0) ans += 1;
    }
    for (auto [u, v] : edges) {
        int now_sg = SG ^ sg(siz[from[u]]);
        int siz_ = std::min(siz[u], siz[v]);
        now_sg ^= sg(siz_); now_sg ^= sg(siz[from[u]] - siz_);
        if (now_sg == 0) ans += 1;
    }

    std::cout << ans << '\n';
    return 0;
}