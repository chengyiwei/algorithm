#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen ("out.out", "w", stdout);

    ios::sync_with_stdio(false);
    int N, Q; cin >> N >> Q;
    vector<vector<int>> g(N + 1);
    
    for (int i = 1; i < N; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v); g[v].push_back(u);
    }

    vector<int> b(N + 1, 0);
    vector<int> s_b(N + 1, 0);
    vector<int> dep(N + 1, 0);
    vector<vector<int>> F(N + 1, vector<int>(21, 0));

    function<void(int , int)> dfs1 = [&] (int u, int f) {
        dep[u] = dep[f] + 1; F[u][0] = f;
        for (int v : g[u]) {
            b[u] ^= v;
            if (v == f) continue;
            dfs1(v, u);
        }
    };
    dfs1(1, 0);

    function<void(int, int)> dfs2 = [&] (int u, int f) {
        s_b[u] = b[u] ^ s_b[f];
        for (int v : g[u]) {
            if (v == f) continue;
            dfs2(v, u);
        }
    };
    dfs2(1, 0);

    for (int i = 1; i <= 20; i++)
        for (int j = 1; j <= N; j++)
            F[j][i] = F[F[j][i - 1]][i - 1];


    function<int(int, int)> lca = [&](int u, int v) {
        if (dep[u] < dep[v]) swap(u, v);
        for (int i = 20; i >= 0; i--) {
            if (dep[F[u][i]] >= dep[v]) u = F[u][i];
        }
        if (u == v) return u;
        for (int i = 20; i >= 0; i--) {
            if (F[u][i] != F[v][i]) {
                u = F[u][i];
                v = F[v][i];
            }
        }
        return F[u][0];
    };


    while (Q--) {
        int u, v; cin >> u >> v;
        int l = lca(u, v);
        // cout << l << " ";
        int ans = s_b[u] ^ s_b[v] ^ b[l] ^ u ^ v;
        cout << ans << '\n';
    }

    return 0;
}