#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr ll INF = 0x3f3f3f3f3f3f3f3f;

struct Edge {
    int u, v;
    ll t, w;
};

struct Line {
    ll k, b;
    Line(ll k = 0, ll b = INF) : k(k), b(b) {}
    ll y(ll x) { return k * x + b; }
};

struct SegmentTree {
    int n;
    vector<Line> t;
    SegmentTree(int n = 0) : n(n) {t.assign(n << 2, Line());}
    
    void update(Line k, int u, int l, int r) {
        int mid = (l + r) >> 1;
        
    }
};

void solve() {
    int n, m; cin >> n >> m;
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].t >> edges[i].w;
    }


    auto dij = [&] (int s, vector<ll>& dis) {
        priority_queue <pair<ll, int> , greater<pair<ll, int>>> pq;
        fill(dis.begin(), dis.end(), INF);
        vector<int> vis(n + 1, 0);
        vis[s] = 1; dis[s] = 0; pq.push(pair<ll, int>({0, s}));
        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (vis[u] == 1) continue;
            vis[u] = 1;
            for (auto& e : edges) {
                if (dis[e.v] > dis[e.u] + e.w) {
                    dis[e.v] = dis[e.u] + e.w;
                    pq.push(pair<ll, int>({dis[e.v], e.v}));
                }
            }
        }
        return ;
    };

    vector<ll> dis1(n + 1), disn(n + 1);
    dij(1, dis1), dij(n, disn);


}

int main() {
    int t; cin >> t;
    while (t--) solve();
    return 0;
}