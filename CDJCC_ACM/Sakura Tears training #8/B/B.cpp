#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Edge {
    int u, v; ll w;
    bool operator < (const Edge &rhs) const {
        return w < rhs.w;
    }
};

int main() {
    freopen ("B.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<pair<int, int>> a(n + 1);
    vector<ll> c(n + 1), k(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= n; i++) cin >> k[i];

    vector<Edge> edges;
    for (int i = 1; i <= n; i++) edges.push_back({0, i, c[i]});
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++) {
            ll w = (k[i] + k[j]) * (abs(a[i].first - a[j].first) + abs(a[i].second - a[j].second));
            edges.push_back({i, j, w});
        }
    
    sort(edges.begin(), edges.end());
    vector<int> p(n + 1);
    iota(p.begin(), p.end(), 0);
    
    function<int(int)> find = [&] (int x) {
        return x == p[x] ? x : p[x] = find(p[x]);
    };

    ll sum = 0;
    vector<int> stations;
    vector<pair<int, int>> roads;
    for (auto [u, v, w] : edges) {
        int pu = find(u), pv = find(v);
        if (pu != pv) {
            p[pu] = pv;
            sum += w;
            if (u == 0) stations.push_back(v);
            else roads.push_back({u, v});
        }
    }

    cout << sum << "\n";
    cout << stations.size() << "\n";
    for (int x : stations) cout << x << " "; cout << "\n";
    cout << roads.size() << "\n";
    for (auto [u, v] : roads) cout << u << " " << v << "\n";
    return 0;
}