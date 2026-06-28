#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int flg[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
const int inf = 0x3f3f3f3f;
int main() {
    freopen ("G.in", "r", stdin);
    int n, m, k; cin >> n >> m >> k;
    vector<pii> a(k);
    vector<vector<int> > mp(n + 1, vector<int>(m + 1, 0));
    for (auto &[x, y] : a) cin >> x >> y;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            char ch; cin >> ch;
            if (ch == '.') mp[i][j] = 1;
            if (ch == '#') mp[i][j] = 2;
        }
    for (int i = 0; i < k; i++) {
        auto [x, y] = a[i];
        mp[x][y] = -i;
    }

    priority_queue<pair<int, pii>, vector<pair<int, pii> >, greater<pair<int, pii> > > pq;

    vector<int> min_stp (k, inf);

    if (k > 1) {
        for (int i = 1; i < k; i++) {
            int x = i + 1;
            min_stp[i] = k - 2 + x - 1;
        }
    }

    auto bfs1 = [&] (pii st) {
        vector<vector<int> > dis(n + 1, vector<int>(m + 1, 0)), vis(n + 1, vector<int>(m + 1, 0));
        queue<pii> q; q.push(st); dis[st.first][st.second] = 0; vis[st.first][st.second] = 1;
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();

            auto calc = [&] (int x, int y) -> void {
                int op = 0, idx = -mp[x][y];
                if (dis[x][y] - mp[x][y] < k) op = k - (dis[x][y] - mp[x][y]);  //往外面绕
                min_stp[idx] = min(min_stp[idx], op + dis[x][y]);
            };

            for (int i = 0; i < 4; i++) {
                int nx = x + flg[i][0], ny = y + flg[i][1];
                if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
                if (mp[nx][ny] == 2 || vis[nx][ny]) continue;
                dis[nx][ny] = dis[x][y] + 1; vis[nx][ny] = 1;
                if (mp[nx][ny] < 0) calc(nx, ny);
                if (dis[nx][ny] - mp[nx][ny] >= k)
                    q.push({nx, ny});
            }
        }
        return ;
    };
    
    bfs1(a[0]); min_stp[0] = 0;
    for (int i = 0; i < k; i++) 
        pq.push({min_stp[i], a[i]});

    for (int i = 0; i < k; i++)
        cout << min_stp[i] << " ";
    cout << endl;
    vector<vector<int> > vis(n + 1, vector<int>(m + 1, 0)), dis(n + 1, vector<int>(m + 1, 0));
    deque<pii> q;
    
    for (auto [x, y] : a) vis[x][y] = 1;

    while (!pq.empty()) {

        auto get_q = [&] () {
            auto [op, st] = pq.top(); pq.pop();
            auto [x, y] = st;
            q.push_front(st); dis[x][y] = op;
        };

        if (!pq.empty())
            get_q();

        while (!q.empty()) {
            while (!pq.empty()&& pq.top().first == dis[q.front().first][q.front().second]) 
                get_q();
            auto [x, y] = q.front(); q.pop_front();
            for (int i = 0 ; i < 4; i++) {
                int nx = x + flg[i][0], ny = y + flg[i][1];
                if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
                if (mp[nx][ny] == 2 || vis[nx][ny]) continue;
                vis[nx][ny] = 1; dis[nx][ny] = dis[x][y] + 1;
                q.push_back({nx, ny});
            }
        }
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++)
            cout << dis[i][j] << " ", ans += 1ll * dis[i][j] * dis[i][j];
        cout << endl;
    }
    cout << ans << endl;
    return 0;
}