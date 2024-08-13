#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

struct Node {
    int maxx_1, maxx_2;
    int maxi_1, maxi_2;
    Node () {
        maxx_1 = maxx_2 = -1;
        maxi_1 = maxi_2 = 0;
    }
};

struct Segment_Tree {
    int n;
    vector<Node> t;
    Segment_Tree (int n) : n(n), t(n << 2) {}

    Node merge (Node A, Node B) {
        vector<pii> v;
        v.push_back({A.maxx_1, A.maxi_1});
        v.push_back({A.maxx_2, A.maxi_2});
        v.push_back({B.maxx_1, B.maxi_1});
        v.push_back({B.maxx_2, B.maxi_2});
        sort(v.begin(), v.end(), greater<pair<int, int>>());
        vector<pii> v2;
        for (int i = 0; i < v.size(); i++)
            if (i == 0 || v[i].second != v[i - 1].second) v2.push_back({v[i].first, 0});
        Node res;
        if (v2.size() >= 1) res.maxx_1 = v2[0].first, res.maxi_1 = v2[0].second;
        if (v2.size() >= 2) res.maxx_2 = v2[1].first, res.maxi_2 = v2[1].second;
        return res;
    }

    void build (int x, int l, int r, vector<int> &a, vector<int>& nxt) {
        if (l == r) {
            t[x].maxi_1 = a[l];
            t[x].maxx_1 = nxt[l];
            return ;
        }
        int mid = (l + r) >> 1;
        build(x << 1, l, mid, a, nxt); build(x << 1 | 1, mid + 1, r, a, nxt);
        t[x] = merge(t[x << 1], t[x << 1 | 1]);
    }

    Node query (int x, int l, int r, int L, int R, int id) {
        if (L <= l && r <= R) {
            return t[x];
        }
        int mid = (l + r) >> 1;
        if (R <= mid) return query(x << 1, l, mid, L, R, id);
        if (L > mid) return query(x << 1 | 1, mid + 1, r, L, R, id);
        Node A = query(x << 1, l, mid, L, R, id), B = query(x << 1 | 1, mid + 1, r, L, R, id);
        return merge(A, B);
    }

    int ask (int L, int R, int id) {
        Node res = query(1, 1, n, L, R, id);
        if (res.maxi_1 == id) return res.maxx_2;
        return res.maxx_1;
    }
};

void solve() {
    int N, K; cin >> N >> K;
    vector<int> a(N + 1), nxt(N + 1);
    for (int i = 1; i <= N; i++) cin >> a[i]; auto b = a;
    sort(b.begin() + 1, b.end()); b.erase(unique(b.begin() + 1, b.end()), b.end()); int M = b.size();
    for (int i = 1; i <= N; i++) a[i] = lower_bound(b.begin() + 1, b.end(), a[i]) - b.begin();

    vector<vector<int>> g(M + 1);
    for (int i = 1; i <= N; i++) {
        g[a[i]].push_back(i);
    }
    for (int i = 1; i <= M; i++) {
        for (int j = 0; j < g[i].size(); j++) {
            if (j + K - 1 >= g[i].size()) nxt[g[i][j]] = INF;
            else nxt[g[i][j]] = g[i][j + K - 1];
        }
    }

    for (int i = 1; i <= N; i++) cout << nxt[i] << " \n"[i == N];

    Segment_Tree T(N);
    T.build(1, 1, N, a, nxt);

    vector<int> f(N + 1, INF);
    for (int i = 1; i <= N; i++) {
        if (nxt[i] == INF) continue;
        f[i] = T.ask(i, nxt[i], a[i]);
    }

    for (int i = 1; i <= N; i++)
        cout << f[i] << " \n"[i == N];
}

int main() {
    freopen ("D.in", "r", stdin);
    ios::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}