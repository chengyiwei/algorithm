#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;

    Edge (int u = 0, int v = 0, int w = 0) : u(u), v(v), w(w) {}
    bool operator < (const Edge &rhs) const {
        return w < rhs.w || (w == rhs.w && (u < rhs.u || (u == rhs.u && v < rhs.v)));
    }
};

void solve() {
    int n, m1, m2; cin >> n >> m1 >> m2;
    vector<Edge> g1, g2;

    vector<int> p;
    for (int i = 0; i < m1; i++) {
        int u, v, w; cin >> u >> v >> w;
        g1.emplace_back(u, v, w);
        p.push_back(w);
    }
    for (int i = 0; i < m2; i++) {
        int u, v, w; cin >> u >> v >> w;
        g2.emplace_back(u, v, w);
        p.push_back(w);
    }

    sort(g1.begin(), g1.end()); sort(g2.begin(), g2.end());
    sort(p.begin(), p.end()); p.erase(unique(p.begin(), p.end()), p.end());

    vector<int> hsh1(n + 1), hsh2(n + 1);
    for (int i = 1; i <= n; i++) hsh1[i] = rand() * rand(), hsh2[i] = rand() * rand();
    int res1_1 = 0, res2_1 = 0, res1_2 = 0, res2_2 = 0;
    for (int i = 1; i <= n; i++) {
        res1_1 ^= hsh1[i];
        res2_1 ^= hsh1[i];
        res1_2 ^= hsh2[i];
        res2_2 ^= hsh2[i];
    }

    vector<int> fa1(n + 1), fa2(n + 1);
    iota(fa1.begin(), fa1.end(), 0); iota(fa2.begin(), fa2.end(), 0);

    function<int(int, vector<int>&)> find = [&](int x, vector<int> &fa) {
        return fa[x] == x ? x : fa[x] = find(fa[x], fa);
    };

    int p1 = 0, p2 = 0;
    for (int i = 0; i < p.size(); i++) {
        vector<int> update1, update2;
        while (p1 < m1 && g1[p1].w <= p[i]) {
            int u = find(g1[p1].u, fa1), v = find(g1[p1].v, fa1);
            if (u > v) swap(u, v);
            if (u != v) {
                update1.push_back(v);
                // cout << ":1: " << v << ' ' << hsh[v] << '\n';
                fa1[v] = u;
            }
            p1++;
        }
        while (p2 < m2 && g2[p2].w <= p[i]) {
            int u = find(g2[p2].u, fa2), v = find(g2[p2].v, fa2);
            if (u > v) swap(u, v);
            if (u != v) {
                // cout << ":2: " << v << ' ' << hsh[v] << '\n';
                update2.push_back(v);
                fa2[v] = u;
            }
            p2++;
        }

        for (int v : update1) {
            res1_1 ^= hsh1[v]  * (hsh1[find(v, fa1)]);
            res1_2 ^= hsh2[v]  * (hsh2[find(v, fa1)]);
        }

        for (int v : update2) {
            res2_1 ^= hsh1[v]  * (hsh1[find(v, fa2)]);
            res2_2 ^= hsh2[v]  * (hsh2[find(v, fa2)]);
        }

        if (res1_1 != res2_1 || res1_2 != res2_2) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while (T--) solve();
    return 0;
}

/*
1
3 3 3
1 2 1
1 3 1
2 3 2
1 2 1
1 3 2
2 3 1
*/