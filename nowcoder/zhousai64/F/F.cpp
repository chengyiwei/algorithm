#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;

using ll = long long;

int n, _;
vector<int> g[MAXN];
int X, Y;

int vis[MAXN], b[MAXN], dis[MAXN];

bool dfs(int u, int fa) {
    if (u == Y) {
        vis[u] = 1;
        return true;
    }
    for (auto v : g[u]) {
        if (v == fa) continue;
        if (dfs(v, u)) {
            vis[u] = 1;
            return true;
        }
    }
    return false;
}

int main() {
    freopen ("F.in", "r", stdin);
    cin >> n >> _;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v); g[v].push_back(u);
    }
    while (_--) {
        cin >> X >> Y;

        for (int i = 1; i <= n; i++) vis[i] = 0, b[i] = 0;

        dfs(X, 0);

        queue<int> q;
        for (int i = 1; i <= n; i++) if (vis[i] == 1) {
            q.push(i);
            dis[i] = 0;
            b[i] = 1;
        }

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto v : g[u]) {
                if (b[v] == 0) {
                    b[v] = 1;
                    dis[v] = dis[u] + 1;
                    q.push(v);
                }
            }
        }
        ll ans = 0;
        for (int i = 1; i <= n; i++)
            ans += dis[i];
        cout << ans << '\n';
    }
    return 0;
}