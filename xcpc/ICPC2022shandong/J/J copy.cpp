#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxm = 5e5 + 10, maxn = 1e5 + 10;

int col[60][maxn];

int read() {
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
    return x * f;
}

signed main() {
    freopen ("J.in", "r", stdin);
    freopen ("J0.out", "w", stdout);
    int n = read(), m = read(), q = read(), V = read();
    vector<vector<pair<int,int> > > g(n + 1, vector<pair<int,int> > ());
    for (int i = 0; i < m; i++) {
        int u = read(), v = read(), w = read();
        g[u].push_back({v, w}); g[v].push_back({u, w});
    }
    for (int i = 0; i < 60; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (col[i][j]) continue;
            ++cnt;
            queue<int> que; que.push(j);
            col[i][j] = cnt;
            while (!que.empty()) {
                int now = que.front(); que.pop();
                for (auto [v, w] : g[now]) {
                    if (col[i][v] || !(w >> i & 1)) continue;
                    col[i][v] = cnt;
                    que.push(v);
                }
            }
        }
    }
    while (q--) {
        int u, v;
        cin >> u >> v;
        int now_V = 0;
        for (int i = 0; i < 60; i++) {
            if (col[i][u] == col[i][v]) 
                now_V += (1ll << i);
        }
        if (now_V >= V) puts("Yes");
        else puts("No");
    }
    cout << clock() << endl;
    return 0;
}