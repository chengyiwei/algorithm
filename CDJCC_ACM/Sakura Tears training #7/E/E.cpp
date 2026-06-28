#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> g;
vector<int> in, out, dep, id;
int cnt;

void dfs(int u, int f) {
    dep[u] = dep[f] + 1;
    in[u] = ++cnt;
    for(auto v : g[u]) {
        if (v == f) continue;
        dfs(v, u);
    }
    out[u] = cnt;
}

bool inter(int u, int v) {
    if (in[u] <= in[v] && in[v] <= out[u]) return 1;
    if (in[v] <= in[u] && in[u] <= out[v]) return 1;
    return 0;
}

bool cmp(int a, int b) {
    return dep[a] < dep[b];
}

void solve() {
    cin >> n;
    g.assign(n + 1, vector<int>());
    in.assign(n + 1, 0); out.assign(n + 1, 0); cnt = 0; dep.assign(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        int x; cin >> x;
        g[x].push_back(i);
    }
    dfs(1, 0);
    id.assign(n + 1, 0);
    iota(id.begin(), id.end(), 0);
    sort(id.begin() + 1, id.end(), cmp);
    reverse(id.begin() + 1, id.end());
    int ans = 0;
    queue<int> q;
    for (int _  = 1; _ <= n; _++) {
        int u = id[_];
        if (q.empty()) q.push(u);
        else {
            int v = q.front();
            if (inter(u, v)) q.push(v);
            else {
                q.pop(); ans += 1;
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    freopen ("E.in", "r", stdin);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}