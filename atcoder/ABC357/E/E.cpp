#include <bits/stdc++.h>
#define int long long 
using namespace std;

signed main() {
    freopen ("E.in", "r", stdin);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> fa(n + 1);
    
    vector<int> vis(n + 1, 0), du(n + 1, 0);
    vector<int> in_scc(n + 1, 0);
    int cnt_scc = 0;
    for (int i = 1; i <= n; i++)
        cin >> fa[i];
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        int u = i;
        while (true) {
            if (in_scc[u]) break;
            if (vis[u] == i) {
                cnt_scc += 1;
                int j = u;
                while (true) {
                    in_scc[j] = cnt_scc;
                    j = fa[j];
                    if (j == u) break;
                }
            }
            vis[u] = i;
            u = fa[u];
        }
    }

    vector<int> siz(cnt_scc + 1, 0);
    for (int i = 1; i <= n; i++) 
        if (in_scc[i])
            siz[in_scc[i]] += 1;

    function<int(int)> dfs = [&](int u) {
        if (in_scc[u]) return siz[in_scc[u]];
        return 1 + dfs(fa[u]);
    };

    int ans = 0;
    for (int i = 1; i <= n; i++) ans = ans + dfs(i);
    cout << ans << endl;
    return 0;
}