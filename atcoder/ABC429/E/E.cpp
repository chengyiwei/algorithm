#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Item {
    int v;
    int d;
    int src;
    Item() {}
    Item(int _v, int _d, int _src) : v(_v), d(_d), src(_src) {}
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    string s; cin >> s;
    s = "#" + s; 

    const int INF = (int)2e18;

    vector<int> d1(n + 1, INF), d2(n + 1, INF);
    vector<int> s1(n + 1, -1), s2(n + 1, -1);

    queue<Item> q;

    for (int i = 1; i <= n; i++) {
        if (s[i] == 'S') {
            d1[i] = 0;
            s1[i] = i;
            q.push(Item(i, 0, i));
        }
    }

    while (!q.empty()) {
        Item cur = q.front(); q.pop();
        int u = cur.v;
        int du = cur.d;
        int src = cur.src;

        for (int to_idx = 0; to_idx < (int)g[u].size(); to_idx++) {
            int v = g[u][to_idx];
            int cand = du + 1;
            if (cand < d1[v]) {
                d2[v] = d1[v];
                s2[v] = s1[v];
                d1[v] = cand;
                s1[v] = src;
                q.push(Item(v, cand, src));
            } else if (src != s1[v]) {
                if (cand < d2[v]) {
                    d2[v] = cand;
                    s2[v] = src;
                    q.push(Item(v, cand, src));
                } else if (cand == d2[v]) {
                }
            } else {
            }
            if (cand == d1[v] && src != s1[v]) {
                if (cand < d2[v]) {
                    d2[v] = cand;
                    s2[v] = src;
                    q.push(Item(v, cand, src));
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (s[i] == 'D') {
            if (d1[i] < INF && d2[i] < INF && s1[i] != -1 && s2[i] != -1 && s1[i] != s2[i]) {
                cout << (d1[i] + d2[i]) << "\n";
            } else {
                cout << -1 << "\n";
            }
        }
    }

    return 0;
}