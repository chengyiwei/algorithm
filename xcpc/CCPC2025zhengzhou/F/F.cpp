#include <bits/stdc++.h>
using namespace std;

const int flg[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> mp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            char c; cin >> c;
            if (c == '#') mp[i][j] = 1;
            else mp[i][j] = 0;
        }

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         cout << mp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    vector<vector<int>> op(n + 1, vector<int>(m + 1, 1));

    auto bfs = [&] (int sx, int sy) {
        queue<pair<int, int>> q;
        vector<vector<int>> vis(n + 1, vector<int>(m + 1, 0));
        q.push({sx, sy});
        vis[sx][sy] = 1;
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            op[x][y] = 0; // mark as visited
            for (int j = 0; j < 4; j++) {
                int nx = x + flg[j][0], ny = y + flg[j][1];
                if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
                if (mp[nx][ny] == 1 || vis[nx][ny]) continue;
                vis[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    };

    bfs(1, 1); 
    bfs(n, m);

    deque<pair<int, int>> q;
    vector<vector<int>> vis(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> dis(n + 1, vector<int>(m + 1, 0));
    q.push_back({1, 1}); vis[1][1] = 1; dis[1][1] = 0;

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop_front();
        for (int j = 0; j < 4; j++) {
            int nx = x + flg[j][0], ny = y + flg[j][1];
            if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if (vis[nx][ny]) continue;
            if (op[nx][ny] == 0) {
                q.push_front({nx, ny});
                vis[nx][ny] = 1;
                dis[nx][ny] = dis[x][y];
            }
            else {
                q.push_back({nx, ny});
                vis[nx][ny] = 1;
                dis[nx][ny] = dis[x][y] + 1;
            }
        }
    };

    cout << dis[n][m] << "\n";
    return;
}

int main() {
    // freopen ("F.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(nullptr);

    int T; cin >> T;
    while (T--) solve();
}