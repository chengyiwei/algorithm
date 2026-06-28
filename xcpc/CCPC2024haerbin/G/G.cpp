#include <bits/stdc++.h>

int main() {
    freopen ("G.in", "r", stdin);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int n, m, k; std::cin >> n >> m >> k;
    std::vector<std::vector<int>> g(n + 1);
    std::vector<int> b(n + 1, 0);
    for (int i = 1; i <= k; i++) {
        int x; std::cin >> x;
        b[x] = 1;
    }
    
    for (int i = 1; i <= m; i++) {
        int u, v; std::cin >> u >> v;
        g[u].push_back(v); g[v].push_back(u);
    }

    int st = -1;
    for (int i = 1; i <= n; i++) {
        if (b[i] != 1) {st = i; break;} 
    }

    if (st == -1) {std::cout << "No\n"; return 0;}

    std::vector<int> vis(n + 1, 0);
    std::queue<int> q; q.push(st); vis[st] = 1;

    std::vector<std::vector<int>> ans;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        std::vector<int> now;
        now.push_back(u);
        for (auto v : g[u]) if (!vis[v]) {
            now.push_back(v);
            vis[v] = 1;
            if (!b[v]) q.push(v);
        }
        if (now.size() > 1)
            ans.push_back(now);
    }

    if ((*std::min_element(vis.begin() + 1, vis.end())) == 0) {
        std::cout << "No\n"; return 0;
    }

    std::cout << "Yes\n";
    std::cout << ans.size() << "\n";
    for (auto &now : ans) {
        std::cout << now.front() << " " << now.size() - 1 << " ";
        for (int i = 1; i < now.size(); i++)
            std::cout << now[i] << " ";
        std::cout << "\n";
    }
    return 0;
}