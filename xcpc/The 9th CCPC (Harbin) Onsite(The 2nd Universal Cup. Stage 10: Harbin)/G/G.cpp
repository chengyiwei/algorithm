#include <bits/stdc++.h>

struct Wall {
    int x1, x2, y, id;
};

int main() {
    freopen ("G.in", "r", stdin);
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    int n, m, k; std::cin >> n >> m >> k;
    std::vector<Wall> walls(k);
    for (int i = 0; i < k; i++) {
        std::cin >> walls[i].x1 >> walls[i].x2 >> walls[i].y;
    }

    std::sort(walls.begin(), walls.end(), [&](const Wall &a, const Wall &b) {
        return a.y < b.y || (a.y == b.y && a.x1 < b.x1);
    });

    if (n == 1) {
        int l = 0, r = k - 1;
        while (l < k && walls[l].y == l + 1) l += 1;
        while (r >= 0 && walls[r].y ==  m - (k - 1 - r)) r -= 1;
        std::cout << (l > r ? "YES" : "NO") << '\n';
        return 0;
    }

    int cnt = 0, pos = 0;
    std::vector<std::vector<int>> g(10 * k);

    auto add_e = [&] (int u, int v) {
        g[u].push_back(v); g[v].push_back(u);
    };
    
    std::vector<Wall> v, pre_v;
    for (int i = 1; i <= m; i++) { // 枚举列
        pre_v = v; v.clear();
        while (pos < k && walls[pos].y == i) {
            if (pos == 0 || walls[pos].y != walls[pos - 1].y) {
                if (walls[pos].x1 > 1)
                    v.push_back({1, walls[pos].x1 - 1, i, ++cnt});
            }
            else {
                if (walls[pos - 1].x2 + 1  <= walls[pos].x1 - 1)
                    v.push_back({walls[pos - 1].x2 + 1, walls[pos].x1 - 1, i, ++cnt});
            }
            pos += 1;
        }
        if (pos == 0 || walls[pos - 1].y != i) {
            if (pre_v.size() == 1 && pre_v.back().x1 == 1 && pre_v.back().x2 == n) {
                std::cout << "NO\n";
                return 0;
            }
            v.push_back({1, n, i, ++cnt});
        }
        else if (walls[pos - 1].x2 < n) {
            v.push_back({walls[pos - 1].x2 + 1, n, i, ++cnt});
        }

        for (int pre_j = 0, j = 0; pre_j < pre_v.size(); pre_j++) {
            while (j < v.size() && v[j].x2 < pre_v[pre_j].x1) j += 1;
            while (j < v.size() && v[j].x1 <= pre_v[pre_j].x2) { // 相交
                int L = std::max(v[j].x1, pre_v[pre_j].x1), R = std::min(v[j].x2, pre_v[pre_j].x2);
                if (R ^ L) {
                    std::cout << "NO\n";
                    return 0;
                }
                add_e(v[j].id, pre_v[pre_j].id);
                if (v[j].x2 > pre_v[pre_j].x2) break;
                j += 1;
            }
        }
    }
    g.resize(cnt + 1);

    if (cnt == 1) {
        std::cout << "YES" << "\n";
        return 0;
    }

    std::vector<int> du(cnt + 1, 0);
    int num = 0; std::queue<int> q;
    for (int i = 1; i <= cnt; i++) du[i] = g[i].size();
    for (int i = 1; i <= cnt; i++) if (du[i] == 1)
        q.push(i), num += 1;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto v : g[u]) {
            if (--du[v] == 1) {
                q.push(v); num += 1;
            }
        }
    }

    std::cout << (num == cnt ? "YES" : "NO") << '\n';
    return 0;
}