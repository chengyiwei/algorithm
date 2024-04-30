#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
void solve() {
    int n, m; cin >> n >> m;
    int cnt = n;
    map<int,int> mp;
    vector<vector<pair<int,int>>> g(n + m + 1);
    for (int i = 1; i <= m; i++){
        int u,v,w; cin >> u >> v >> w;
        if (mp.count(w) == 0) mp[w] = ++cnt;
        g[u].push_back({mp[w],1});
        g[v].push_back({mp[w],1});
        g[mp[w]].push_back({u,0});
        g[mp[w]].push_back({v,0});
    }
    int s, t; cin >> s >> t;
    vector<long long> dis(n + m + 1,INF);
    deque<int> q;
    dis[s] = 0; q.push_front(s);
    while (q.size()) {
        int u = q.front(); q.pop_front();
        for (auto &[v,w] : g[u]) {
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                if (w == 1) q.push_back(v);
                else q.push_front(v);
            }
        }
    }
    cout << dis[t] << '\n';
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}