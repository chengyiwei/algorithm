#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> fa(n + 1, 0), dep(n + 1, 0), max_dep(n + 1, 0);
    iota(fa.begin(), fa.end(), 0);
    function<int(int)> find = [&](int x) {
        if (fa[x] == x) return x;
        int f = find(fa[x]);
        if (f != fa[x]) {
            dep[x] = dep[fa[x]] + dep[x];
            fa[x] = f;
        }
        max_dep[f] = max(max_dep[f], dep[x] + max_dep[x]);
        return fa[x];
    };
    for (int i = 1; i < n; i++) {
        int u, v, c; cin >> u >> v >> c;
        fa[v] = u; dep[v] = 1;
        int g = find(v);
        max_dep[g] = max(max_dep[g], dep[v]);
        find(c);
        cout << max_dep[c] << ' ';
    }
    cout << '\n';
}

int main() {
    freopen ("A.in", "r", stdin);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) solve ();
    return 0;
}