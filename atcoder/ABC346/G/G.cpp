#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Segment_Tree {
    int n;
    vector<int> sum, tag;
    Segment_Tree (int n) {
        this->n = n;
        tag.assign(n << 2, 0);
        sum.assign(n << 2, 0);
    }


    void update (int x, int l, int r, int ql, int qr, int val) {
        if (ql <= l && r <= qr) {
            tag[x] += val;
            if (tag[x]) sum[x] = r - l + 1;
            else if (l == r) sum[x] = 0;
            else sum[x] = sum[x << 1] + sum[x << 1 | 1];
            return ;
        }
        int mid = (l + r) >> 1;
        if (ql <= mid) update(x << 1, l, mid, ql, qr, val);
        if (qr > mid) update(x << 1 | 1, mid + 1, r, ql, qr, val);
        if (!tag[x]) sum[x] = sum[x << 1] + sum[x << 1 | 1];
    }

};

struct Line {
    int l, r, x, op;
    Line (int l, int r, int x, int op) : l(l), r(r), x(x), op(op) {}
    bool operator < (const Line &rhs) {
        if (x == rhs.x) return op < rhs.op;
        return x < rhs.x;
    }
};

int main() {
    freopen ("G.in", "r", stdin);
    int n; cin >> n;
    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<int> pre(n + 1, 0), nxt(n + 1, n + 1), pos(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        pre[i] = pos[a[i]];
        pos[a[i]] = i;
    }
    pos.assign(n + 1, n + 1);
    for (int i = n; i; i--) {
        nxt[i] = pos[a[i]];
        pos[a[i]] = i;
    }
    
    vector<Line> lines;
    for (int i = 1; i <= n; i++) {
        lines.emplace_back(i, nxt[i] - 1, pre[i], 1);
        lines.emplace_back(i, nxt[i] - 1, i, -1);
    }
    
    Segment_Tree T(n);
    ll ans = 0;
    sort(lines.begin(), lines.end());
    for (int i = 0; i < lines.size() - 1; i++) {
        T.update(1, 1, n, lines[i].l, lines[i].r, lines[i].op);
        ans += 1ll * T.sum[1] * (lines[i + 1].x - lines[i].x);
    }
    cout << ans << endl;
    return 0;
}