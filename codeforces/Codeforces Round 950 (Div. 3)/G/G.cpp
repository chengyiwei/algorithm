#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

struct Node {
    int cnt;
    int nxt[2];
    Node() {
        cnt = 0;
        memset(nxt, 0, sizeof(nxt));
    }
};

struct Tire {
    int n;
    vector<Node> a;
    Tire() {
        n = 0;
        a.push_back(Node());
    }

    void insert (int x) {
        int p = 0;
        for (int i = 30; i >= 0; i--) {
            int u = (x >> i) & 1;
            if (!a[p].nxt[u]) {
                a[p].nxt[u] = ++n;
                a.push_back(Node());
            }
            p = a[p].nxt[u];
            a[p].cnt++;
        }
    }

    void del (int x) {
        int p = 0;
        for (int i = 30; i >= 0; i--) {
            int u = (x >> i) & 1;
            p = a[p].nxt[u];
            a[p].cnt--;
        }
    }

    int query (int x) { // 求异或 x 的最大值
        int ret = 0, p = 0;
        for (int i = 30; i >= 0; i--) {
            int u = (x >> i) & 1;
            if (a[a[p].nxt[u ^ 1]].cnt)
                ret |= 1 << i, p = a[p].nxt[u ^ 1];
            else if (a[a[p].nxt[u]].cnt)
                p = a[p].nxt[u];
            else
                break;
        }
        return ret;
    }
}T[2];


void solve() {
    int n, q; cin >> n >> q;
    T[0] = Tire(); T[1] = Tire();
    vector<vector<pii>> g(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    vector<int> pre(n + 1, 0), dep(n + 1, 0);
    auto dfs = [&] (auto &&dfs, int u, int fa) ->void {
        T[dep[u]].insert(pre[u]);
        for (auto [v, w] : g[u]) if (v != fa) {
            pre[v] = pre[u] ^ w;
            dep[v] = dep[u] ^ 1;
            dfs(dfs, v, u);
        }
    };

    dfs(dfs, 1, 1);

    int last = 0;
    while (q--) {
        char opt; cin >> opt;
        if (opt == '^') {
            int x; cin >> x;
            last ^= x;
        }
        else {
            int v, x; cin >> v >> x;
            int ans = pre[v] ^ x ^ (dep[v] * last);
            T[dep[v]].del(pre[v]);
            ans = max(T[0].query(ans), T[1].query(ans ^ last));
            T[dep[v]].insert(pre[v]);
            cout << ans << " ";
        }
    }
    cout << endl;
}

int main() {
    freopen ("G.in", "r", stdin);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}