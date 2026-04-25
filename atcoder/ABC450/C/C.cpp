#include <bits/stdc++.h>
using namespace std;

const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<vector<char>> a(n + 1, vector<char>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    int ans = 0;
    vector<vector<int>> vis(n + 1, vector<int>(m + 1)); // 这个点是否被遍历过

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == '#' || vis[i][j]) continue;
            int flg = 1; // 是否接触边框， 1 没有， 0 有
            queue<pair<int, int>> q; // bfs

            q.push({i, j});  vis[i][j] = 1;
            if (i == 1 || i == n || j == 1 || j == m) flg = 0; // 接触边框
            // bfs 遍历这个连通块
            while (!q.empty()) {
                auto [x, y] = q.front(); q.pop();
                for (int k = 0; k < 4; k++) {
                    int next_x = x + dx[k], next_y = y + dy[k];
                    if (next_x < 1 || next_x > n || next_y < 1 || next_y > m || a[next_x][next_y] == '#' || vis[next_x][next_y]) continue;
                    if (next_x == 1 || next_x == n || next_y == 1 || next_y == m) flg = 0; // 接触边框
                    q.push({next_x, next_y}); vis[next_x][next_y] = 1;   
                }
            }

            ans += flg; // 如果没有接触边框， ans 加 1
        }
    }

    cout << ans << '\n';
    return 0;
}

/*
1 3
.#.
*/