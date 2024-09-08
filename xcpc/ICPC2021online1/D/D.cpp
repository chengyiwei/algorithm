#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;

struct Segment_Tree {
    vector<int> tr;
    
    Segment_Tree(int n = 0) {tr.assign(n << 2, INF);}
    
    void update(int x, int l, int r, int ql, int qr, int val) {
        if (ql <= l && r <= qr) {
            tr[x] = min(tr[x], val);
            return ;
        }
        int mid = (l + r) >> 1;
        if (ql <= mid) update(x << 1, l, mid, ql, qr, val);
        if (mid + 1 <= qr) update(x << 1 | 1, mid + 1, r, ql, qr, val);
    }

    int query(int x, int l, int r, int pos) {
        int res = tr[x];
        if (l == r) return res;
        int mid = (l + r) >> 1;
        if (pos <= mid) res = min(res, query(x << 1, l, mid, pos));
        else res = min(res, query(x << 1 | 1, mid + 1, r, pos));
        return res;
    }
};

void solve() {
    int n, m; cin >> n >> m;
    Segment_Tree T(n);
    ll total = 0;
    for (int i = 1; i <= m; i++) {
        int l, r, w; cin >> l >> r >> w; r -= 1;
        T.update(1, 1, n - 1, l, r, w);
        int len = r - l + 1 + 1;
        total += 1ll * len * (len - 1) / 2 * w;
    }
    for (int i = 1; i <= n - 1; i++) {
        int x = T.query(1, 1, n - 1, i);
        if (x == INF) {cout << "Gotta prepare a lesson" << '\n'; return ;}
        total -= x;
    }
    cout << total << '\n';
    
}

int main() {
    freopen ("D.in", "r", stdin);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    int cnt = 0;
    while (T--) {
        cout << "Case #" << ++cnt << ": ";
        solve();
    }
    return 0;
}