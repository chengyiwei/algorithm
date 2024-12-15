#include <bits/stdc++.h>
using namespace std;

const int flg[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main() {
    int n, m; cin >> n >> m;
    vector<vector<char>> mp(n + 1, vector<char>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cin >> mp[i][j];
    }

    pair<int, int> s, t;
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= m; j++) {
            if (mp[i][j] == 'S') s = {i, j};
            if (mp[i][j] == 'T') t = {i, j};
        }
    
    vector<vector<int>> vis(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> dis(n + 1, vector<int>(m + 1, 0));

    queue<pair<int, int>> q;
    q.push(s); vis[s.first][s.second] = 1;
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + flg[i][0], ny = y + flg[i][1];
            if (nx < 1 || nx > n || ny < 1 || ny > m) continue;

            if (mp[nx][ny] != '#' && vis[nx][ny] == 0) {
                vis[nx][ny] = 1;
                dis[nx][ny] = dis[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    if (vis[t.first][t.second] == 0) {
        cout << "NO" << endl;
        return 0;
    }


    cout << "YES" << endl;
    pair<int, int> now = t;
    while (now != s) {
        for (int i = 0; i < 4; i++) {
            int nx = now.first + flg[i][0], ny = now.second + flg[i][1];
            if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if (dis[nx][ny] == dis[now.first][now.second] - 1) {
                if (mp[nx][ny] != '#') {
                    mp[nx][ny] = '*';
                    now = {nx, ny};
                    break;
                }
            }
        }
    }
    mp[s.first][s.second] = 'S';

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cout << mp[i][j];
        cout << endl;
    }
    
    return 0;
}