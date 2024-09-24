#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    function<void(int, int, vector<int>&)> dfs = [&](int u, int f, vector<int> &d) {
        d[u] = d[f] + 1;
        for (int v : g[u]) if (v != f) dfs(v, u, d);
    };

    vector<int> d(n + 1, 0), d1(n + 1, 0), d2(n + 1, 0);
    dfs(1, 0, d);
    int u = max_element(d.begin() + 1, d.end()) - (d.begin() + 1) + 1;
    dfs(u, 0, d1);
    int v = max_element(d1.begin() + 1, d1.end()) - (d1.begin() + 1) + 1;
    dfs(v, 0, d2);
    for (int i = 1; i <= n; i++) d[i] = max(d1[i], d2[i]);
    int mxd = d1[v];
    sort(d.begin() + 1, d.end());
    int pos = 1;
    for (int i = 1; i <= n; i++) {
        if (i >= mxd) cout << n << ' ';
        else {
            while (pos <= n && d[pos] <= i) pos += 1;
            cout << pos << ' ';
        }
    }
}

int main() {
    freopen ("A.in", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    while (T--) solve();
    return 0;
}