#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
    Edge(int u, int v, int w) : u(u), v(v), w(w) {};
    bool operator < (const Edge& e) const {
        return w < e.w;
    }
};

vector<Edge> edges;

int main() {
    freopen ("C.in", "r", stdin);
    ios::sync_with_stdio(0);
    int n, m, s, t; cin >> n >> m >> s >> t;
    vector<int> fa(n + 1);
    iota(fa.begin(), fa.end(), 0);

    function<int(int)> find = [&](int x) {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    };

    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        edges.push_back(Edge(u, v, w));
    }
    sort(edges.begin(), edges.end());
    int ret = 0;
    for (auto& e : edges) {
        int fs = find(s), ft = find(t);
        if (fs == ft) break;
        int fu = find(e.u), fv = find(e.v);
        if (fu == fv) continue;
        ret = e.w; fa[fu] = fv;
    }
    cout << ret << endl;
    return 0;
}