#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll inf = 1e18;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 2; i <= n; i++) {
        int f; cin >> f;
        g[f].push_back(i);
    }
    auto dfs = [&] (auto &&dfs, int u, int fa) -> ll {
        ll min_x = inf;
        if (g[u].size() == 0) return a[u];
        for (auto v : g[u]) {
            if (v == fa) continue;
            min_x = min(min_x, dfs(dfs, v, u));
        }
        if (a[u] > min_x) return min_x;
        else return (min_x + a[u]) / 2;
    };
    ll res = inf;
    for (auto v : g[1])
        res = min(res, dfs(dfs, v, 1));
    cout << a[1] + res << '\n';

}

int main() {
    freopen ("D.in", "r", stdin);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}