#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll inf = 1e18;
int main() {
    int N, M, S, T, C; cin >> N >> M >> S >> T >> C;
    vector<ll> V(N + 1, 0);
    for (int i = 1; i <= N; i++) cin >> V[i];
    vector<vector<pii> > g(N + 1, vector<pii>());
    for (int i = 1; i <= M; i++) {
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    
    auto check = [&] (int W) {
        vector<ll> dis(N + 1, inf);
        priority_queue<pii, vector<pii>, greater<pii> > pq;
        pq.push({V[S], S}); dis[S] = V[S];
        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d != dis[u]) continue;
            for (auto [v, w] : g[u]) {
                if (w > W) continue;
                if (dis[v] > d + V[v]) {
                    dis[v] = d + V[v];
                    pq.push({dis[v], v});
                }
            }
        }
        return dis[T] <= C;
    };
    
    int l = -1, r = 1e9;
    while (l + 1 < r) {
        int mid = l + r >> 1;
        if (check (mid)) r = mid;
        else l = mid;
    }
    cout << r << endl;
    return 0;
}