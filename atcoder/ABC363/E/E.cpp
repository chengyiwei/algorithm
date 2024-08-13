#include <bits/stdc++.h>
using namespace std;

const int flg[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
typedef pair<int, int> pii;
typedef long long ll;

struct Node {
    int h; pii pos;
    bool operator < (const Node &a) const {
        return h > a.h;
    }
};

int main() {
    freopen ("E.in", "r", stdin);
    ios::sync_with_stdio(false);
    int n, m, Y; cin >> n >> m >> Y;
    ll sum = 0;
    vector<vector<int>> h(n + 1, vector<int>(m + 1)), vis(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> h[i][j], sum += 1;
    
    priority_queue<Node> pq;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (i == 1 || i == n || j == 1 || j == m) {
                pq.push({h[i][j], {i, j}});
                vis[i][j] = 1;
            }
        }
    
    int now_H = 0;
    for (now_H = 1; now_H <= Y; now_H += 1) {
        while (true) {
            if (pq.empty() || pq.top().h > now_H) break;
            Node cur = pq.top(); pq.pop(); sum -= 1;
            for (int i = 0; i < 4; i++) {
                auto [x, y] = cur.pos; int nx = x + flg[i][0], ny = y + flg[i][1];
                if (nx < 1 || nx > n || ny < 1 || ny > m || vis[nx][ny]) continue;
                if (!vis[nx][ny]) {
                    pq.push({h[nx][ny], {nx, ny}});
                    vis[nx][ny] = 1;
                }
            }
        }
        cout << sum << '\n';
    }
    return 0;
}