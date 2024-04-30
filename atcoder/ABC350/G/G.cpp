#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll TT = 998244353;

vector<int> fa, siz;

int find (int x) {
    if (fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

vector<int> real_fa;

int main() {
    freopen ("G.in", "r", stdin);
    int n, m; cin >> n >> m;
    fa.resize(n + 1); siz.resize(n + 1); real_fa.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
        siz[i] = 1;
        real_fa[i] = 0;
    };


    int lst = 0;
    while (m--) {
        ll a, b, c; cin >> a >> b >> c;
        ll A = 1 + (((a * (1ll + lst)) % TT) % 2);
        ll B = 1 + (((b * (1ll + lst)) % TT) % n);
        ll C = 1 + (((c * (1ll + lst)) % TT) % n);
        
        int op = A, u = B, v = C;
        // int op, u, v; cin >> op >> u >> v;
        if (op == 1) {
            if (siz[find(u)] < siz[find(v)]) swap(u, v);
            siz[find(u)] += siz[find(v)]; fa[find(v)] = find(u);

            int nxt = real_fa[v]; real_fa[v] = u;
            for (int s = v, f = nxt; f;) {
                int nxt = real_fa[f];
                real_fa[f] = s;
                s = f; f = nxt;
            }
        }
        else if (op == 2) {
            if (find(u) != find(v)) {
                cout << (lst = 0) << '\n';
            }
            else {
                auto check = [&](int u, int v) {
                    if (u == real_fa[real_fa[v]]) return real_fa[v];
                    if (real_fa[u] == real_fa[v]) return real_fa[u];
                    return 0;
                };
                lst = check(u, v) | check(v, u);
                cout << lst << '\n';
            }
        }
    }
    return 0;
}