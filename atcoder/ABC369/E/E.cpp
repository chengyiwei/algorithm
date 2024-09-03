#include <bits/stdc++.h>
using namespace std;
const int MAXN = 405;
const int MAXM = 2e5 + 5;
#define int long long
int dis[MAXN][MAXN];
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;

struct Edge {
    int u, v, w;
}e[MAXM];

signed main() {
    int n, m; cin >> n >> m;
    memset(dis, 0x3f, sizeof(dis));
    for (int i = 1; i <= m; i++) {
        int u, v, l; cin >> u >> v >> l;
        dis[u][v] = dis[v][u] = min(dis[u][v], l);
        e[i] = {u, v, l};
    }
    for (int i = 1; i <= n; i++) dis[i][i] = 0;
    for (int k = 1; k <= n; k++) 
        for (int i = 1; i <= n; i++) 
            for (int j = 1; j <= n; j++) 
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    
    int Q; cin >> Q;
    while (Q--) {
        int k; cin >> k;
        vector<int> c(k);
        for (int i = 0; i < k; i++) cin >> c[i];
        vector<int> idx(k);
        iota(idx.begin(), idx.end(), 0);
        vector<int> p(k);
        ll ans = INF;
        do {
            for (int S = 0; S < (1 << k); S++) {
                ll now_ans = 0;
                p.clear(); p.push_back(1);
                for (int i = 0; i < k; i++) {
                    Edge &now_edge = e[c[idx[i]]];
                    now_ans += now_edge.w;
                    if (S >> i & 1) {
                        p.push_back(now_edge.u);
                        p.push_back(now_edge.v);
                    }
                    else {
                        p.push_back(now_edge.v);
                        p.push_back(now_edge.u);
                    }
                }
                p.push_back(n);
                for (int i = 0; i < p.size(); i += 2)
                    now_ans += dis[p[i]][p[i + 1]];
                ans = min(ans, now_ans);
            }
        }while (next_permutation(idx.begin(), idx.end()));
        cout << ans << '\n';
    }
    return 0;
}