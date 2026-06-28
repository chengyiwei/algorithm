#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

struct Node {
    pll sum;
    ll tag;
};

pll operator + (const pll &a, const pll &b) {
    if (a.first > b.first) return a;
    if (a.first < b.first) return b;
    return {a.first, a.second + b.second};
}
struct Segment_Tree {
    vector<Node> tr;
    int n;
    Segment_Tree(int n) : n(n), tr(n << 4) {}

    void push_up (int u) {
        tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
    }

    void push_down (int u) {
        if (tr[u].tag) {
            tr[u << 1].tag += tr[u].tag;
            tr[u << 1].sum.first += tr[u].tag;
            tr[u << 1 | 1].tag += tr[u].tag;
            tr[u << 1 | 1].sum.first += tr[u].tag;
            tr[u].tag = 0;
        }
    }

    void build (int u, int l, int r) {
        tr[u].tag = tr[u].sum.first = 0; 
        tr[u].sum.second = r - l + 1;
        if (l == r) return;
        int mid = (l + r) >> 1;
        build(u << 1, l, mid); build(u << 1 | 1, mid + 1, r);
        push_up(u);
    }

    void update (int x, int l, int r, int ql, int qr, int val) {
        if (ql <= l && r <= qr) {
            tr[x].tag += val;
            tr[x].sum.first += val;
            return;
        }
        push_down(x);
        int mid = (l + r) >> 1;
        if (ql <= mid) update(x << 1, l, mid, ql, qr, val);
        if (qr > mid) update(x << 1 | 1, mid + 1, r, ql, qr, val);
        push_up(x);
    }

    pll query (int x, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return tr[x].sum;
        push_down(x);
        int mid = (l + r) >> 1;
        if (qr <= mid) return query(x << 1, l, mid, ql, qr);
        if (ql > mid) return query(x << 1 | 1, mid + 1, r, ql, qr);
        return query(x << 1, l, mid, ql, qr) + query(x << 1 | 1, mid + 1, r, ql, qr);
    }

};

int main() {
    freopen ("D.in", "r", stdin);
    ios::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) {
        int n, k; cin >> n >> k;
        ll ans = 0;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        auto a_ = a;
        sort(a_.begin() + 1, a_.end());
        a_.erase(unique(a_.begin() + 1, a_.end()), a_.end());
        for (int i = 1; i <= n; i++) a[i] = lower_bound(a_.begin() + 1, a_.end(), a[i]) - a_.begin();
        Segment_Tree T(n + 1);
        T.build(1, 1, n);
    
        int m = a_.size();
        vector<vector<int>> pos(m + 1, vector<int>());

        for (int i = 1; i <= m; i++) pos[i].push_back(0);

        for (int i = 1; i <= n; i++) {
            T.update(1, 1, n, pos[a[i]].back() + 1, i, -1);
            if (pos[a[i]].size() >= k + 1) 
                T.update (1, 1, n, pos[a[i]][pos[a[i]].size() - k - 1] + 1, pos[a[i]][pos[a[i]].size() - k], -1);
            pos[a[i]].push_back(i);
            if (pos[a[i]].size() >= k + 1)
                T.update (1, 1, n, pos[a[i]][pos[a[i]].size() - k - 1] + 1, pos[a[i]][pos[a[i]].size() - k], 1);
            
            auto q = T.query(1, 1, n, 1, i);
            if (q.first == 0) {
                ans += q.second;
                // cout << i << " " << q.second << endl;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}