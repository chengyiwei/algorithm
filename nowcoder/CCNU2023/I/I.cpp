#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n + 5, vector<int>(m + 5, -1));
    auto ok = a;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ok[i][j] = 1;
        }
    }
    ok[n][m + 1] = 1;
    for (int i = 1; i <= k; i++) {
        int x, y, t;
        cin >> x >> y >> t;
        a[x][y] = t;
    }
    using tup = tuple<int, int, int>;
    deque<tup> q;
    const vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    const int inf = 1e9;
    vector<vector<vector<int>>> dis(n + 5, vector<vector<int>>(m + 5, vector<int>(5, inf)));
    dis[1][1][0] = 0;
    q.emplace_back(1, 1, 0);
    while (q.size()) {
        auto [x, y, u] = q.front();
        q.pop_front();
        if (a[x][y] == -1) {
            auto [dx, dy] = dir[u];
            int tx = x + dx, ty = y + dy;
            if (ok[tx][ty] == -1) continue;
            if (dis[x][y][u] < dis[tx][ty][u]) {
                dis[tx][ty][u] = dis[x][y][u];
                q.emplace_front(tx, ty, u);
            }
        } else {
            for (int t : {0, 1}) {
                int w = (t != a[x][y]);
                int nu = u ^ (1 + t + t);
                auto [dx, dy] = dir[nu];
                int tx = x + dx, ty = y + dy;
                if (ok[tx][ty] == -1) continue;
                if (dis[x][y][u] + w < dis[tx][ty][nu]) {
                    dis[tx][ty][nu] = dis[x][y][u] + w;
                    if (w == 0) q.emplace_front(tx, ty, nu);
                    else q.emplace_back(tx, ty, nu);
                }
            }
        }
    }
    int res = dis[n][m + 1][0];
    if (res > inf / 2) res = -1;
    cout << res << '\n';
    return 0;
}