#include <bits/stdc++.h>
using namespace std;
const int N = 300006;

struct Node {
    int mx, freq;
    int tg;
    array<int, 60> v;
};

struct Seg : array<Node, N << 2> {
#define ls (p << 1)
#define rs (ls | 1)
#define cur at(p)
#define lson at(ls)
#define rson at(rs)

    void build(int p, int l, int r) {
        cur.mx = 0;
        cur.freq = r - l + 1;
        for (int i = 0; i < 60; i++) cur.v[i] = -1;
        if (l == r) return;
        int mid = (l + r) >> 1;
        build(ls, l, mid);
        build(rs, mid + 1, r);
    }

    void pd(int p, int x) {
        lson.mx += cur.tg;
        rson.mx += cur.tg;
        lson.tg+=cur.tg;
        rson.tg+=cur.tg;
        cur.tg = 0;
        if (cur.v[x] == 0) return;
        lson.v[x] = cur.v[x];
        rson.v[x] = cur.v[x];
    }

    void pushup(int p, int x) {
        if (lson.mx > rson.mx) {
            cur.mx = lson.mx;
            cur.freq = lson.freq;
        } else if (lson.mx < rson.mx) {
            cur.mx = rson.mx;
            cur.freq = rson.freq;
        } else {
            cur.mx = lson.mx;
            cur.freq = lson.freq + rson.freq;
        }
        if (lson.v[x] == rson.v[x]) cur.v[x] = lson.v[x];
        else cur.v[x] = 0;
    }

    void pushdown(int p, int l, int r, int x, int t) {
        // cout << "pushdown " << l << " " << r << " " << x << " " << t << "\n";
        if (l == r) {
            if (cur.v[x] == -1 && t == 1) {
                cur.mx++;
                cur.v[x] = 1;
            }
            if (cur.v[x] == 1 && t == -1) {
                cur.mx--;
                cur.v[x] = -1;
            }
            return;
        }
        if (cur.v[x] == t) {
            return;
        }
        pd(p, x);
        if (cur.v[x] == -1 && t == 1) {
            // cout << "!!!" << endl;
            cur.mx++;
            cur.tg++;
            cur.v[x] = 1;
            pd(p, x);
            return;
        }
        if (cur.v[x] == 1 && t == -1) {
            cur.mx--;
            cur.tg--;
            cur.v[x] = -1;
            pd(p, x);
            return;
        }
        int mid = (l + r) >> 1;
        pushdown(ls, l, mid, x, t);
        pushdown(rs, mid + 1, r, x, t);
        pushup(p, x);
    }
    void update(int p, int l, int r, int ql, int qr, int x, int t) {
        // if (cur.v[x] == t) {
        //     return;
        // }
        // cout << "update " << l << " " << r << " " << ql << " " << qr << " " << x << " " << t << "\n";
        if (ql <= l && r <= qr) {
            pushdown(p, l, r, x, t);
            // cout << "after pushdown mx: " << cur.mx << endl;
            // pushup(p, x);
            return;
        }
        pd(p, x);
        int mid = (l + r) >> 1;
        if (ql <= mid) update(ls, l, mid, ql, qr, x, t);
        if (qr > mid) update(rs, mid + 1, r, ql, qr, x, t);
        pushup(p, x);
    }

    pair<int, int> query(int p, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return {cur.mx, cur.freq};
        }

        lson.mx += cur.tg;
        rson.mx += cur.tg;
        lson.tg+=cur.tg;
        rson.tg+=cur.tg;
        cur.tg = 0;

        int mid = (l + r) >> 1;
        pair<int, int> res = {0, 0};
        if (ql <= mid) {
            auto t = query(ls, l, mid, ql, qr);
            if (t.first > res.first) {
                res = t;
            } else if (t.first == res.first) {
                res.second += t.second;
            }
        }
        if (qr > mid) {
            auto t = query(rs, mid + 1, r, ql, qr);
            if (t.first > res.first) {
                res = t;
            } else if (t.first == res.first) {
                res.second += t.second;
            }
        }
        return res;
    }

    void print(int p, int l, int r) {
        cout << "[" << l << ", " << r << "] mx: " << cur.mx << " freq: " << cur.freq << "\n";
        if (l == r) return;
        int mid = (l + r) >> 1;
        print(ls, l, mid);
        print(rs, mid + 1, r);
    }
} seg;

int n, q;
void solve() {
    int op, l, r, x;
    cin >> op >> l >> r;
    if (op == 3) {
        auto [mx, freq] = seg.query(1, 1, n, l, r);
        cout << mx << " " << freq << "\n";
    } else {
        cin >> x;
        x--;
        if (op == 1) {
            seg.update(1, 1, n, l, r, x, 1);
        } else {
            seg.update(1, 1, n, l, r, x, -1);
        }
        // seg.print(1, 1, n);
    }
}

int main() {
    freopen ("G.in", "r", stdin);
    freopen ("std.out", "w", stdout);
    cin >> n >> q;
    seg.build(1, 1, n);
    while (q--) solve();
    return 0;
}
