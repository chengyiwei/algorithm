#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 410, maxm = 1000000;
const ll inf = 0x3f3f3f3f3f3f3f3fll;

ll tc, n, s, t, p, m, kk, cnt, head[maxn], len;
string a[maxn], b[maxn];
bool can[maxn][maxn];
map<string, ll> mp;

ll ID(string &s) {
    if (mp.count(s)) {
        return mp[s];
    } else {
        return mp[s] = ++cnt;
    }
}

struct edge {
    ll from, to, next, cap, flow;
} edges[maxm];

void add_edge(ll u, ll v, ll c, ll f) {
    edges[++len].from = u;
    edges[len].to = v;
    edges[len].next = head[u];
    edges[len].cap = c;
    edges[len].flow = f;
    head[u] = len;
}

struct Dinic {
    bool vis[maxn];
    ll d[maxn], cur[maxn];

    void add(ll u, ll v, ll c) {
        // printf("%lld %lld %lld\n",u,v,c);
        add_edge(u, v, c, 0);
        add_edge(v, u, 0, 0);
    }

    bool bfs() {
        memset(vis, 0, sizeof(vis));
        queue<ll> q;
        q.push(s);
        d[s] = 0;
        vis[s] = 1;
        while (q.size()) {
            ll u = q.front();
            q.pop();
            for (int i = head[u]; i; i = edges[i].next) {
                edge e = edges[i];
                if (!vis[e.to] && e.cap > e.flow) {
                    vis[e.to] = 1;
                    d[e.to] = d[u] + 1;
                    q.push(e.to);
                }
            }
        }
        return vis[t];
    }

    ll dfs(ll u, ll a) {
        if (u == t || !a) {
            return a;
        }
        ll flow = 0, f;
        for (ll &i = cur[u]; i; i = edges[i].next) {
            edge &e = edges[i];
            if (d[u] + 1 == d[e.to] && (f = dfs(e.to, min(a, e.cap - e.flow))) > 0) {
                e.flow += f;
                edges[i ^ 1].flow -= f;
                flow += f;
                a -= f;
                if (!a) {
                    break;
                }
            }
        }
        return flow;
    }

    ll solve() {
        ll flow = 0;
        while (bfs()) {
            for (int i = 1; i <= n; ++i) {
                cur[i] = head[i];
            }
            flow += dfs(s, inf);
        }
        return flow;
    }
} solver;

int main() {
    freopen("UVA753.in","r",stdin);
    freopen("UVA7530.out","w",stdout);
    scanf("%lld", &tc);
    while (tc--) {
        memset(can, 0, sizeof(can));
        memset(head, 0, sizeof(head));
        cnt = 0;
        len = 1;
        mp.clear();
        scanf("%lld", &p);
        for (int i = 1; i <= p; ++i) {
            string tmp;
            cin >> tmp;
            ID(tmp);
            a[i] = tmp;
        }
        scanf("%lld", &m);
        for (int i = 1; i <= m; ++i) {
            string a, tmp;
            cin >> a >> tmp;
            ID(tmp);
            b[i] = tmp;
        }
        n = cnt + 2;
        s = cnt + 1;
        t = n;
        scanf("%lld", &kk);
        while (kk--) {
            string s, t;
            cin >> s >> t;
            can[ID(s)][ID(t)] = 1;
        }
        for (int k = 1; k <= cnt; ++k) {
            for (int i = 1; i <= cnt; ++i) {
                for (int j = 1; j <= cnt; ++j) {
                    can[i][j] |= (can[i][k] & can[k][j]);
                }
            }
        }
        for (int i = 1; i <= m; ++i) {
            solver.add(s, ID(b[i]), 1);
        }
        for (int i = 1; i <= p; ++i) {
            solver.add(ID(a[i]), t, 1);
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= p; ++j) {
                int u = ID(b[i]), v = ID(a[j]);
                if (can[u][v]) {
                    solver.add(u, v, inf);
                }
            }
        }
        printf("%lld\n",m- solver.solve());
        if (tc) {
            putchar('\n');
        }
    }
    return 0;
}