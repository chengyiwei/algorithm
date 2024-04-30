#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
typedef pair<int,int> pii;
typedef unsigned long long ull;
const int flg[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int read() {
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}

int read_ch() {
    char ch = getchar();
    while (ch != '.' && ch != '#') ch = getchar();
    return ch;
}

int main() {
    freopen ("G.in", "r", stdin);
    int N = read(), M = read(), K = read();
    vector<pii> node(1 + K);
    vector<vector<int> > mp(N + 1, vector<int>(M + 1, 0));
    for (int i = 1; i <= K; i++) {
        int x = read(), y = read();
        node[i] = {x, y};
    }
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++) {
            char ch = read_ch();
            if (ch == '#') mp[i][j] = -1;
        }
    for (int i = 1; i <= K; i++) {
        auto [x, y] = node[i];
        mp[x][y] = i;
    }

    priority_queue<pair<int, pii>, vector<pair<int, pii> >, greater<pair<int, pii> > > pq;
    vector<vector<int> > dis(N + 1, vector<int>(M + 1, inf));
    auto [sx, sy] = node[1];
    pq.push({0, {sx, sy}}); deque<pii> q;
    while (!pq.empty()) {

        auto get_node = [&] () -> bool{
            if (pq.empty()) return false;
            auto [d, u] = pq.top(); auto [x, y] = u;
            if (dis[x][y] != inf) { pq.pop(); return true;}
            auto [nx, ny] = q.front();
            if (q.empty() || d <= dis[nx][ny]) {
                pq.pop();
                dis[x][y] = d;
                q.push_front(u);
                return true;
            }
            return false;
        };

        while (get_node()) ;
        
        while (!q.empty()) {
            while (get_node()) ;
            auto [x, y] = q.front(); q.pop_front();
            for (int i = 0; i < 4; i++) {
                int nx = x + flg[i][0], ny = y + flg[i][1];
                if (nx < 1 || nx > N || ny < 1 || ny > M || mp[nx][ny] == -1 || dis[nx][ny] != inf) continue;
                if (mp[nx][ny] == 0) {
                    dis[nx][ny] = dis[x][y] + 1;
                    q.push_back({nx, ny});
                }
                else {
                    int d = dis[x][y] + 1 + max(0, K - dis[x][y] - mp[nx][ny]);
                    pq.push({d, {nx, ny}});
                }
            }
        }
    }
    ull e = 1, ans = 0;
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= M; j++) {
            if (dis[i][j] == inf) dis[i][j] = 0;
            // printf("%d ", dis[i][j]);
            ans += e * dis[i][j] * dis[i][j];
        }
        // printf("\n");
    }
    printf("%llu\n", ans);
    return 0;
}