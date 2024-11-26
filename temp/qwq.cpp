#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 5;

int mp[MAXN][MAXN];
int vis[MAXN][MAXN];
int dis[MAXN][MAXN];
int pre[MAXN][MAXN];

const int flg[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
char v[4] = {'D', 'U', 'R', 'L'};

int main() {
    freopen ("qwq.in", "r", stdin);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> mp[i][j], mp[i][j] = -mp[i][j];
    
    memset(dis, 0x3f, sizeof(dis));
    queue<pair<int, int>> q;
    q.push({1, 1}); vis[1][1] = 1; dis[1][1] = mp[1][1];
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        cout << x << " " << y << " " << dis[x][y] << '\n';
        vis[x][y] = 0;
        for (int i = 0; i < 4; i++) {
            int nx = x + flg[i][0], ny = y + flg[i][1];
            if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if (dis[nx][ny] > dis[x][y] + mp[nx][ny]) {
                dis[nx][ny] = dis[x][y] + mp[nx][ny];
                pre[nx][ny] = i;
                if (!vis[nx][ny]) q.push({nx, ny}), vis[nx][ny] = 1;
            }
        }
    }
    cout << -dis[n][m] << '\n';
    int x = n, y = m;
    vector<char> ans;
    while (x != 1 || y != 1) {
        ans.push_back(v[pre[x][y]]);
        int nx = x - flg[pre[x][y]][0], ny = y - flg[pre[x][y]][1];
        x = nx, y = ny;
    }
    reverse(ans.begin(), ans.end());
    for (auto i : ans) cout << i;
    cout << '\n';
    return 0;
}