#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;

const int N = 5e5 + 7;
const ll INFLL = 1e18;
int n, m, k;
ll dis[N];
priority_queue<pli, vector<pli>, greater<pli>> q[N];

struct To{
    int to, c;
    ll w;
};

vector<To> e[N];

void solve() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        dis[i] = INFLL;
        e[i].clear();
    }
    for (int i = 1; i <= m; i++)
        while (!q[i].empty()) q[i].pop();
    
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        ll len;
        cin >> a >> b >> c >> len;
        e[a].push_back({b, c, len});
        e[b].push_back({a, c, len});
    }

    for (auto [to, c, w]: e[1])
        q[c].push({w, to});
    
    dis[1] = 0;
    for (int i = 1; i <= k; i++) {
        int a; ll b;
        cin >> a >> b;
        set<int> vis;
        priority_queue<pli, vector<pli>, greater<pli>> p;
        while (!q[a].empty() && q[a].top().first <= b) {
            auto [len, to] = q[a].top();
            q[a].pop();
            if (dis[to] == INFLL) {
                vis.insert(to);
                dis[to] = len;
                p.emplace(len, to);
            }
        }
        while (!p.empty()) {
            auto [d, now] = p.top();
            p.pop();
            if (d > dis[now]) continue;
            for (auto [to, c, w] : e[now]) {
                if (c == a && d + w <= dis[to] && d + w <= b) {
                    dis[to] = d + w;
                    vis.insert(to);
                    p.emplace(dis[to], to);
                }
            }
        }

        for (auto now : vis) {
            dis[now] = 0;
            for (auto [to, c, w] : e[now]) {
                q[c].emplace(w, to);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (dis[i] == 0) cout << "1";
        else cout << "0";
    }
    cout << endl;
}

signed main() {
    freopen ("J.in", "r", stdin);
    freopen ("J0.out", "w", stdout);
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}