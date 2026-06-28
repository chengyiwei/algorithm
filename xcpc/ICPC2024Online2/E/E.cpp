#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

void solve() {
    int n, m, D; cin >> n >> m >> D;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v); g[v].push_back(u);
    }
    int k; cin >> k;
    vector<int> s(k + 1);
    vector<int> dis[2]; dis[0].assign(n + 1, INF), dis[1].assign(n + 1, INF);
    queue<pair<int, int>> q;
    for (int i = 1; i <= k; i++) {
        cin >> s[i], dis[0][s[i]] = 0, q.push({0, s[i]});
    }

    while (!q.empty()) {
        auto [op, u] = q.front(); q.pop();
        for (auto v : g[u]) {
            if (dis[op ^ 1][v] > dis[op][u] + 1) {
                int tmp = dis[op][u] + 1;
                if (tmp > D) continue;
                dis[op ^ 1][v] = tmp;
                q.push({op ^ 1, v});
            }
        }
    }

    // for (int i = 1; i <= n; i++) 
    //     cout << dis[0][i] << " ";
    // cout << '\n';
    // for (int i = 1; i <= n; i++) 
    //     cout << dis[1][i] << " ";
    // cout << '\n';
    
    vector<int> dis_o[2]; dis_o[0].assign(n + 1, INF), dis_o[1].assign(n + 1, INF); dis_o[0][1] = 0;
    vector<int> pre[2]; pre[0].assign(n + 1, INF); pre[1].assign(n + 1, INF); 
    while (!q.empty()) q.pop(); q.push({0, 1});
    while (!q.empty()) {
        auto [op, u] = q.front(); q.pop();
        for (auto v : g[u]) {
            if (dis_o[op ^ 1][v] > dis_o[op][u] + 1) {
                int tmp = dis_o[op][u] + 1;
                if (tmp >= dis[op ^ 1][v]) continue;
                dis_o[op ^ 1][v] = dis_o[op][u] + 1;
                pre[op ^ 1][v] = u;
                q.push({op ^ 1, v});
            }
        }
    }

    int op;
    if (dis_o[0][n] == INF && dis_o[1][n] == INF) {cout << -1 << '\n'; return ;}
    if (dis_o[0][n] < dis_o[1][n]) op = 0;
    else op = 1;
    cout << dis_o[op][n] << '\n';
    vector<int> ans;
    for (int p = n; ;) {
        ans.push_back(p);
        if (p == 1 && op == 0) break;
        p = pre[op][p];
        op ^= 1;
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
        if (i == ans.size() - 1) cout << '\n';
        else cout << ' ';
    }
}

int main() {
    freopen ("E.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}