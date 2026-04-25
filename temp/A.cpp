#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e18;

struct Edge {
    int u, v, p;
    ll d;
    bool operator<(const Edge& e) const {return p > e.p;}
};

struct Query {
    int t, u, v, id;
    ll ans;
    bool operator<(const Query& e) const {return t > e.t;}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m; cin >> n >> m;
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].p >> edges[i].d;
    }
    sort(edges.begin(), edges.end());
    int q; cin >> q;
    vector<Query> ask(q);
    for (int i = 0; i < q; i++) {
        cin >> ask[i].t >> ask[i].u >> ask[i].v;
        ask[i].id = i;
    }
    sort(ask.begin(), ask.end());

    vector<vector<ll>> dis(n + 1, vector<ll>(n + 1, INF));
    for (int i = 1; i <= n; i++) dis[i][i] = 0;

    auto in = [&] (Edge &e) { // 加入一条边
        vector<ll> dis_i_eu(n + 1, INF), dis_ev_i(n + 1, INF);
        for (int i = 1; i <= n; i++) {
            dis_i_eu[i] = dis[i][e.u];
            dis_ev_i[i] = dis[e.v][i];
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dis[i][j] = min(dis[i][j], dis_i_eu[i] + e.d + dis_ev_i[i]);
            }
        }
        vector<ll> dis_eu_i(n + 1, INF), dis_i_ev(n + 1, INF);
        for (int i = 1; i <= n; i++) {
            dis_eu_i[i] = dis[e.u][i];
            dis_i_ev[i] = dis[i][e.v];
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dis[i][j] = min(dis[i][j], dis_i_ev[i] + e.d + dis_eu_i[j]);
            }
        }
    };

    int idx = 0;
    for (int i = 0; i < q; i++) {
        while (idx < m && edges[idx].p >= ask[i].t) {
            in(edges[idx]);
            idx++;
        }
        ask[i].ans = dis[ask[i].u][ask[i].v];
    }
    sort(ask.begin(), ask.end(), [] (const Query &a, const Query &b) {return a.id < b.id;});
    for (int i = 0; i < q; i++) {
        if (ask[i].ans == INF) cout << "JIMI" << "\n";
        else cout << ask[i].ans << "\n";
    }
    return 0;
}