#include <bits/stdc++.h>
using namespace std;
int n, q;

struct Node {
    int l, r;
    int fst, scd, num_fst, num_scd;
};

vector<Node> t;

Node merge_node (Node a, Node b) {
    Node c;
    if (a.fst == b.fst) {
        c.fst = a.fst; c.num_fst = a.num_fst + b.num_fst;
        if (a.scd > b.scd)
            c.scd = a.scd, c.num_scd = a.num_scd;
        if (a.scd < b.scd)
            c.scd = b.scd, c.num_scd = b.num_scd;
        if (a.scd == b.scd)
            c.scd = a.scd, c.num_scd = a.num_scd + b.num_scd;
    }
    if (a.fst > b.fst) {
        c.fst = a.fst; c.num_fst = a.num_fst;
        if (a.scd > b.fst)
            c.scd = a.scd, c.num_scd = a.num_scd;
        if (a.scd < b.fst)
            c.scd = b.fst, c.num_scd = b.num_fst;
        if (a.scd == b.fst)
            c.scd = a.scd, c.num_scd = a.num_scd + b.num_fst;
    }
    if (a.fst < b.fst) {
        c.fst = b.fst; c.num_fst = b.num_fst;
        if (a.fst > b.scd)
            c.scd = a.fst, c.num_scd = a.num_fst;
        if (a.fst < b.scd)
            c.scd = b.scd, c.num_scd = b.num_scd;
        if (a.fst == b.scd)
            c.scd = a.fst, c.num_scd = a.num_fst + b.num_scd;
    }
    return c;
}

void push_up (int x) {
    int l = t[x << 1].l, r = t[x << 1 | 1].r;
    t[x] = merge_node(t[x << 1], t[x << 1 | 1]);
    t[x].l = l; t[x].r = r;
}

void build (int x, int l, int r, vector<int> &a) {
    t[x].l = l; t[x].r = r;
    if (l == r) {
        t[x].fst = a[l]; t[x].num_fst = 1;
        t[x].scd = -1; t[x].num_scd = 0;
        return ;
    }
    int mid = (l + r) >> 1;
    build(x << 1, l, mid, a); build(x << 1 | 1, mid + 1, r, a);
    push_up (x);
}

void update (int x, int l, int r, int pos, int val) {
    if (l == r) {
        t[x].fst = val; t[x].num_fst = 1;
        t[x].scd = -1; t[x].num_scd = 0;
        return ;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) update(x << 1, l, mid, pos, val);
    else update(x << 1 | 1, mid + 1, r, pos, val);
    push_up(x);
}

Node query (int x, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return t[x];
    int mid = (l + r) >> 1;
    if (qr <= mid) return query(x << 1, l, mid, ql, qr);
    if (ql > mid) return query(x << 1 | 1, mid + 1, r, ql, qr);
    return merge_node(query(x << 1, l, mid, ql, qr), query(x << 1 | 1, mid + 1, r, ql, qr));
}

int main() {
    freopen ("F.in", "r", stdin);
    freopen ("F.out", "w", stdout);
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    t.resize(4 * n + 1);
    build(1, 1, n, a);
    while (q--) {
        int opt; cin >> opt;
        if (opt == 1) {
            int p, x; cin >> p >> x;
            update(1, 1, n, p, x);
        }
        else {
            int ql, qr; cin >> ql >> qr;
            Node ans = query(1, 1, n, ql, qr);
            cout << ans.num_scd << '\n';
        }
    }
    return 0;
}