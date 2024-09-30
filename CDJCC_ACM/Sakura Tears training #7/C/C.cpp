#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    int a, b, d_a, d_b; cin >> a >> b >> d_a >> d_b;
    
    vector<vector<int>> g(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> d(n + 1, 0);

    auto dfs = [&] (auto &&dfs, int u, int fa) -> void{
        for (auto &v : g[u]) {
            if (v == fa) continue;
            d[v] = d[u] + 1;
            dfs(dfs, v, u);
        }
    };

    dfs(dfs, a, 0);
    int d_ab = d[b];
    int X = max_element(d.begin() + 1, d.end()) - d.begin();
    d[X] = 0;
    dfs(dfs, X, 0);
    auto dis = *max_element(d.begin() + 1, d.end());
    if (d_ab <= d_a || 2 * d_a >= dis || 2 * d_a >= d_b)
        cout << "Alice" << '\n';
    else
        cout << "Bob" << '\n';
}

int main() {
    freopen ("C.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
