#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int inf = 1e9;
const int flg[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
struct Node {
    pii pos; int val;
};

int main() {
    freopen ("D.in", "r", stdin);
    int H, W; cin >> H >> W;
    pii st, ed;
    vector<vector<char> > mp(H + 2, vector<char>(W + 2, '#'));
    
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            cin >> mp[i][j];
            if (mp[i][j] == 'S') st = {i, j};
            if (mp[i][j] == 'T') ed = {i, j};
        }
    }
    int N, id_s = 0; cin >> N;
    vector<Node> a(N + 2);
    
    for (int i = 1; i <= N; i++) {
        cin >> a[i].pos.first >> a[i].pos.second >> a[i].val;
        if (a[i].pos == st) id_s = i;
    }
    a[N + 1].pos = ed; a[N + 1].val = 0;

    vector<vector<int> > g(N + 2,vector<int>());
    for (int i = 1; i <= N; i++) {
        auto bfs = [&] (pii s) {
            vector<vector<int> > dis (H + 2, vector<int>(W + 2, -1));
            queue<pii> q;
            q.push(s);
            dis[s.first][s.second] = 0;
            while (!q.empty()) {
                auto [x, y] = q.front(); q.pop();
                for (int k = 0; k < 4; k++) {
                    int nx = x + flg[k][0], ny = y + flg[k][1];
                    if (mp[nx][ny] == '#' || dis[nx][ny] != -1) continue;
                    dis[nx][ny] = dis[x][y] + 1;
                    q.push({nx, ny});
                }
            }
            return dis;
        };
        auto dis = bfs(a[i].pos);
        for (int j = 1; j <= N + 1; j++) {
            if (i == j) continue;
            auto [x, y] = a[j].pos;
            if (dis[x][y] != -1 && dis[x][y] <= a[i].val)
                g[i].push_back(j);
        }
    }
    if (id_s == 0) return cout << "No" << '\n', 0;
    vector<int> dis(N + 2, -1);
    queue<int> q; q.push(id_s); dis[id_s] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto v : g[u]) {
            if (dis[v] != -1) continue;
            dis[v] = dis[u] + 1;
            q.push(v);
            if (v == N + 1) return cout << "Yes" << '\n', 0;
        }
    }
    return cout << "No" << '\n', 0;
}