#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 5;
int n, m, rt;
vector<int> g[maxn];
int f[maxn][25], dep[maxn];

void dfs(int u, int fa) {
    f[u][0] = fa;
    dep[u] = dep[fa] + 1;
    for (int i = 1; i <= 20; i++)
        f[u][i] = f[f[u][i - 1]][i - 1];
    for (auto v : g[u]) {
        if (v == fa) continue;
        dfs(v, u);
    }
}

int lca(int x, int y) {
    if (dep[x] < dep[y]) swap(x, y);
    for (int i = 20; i >= 0; i--)
        if (dep[f[x][i]] >= dep[y])
            x = f[x][i];
    if (x == y) return x;
    for (int i = 20; i >= 0; i--)
        if (f[x][i] != f[y][i])
            x = f[x][i], y = f[y][i];
    return f[x][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> rt;
    for (int i = 1; i < n; i++) {
        int x, y; cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(rt, 0);
    while (m--) {
        int x, y; cin >> x >> y;
        cout << lca(x, y) << endl;
    }
    return 0;
}