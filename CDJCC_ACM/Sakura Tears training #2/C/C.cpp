#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q; cin >> n >> q;
    vector<int> fa(n + 1), id(n + 1), a(n + 1);
    vector<vector<int>> g(n + 1);
    for (int i = 2; i <= n; i++) cin >> fa[i], g[fa[i]].push_back(i); fa[1] = 0;
    for (int i = 1; i <= n; i++) cin >> a[i], id[a[i]] = i;

    vector<set<int>> p(n + 1, set<int>());
    set<int> unable;

    auto check = [&](int u) -> bool {
        int siz = p[u].size();
        int max_ = *p[u].rbegin(), min_ = *p[u].begin();
        bool chk = max_ - min_ + 1 == siz && *p[u].begin() == id[u];
        if (chk) {
            if (unable.count(u)) unable.erase(u);
            return 1;
        }
        else {
            if (!unable.count(u)) unable.insert(u);
            return 0;
        }
    };

    auto dfs = [&](auto &&dfs, int u) -> void {
        p[u].insert(id[u]);
        for (auto v : g[u]) {
            dfs(dfs, v);
            p[u].insert(p[v].begin(), p[v].end());
        }
        check(u);
    };

    dfs(dfs, 1);

    while (q--) {
        int x, y; cin >> x >> y;
        for (int tmp = a[x]; tmp; tmp = fa[tmp]) p[tmp].erase(x);
        for (int tmp = a[y]; tmp; tmp = fa[tmp]) p[tmp].erase(y);

        swap(a[x], a[y]);
        id[a[x]] = x, id[a[y]] = y;

        for (int tmp = a[x]; tmp; tmp = fa[tmp]) p[tmp].insert(x), check(tmp);
        for (int tmp = a[y]; tmp; tmp = fa[tmp]) p[tmp].insert(y), check(tmp);

        if (unable.empty()) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main() {
    freopen ("C.in", "r", stdin);
    freopen ("C.out","w", stdout);
    ios::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}