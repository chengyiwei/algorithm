#include <bits/stdc++.h>
using namespace std;

struct node {
    int flg, tag, l_x, r_x;
};

struct Segment_Tree {
    int n;
    vector<node> t;
    Segment_Tree (int n) {
        this -> n = n;
        t.resize(n << 4);
    }

    node merge_node(node a, node b) {
        node c;
        if (a.tag) a.l_x ^= 1, a.r_x ^= 1;
        if (b.tag) b.l_x ^= 1, b.r_x ^= 1;
        c.flg = a.flg & b.flg;
        c.flg &= (a.r_x ^ b.l_x);
        c.l_x = a.l_x;
        c.r_x = b.r_x;
        return c;
    }

    void push_up(int u) {
        t[u] = merge_node(t[u << 1], t[u << 1 | 1]);
    }

    void push_down(int x) {
        if (t[x].tag) {
            t[x].l_x ^= 1; t[x].r_x ^= 1;
            t[x << 1].tag ^= 1; t[x << 1 | 1].tag ^= 1;
            t[x].tag = 0;
        }
    }

    void build(int u, int l,int r,vector<int> &a) {
        if (l == r) {
            t[u].l_x = t[u].r_x = a[l]; t[u].flg = 1; t[u].tag = 0;
            return;
        }
        int mid = l + r >> 1;
        build(u << 1, l, mid, a);
        build(u << 1 | 1, mid + 1, r, a);
        push_up(u);
    }

    void update (int x, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            t[x].tag ^= 1;
            return;
        }
        push_down(x);
        int mid = l + r >> 1;
        if (ql <= mid) update(x << 1, l, mid, ql, qr);
        if (qr > mid) update(x << 1 | 1, mid + 1, r, ql, qr);
        push_up(x);
    }

    node query(int x, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return t[x];
        push_down(x);
        int mid = l + r >> 1;
        if (qr <= mid) return query(x << 1, l, mid, ql, qr);
        if (ql > mid) return query(x << 1 | 1, mid + 1, r, ql, qr);
        return merge_node(query(x << 1, l, mid, ql, qr), query(x << 1 | 1, mid + 1, r, ql, qr));
    }
};

int main() {
    freopen("E.in", "r", stdin);
    int n, Q; scanf("%d %d\n", &n, &Q);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        char ch; scanf(" %c", &ch);
        a[i] = ch - '0';
    }
    Segment_Tree T(n);
    T.build(1, 1, n, a);
    while (Q--) {
        int op, l, r; scanf("%d%d%d", &op, &l, &r);
        if (op == 1) {
            T.update(1, 1, n, l, r);
        } else {
            node res = T.query(1, 1, n, l, r);
            if (res.flg) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}