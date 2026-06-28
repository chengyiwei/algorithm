#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll inf = 1e12;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 2; i <= n; i++) {
        int f; cin >> f;
        g[f].push_back(i);
    }
    ll L = 0, R = inf;

    auto dfs = [&] (auto &&dfs, int u, int fa, ll pre, ll mid) -> bool {
        // if (u == 1 && a[u] >= mid) return 1;
        // if (u != 1 && a[u] - pre >= 0) return 1;
        if (g[u].size() == 0) {
            if (u == 1) return a[u] >= mid;
            return a[u] - pre >= 0;
        }
        ll d = max((u == 1 ? mid - a[u] : pre - a[u]), 0ll);
        int res = 1;
        for (auto v : g[u]) {
            if (v == fa) continue;
            if (pre + d > inf) return 0;
            res &= dfs(dfs, v, u, pre + d, mid);
        }
        return res;
    };

    while (L + 1 < R) {
        ll mid = (L + R) >> 1;
        if (dfs(dfs, 1, 0, 0, mid)) L = mid;
        else R = mid;
    }
    cout << L << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}