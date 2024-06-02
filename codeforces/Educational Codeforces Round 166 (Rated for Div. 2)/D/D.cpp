#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> p;
ll ans;



struct Segment_Tree {
    int n;
    vector<int> t;
    Segment_Tree(int n) : n(n) {
        t.resize(n << 2);
    }
    void push_up (int x) {
        t[x] = max(t[x << 1], t[x << 1 | 1]);
    }

    void update (int x, int l, int r, int pos, int val) {
        if (l == r) {
            t[x] = val;
            return;
        }
        int mid = (l + r) >> 1;
        if (pos <= mid) update(x << 1, l, mid, pos, val);
        else update(x << 1 | 1, mid + 1, r, pos, val);
        push_up(x);
    }
    int query (int x, int l, int r, int L, int R) {
        if (l > R) return 0;

        if (l >= L && r <= R) return t[x];
        int mid = (l + r) >> 1;
        int res = 0;
        if (L <= mid) res = max(res, query(x << 1, l, mid, L, R));
        if (R > mid) res = max(res, query(x << 1 | 1, mid + 1, r, L, R));
        return res;
    }
};

void solve() {
    string s; cin >> s;
    int n = s.size();
    p.resize(n + 1); p[0] = 0;
    Segment_Tree seg(n + 1);
    vector<vector<int> > pos(n + 1);
    for (int i = 1; i <= n; i++) {
        char ch = s[i - 1];
        if (ch == '(') p[i] = p[i - 1] + 1;
        else p[i] = p[i - 1] - 1;
    }
    ans = 0;
    for (int i = 1; i <= n; i++) {
        int p_ = seg.query(1, 1, n, 2 * p[i] + 1, n);
        int add = distance(lower_bound(pos[p[i]].begin(), pos[p[i]].end(), p_), pos[p[i]].end());
        ans += add;
        pos[p[i]].push_back(i);
        seg.update(1, 1, n, p[i], i);    
    }
    cout << ans << '\n';
}

int main() {
    freopen ("D.in", "r", stdin);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) solve();
}