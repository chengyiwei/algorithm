#include <bits/stdc++.h>

int main() {
    freopen ("in.in", "r", stdin);
    int n, m; std::cin >> m; n = 1050;
    std::vector<std::vector<std::pair<int, int>>> g(n + 1);
    std::vector<int> du(n + 1, 0);
    int cnt = 0;
    for (int i = 1; i <= m; i++) {
        int x, y; std::cin >> x >> y;
        g[x].push_back({y, cnt++});
        g[y].push_back({x, cnt++});
        du[x]++; du[y]++;
    }

    for (int i = 1; i <= n; i++)
        std::sort(g[i].begin(), g[i].end());

    int st = -1; // 起点
    for (int i = 1; i <= n; i++) {
        if (du[i] > 0 && st == -1) st = i;
        if (du[i] & 1) {
            st = i;
            break;
        }
    }

    std::vector<int> vis(cnt, 0);
    std::stack<int> stk;
    std::function<void(int)> dfs = [&](int u) {
        for (auto &[v, id] : g[u]) {
            if (vis[id]) continue;
            vis[id] = 1; vis[id ^ 1] = 1;
            dfs(v);
        }
        stk.push(u);
    };

    dfs(st);

    while (!stk.empty()) {
        std::cout << stk.top() << "\n";
        stk.pop();
    }

    return 0;
}