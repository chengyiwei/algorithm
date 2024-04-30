#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxm = 5e5 + 10, maxn = 1e5 + 10;

struct Edge {
    int u, v, w;
    Edge(int u_, int v_, int w_) : u(u_), v(v_), w(w_) {}
    Edge() {}
}edges[maxm];

struct Dsu {
    vector<int> p;
    int n;
    void init (int n_) {
        n = n_ + 1;
        p.resize(n);
        iota(p.begin(), p.end(), 0);
    }
    int find(int x) {
        return x == p[x] ? x : p[x] = find(p[x]);
    }
    void merge(int x, int y) {
        x = find(x); y = find(y);
        if (x != y) 
            p[x] = y;
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
}d[60];


int read() {
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
    return x * f;
}


signed main() {
    // freopen ("J.in", "r", stdin);
    // freopen ("J.out", "w", stdout);
    int n = read(), m = read(), q = read(), V = read();
    for (int i = 0; i < m; i++) {
        int u = read(), v = read(), w = read();
        edges[i] = Edge(u, v, w);
    }
    for (int i = 0; i < 60; i++) {
        auto &now_dsu = d[i];
        now_dsu.init(n);
        for (int j = 0; j < m; j++) {
            auto &[u, v, w] = edges[j];
            if ((w >> i) & 1)
                now_dsu.merge(u, v);
        }
    }
    while (q--) {
        int u, v;
        u = read(), v = read();
        int now_V = 0;
        for (int i = 0; i < 60; i++) {
            if (d[i].same(u, v)) {
                now_V |= (1ll << i);
            }
        }
        if (now_V >= V) printf("Yes\n");
        else printf("No\n");
    }
    // cout << clock() << endl;
    return 0;
}