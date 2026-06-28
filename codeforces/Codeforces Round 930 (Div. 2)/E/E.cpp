#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
const LL INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];
    vector<vector<int> > a(n, vector<int>(m));
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            cin >> a[i][j];

    auto get = [&] (int x, int y) {
        return x * n + y;
    };

    int t = 2 * n + n * m;
    vector<vector<pii> > g(t);
    for (int i = 0; i < n; i++) 
        g[i].push_back({i + n, c[i]});
    vector<int> id(n);
    iota(id.begin(), id.end(), 0);
    for (int i = 0; i < m; i ++) {
        sort (id.begin(), id.end(), [&](int x, int y) {
            return a[x][i] < a[y][i];
        });
        for (int j = 0; j + 1 < n; j++) {
            g[2 * n + get(i, j)].push_back({2 * n + get(i, j + 1), 0});
            g[2 * n + get(i, j + 1)].push_back({2 * n + get(i, j), - a[id[j]][i] + a[id[j + 1]][i]});
        }
        for (int j = 0; j < n; j++) {
            g[2 * n + get(i, j)].push_back({id[j], 0});
            g[id[j] + n].push_back({2 * n + get(i, j), 0});
        }
    }

    vector<LL> dis(t, INF); vector<bool> vis(t, 0);
    priority_queue<pair<LL,int> , vector<pair<LL,int> >, greater<pair<LL,int> > > q; 
    dis[n] = 0; q.push({0, n}); 
    while (!q.empty()) {
        auto [d, u] = q.top(); q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto [v, w] : g[u]) {
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q.push({dis[v], v});
            }
        }
    }
    cout << dis[2 * n - 1] << '\n';
}

int main() {
    freopen ("E.in" ,"r", stdin);
    ios::sync_with_stdio();
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while (T--) solve();
    return 0;
}