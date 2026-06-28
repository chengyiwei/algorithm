#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
struct Edge {
    int u, v, w;
    Edge(int u, int v, int w) : u(u), v(v), w(w) {}
    bool operator < (const Edge &e) const {
        return w < e.w;
    }
};

int main() {
    freopen ("B.in", "r", stdin);
    ios::sync_with_stdio(false);
    int n, m, q; cin >> n >> m >> q;
    vector<int> vis(n + 1, 0);
    vector<Edge> edges;
    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        edges.emplace_back(u, v, w);
    }
    sort(edges.begin(), edges.end());
    map<pii, vector<int>> p;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].u, v = edges[i].v;
        p[{u, v}].push_back(i); p[{v, u}].push_back(i);
    }

    vector<int> a, fa;
    fa.resize(n + 1); iota(fa.begin(), fa.end(), 0);
    function<int(int)> find = [&](int x) {
        return x == fa[x] ? x : fa[x] = find(fa[x]);
    };
    
    int sq = sqrt(n);
    while (q--) {
        int k; cin >> k; ll ans = 0; int cnt = 0; a.resize(k + 1);
        for (int i = 1; i <= k; i++) cin >> a[i];

        if (k >= sq) {
            for (int i = 1; i <= k; i++)  vis[a[i]] = 1;
            for (int i = 0; i < edges.size(); i++) {
                int u = edges[i].u, v = edges[i].v;
                if (!vis[u] || !vis[v]) continue;
                int fu = find(u), fv = find(v);
                if (fu != fv) {
                    fa[fu] = fv; ans += edges[i].w; cnt++;
                }
                if (cnt == k - 1) break;
            }
            for (int i = 1; i <= k; i++) vis[a[i]] = 0, fa[a[i]] = a[i];
        }
        else {
            vector<int> e;
            for (int i = 1; i <= k; i++)
                for (int j = i + 1; j <= k; j++) {
                    int u = a[i], v = a[j];
                    for (auto x : p[{u, v}]) e.push_back(x);
                }
            
            sort(e.begin(), e.end());
            e.erase(unique(e.begin(), e.end()), e.end());
            for (auto i : e) {
                int u = edges[i].u, v = edges[i].v;
                int fu = find(u), fv = find(v);
                if (fu != fv) {
                    fa[fu] = fv; ans += edges[i].w; cnt += 1;
                }
                if (cnt == k - 1) break;
            }
            for (int i = 1; i <= k; i++) fa[a[i]] = a[i];
        }
        if (cnt == k - 1) cout << ans << '\n';
        else cout << -1 << '\n';
    }
    return 0;
}