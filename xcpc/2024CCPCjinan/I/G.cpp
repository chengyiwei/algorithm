#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
typedef long long ll;
ll dp[MAXN][2], val[MAXN];
vector<vector<int>> g;
int n;

void dfs1(int u, int op, int fa) {
    if (op == 0) {
        ll res = val[u];
        vector<ll> p;
        for (auto v : g[u]) {
            if (v == fa) continue;
            dfs1(v, 0, u); dfs1(v, 1, u);
            res = max(res, max(dp[u][0], dp[u][1] + val[u]));
            p.push_back(dp[u][1]);
        }
        sort(p.begin(), p.end(), greater<ll>());
        if (p.size() >= 2)
            res = max(res, p[0] + p[1] + val[u]);
        dp[u][op] = res;
    }
    else {
        ll res = val[u];
        for (auto v : g[u])
            res = max(res, dp[u][1] + val[u]);
        dp[u][op] = res;
    }
}

ll f[MAXN][2];
void dfs2(int u, int fa, pair<ll, ll> oht) {
    ll res = val[u];
    res = max(res, dp[])
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n; g.assign(n + 1, vector<int>());
    for (int i = 1; i <= n; i++) cin >> val[i];
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v); g[v].push_back(u);
    }


}