#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vvi;

int main() {
    freopen ("A.in", "r", stdin);
    ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    
    auto flip = [&](int x, int y, vvi a) {
        auto b = a;
        for (int dx = 0; dx < n - 1; dx++)
            for (int dy = 0; dy < m - 1; dy++)
                b[x + dx][y + dy] = a[x + n - 2 - dx][y + m - 2 - dy];
        return b;
    };

    auto bfs = [&](vvi a) {
        map<vvi, int> res;
        queue<vvi> q; q.push(a); res[a] = 0;
        while (!q.empty()) {
            vvi t = q.front(); q.pop();
            int d = res[t];
            if (d >= 10) break;
            for (int x = 0; x <= 1; x++)
                for (int y = 0; y <= 1; y++) {
                    vvi b = flip(x, y, t);
                    if (!res.count(b)) {
                        res[b] = d + 1;
                        q.push(b);
                    }
                }
        }
        return res;
    };

    vvi b(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            b[i][j] = i * m + j + 1;
    
    auto res1 = bfs(a);
    auto res2 = bfs(b);
    int ans = 22;
    for (auto &[v, d] : res2) {
        if (res1.count(v)) ans = min(ans, res1[v] + d);
    }
    cout << (ans > 20 ? -1 : ans) << '\n';
    return 0;
}