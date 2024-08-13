#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> dep(n + 1, 0), rt(n + 1, 0);
    vector<vector<int>> g(n + 1);

    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v); g[v].push_back(u);
    }

    vector<int> root;

    function<void(int, int, int, int)> dfs = [&](int u, int fa, int d, int r) {
        dep[u] = d; rt[u] = r;
        for (auto v : g[u]) {
            if (v == fa) continue;
            dfs(v, u, d + 1, r);
        }
    };

    for (int i = 1; i <= n; i++) {
        if (dep[i] != 0) continue;
        root.push_back(i);
        dfs(i, 0, 1, i);
    }

    int max_dep = *max_element(dep.begin() + 1, dep.end()); // max_dep 表示最深的深度
    
    if (max_dep == 1) {
        for (int i = 1; i <= n; i++) cout << i << ' ';
        cout << '\n';
        return ;
    }
    if (root.size() > 1) {
        int x, y;
        for (int i = 1; i <= n; i++) if (dep[i] == 2) x = i;
        for (int i = 1; i <= n; i++) if (dep[i] == 1 && rt[i] != rt[x]) y = i;
        for (int i = 1; i <= n; i++) if ((dep[i] & 1) && i != y) cout << i << ' ';
        cout << y << ' ' << x << ' ';
        for (int i = 1; i <= n; i++) if (!(dep[i] & 1) && i != x) cout << i << ' ';
        cout << '\n';
    }
    else  {
        if (max_dep == 2) {
            cout << "-1" << '\n';
        }
        else if (max_dep == 3) {
            int x, y;
            vector<int> v;
            for (int i = 1; i <= n; i++) if (dep[i] == 2) v.push_back(i);
            if (v.size() == 1) {
                cout << "-1" << '\n';
            }else {
                int x, y;
                for (int i = 1; i <= n; i++) if (dep[i] == 3) y = i;
                for (auto u : v) {
                    bool flg = 1;
                    for (auto v : g[u]) {
                        if (v == y) {flg = 0; break;}
                    }
                    if (flg) {x = u; break;}
                }
                for (int i = 1; i <= n; i++) if ((dep[i] & 1) && i != y) cout << i << ' ';
                cout << y << ' ' << x << ' ';
                for (int i = 1; i <= n; i++) if ((dep[i] & 1) == 0 && i != x) cout << i << ' ';
                cout << '\n';
            }
        }
        else {
            int x, y;
            for (int i = 1; i <= n; i++) {
                if (dep[i] == 1) y = i;
                if (dep[i] == 4) x = i; 
            }
            for (int i = 1; i <= n; i++) if ((dep[i] & 1) && i != y) cout << i << ' ';
            cout << y << ' ' << x << ' ';
            for (int i = 1; i <= n; i++) if ((dep[i] & 1) == 0 && i != x) cout << i << ' ';
            cout << '\n';
        }
    }
} 

int main() {
    freopen ("F.in", "r", stdin);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}