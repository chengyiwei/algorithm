#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 0x3f3f3f3f;

struct Segment_Tree {
    struct Lazy {
        int add; // 加上的值
        Lazy(int v = 0) : add(v) {}
        void apply(const Lazy &rhs) {
            add += rhs.add;
        }
    };

    struct Info {
        int max_val, max_num;
        Info(int max_v = 0, int max_n = 1) : max_val(max_v), max_num(max_n) {}
        Info operator + (const Info &rhs) const {
            Info res;
            if (max_val == rhs.max_val) {
                res.max_val = max_val;
                res.max_num = max_num + rhs.max_num;
            }
            else if (max_val > rhs.max_val) {
                res.max_val = max_val;
                res.max_num = max_num;
            }
            else {
                res.max_val = rhs.max_val;
                res.max_num = rhs.max_num;
            }
            return res;
        };
        void apply(const struct Lazy &rhs) {
            if (rhs.add) { max_val += rhs.add; }
        }
    };

    int n;
    vector<Info> info;
    vector<Lazy> lazy;
    Segment_Tree(int n) : n(n) {
        info.assign(n * 4, Info());
        lazy.assign(n * 4, Lazy());
    };

    void apply(int o, const Lazy &x) {
        info[o].apply(x);
        lazy[o].apply(x);
    }

    void push_up(int o) {
        info[o] = info[o << 1] + info[o << 1 | 1];
    }

    void push_down(int o) {
        apply(o << 1, lazy[o]);
        apply(o << 1 | 1, lazy[o]);
        lazy[o] = Lazy();
    }

    void update(int o, int l, int r, int ql, int qr, const Lazy &x) {
        if (ql >= r || qr <= l) return ;
        if (ql <= l && r <= qr) {
            apply(o, x);
            return ;
        }
        push_down(o);
        int mid = (r - l) / 2 + l;
        update(o << 1, l, mid, ql, qr, x);
        update(o << 1 | 1, mid, r, ql, qr, x);
        push_up(o);
    }

    void update(int l, int r, const Lazy &x) {
        update(1, 0, n, l, r, x);
    }

    void update(int l, int r, int v) {
        Lazy lazy = Lazy(v);
        update(1, 0, n, l, r, lazy);
        // cout << "update: " << l << ' ' << r << ' ' << lazy.add << '\n';
    }

    Info query(int o, int l, int r, int ql, int qr) {
        if (ql >= r || qr <= l) return Info(-INF, 0);
        if (ql <= l && r <= qr) {
            return info[o];
        }
        push_down(o);
        int mid = (r - l) / 2 + l;
        Info res = query(o << 1, l, mid, ql, qr) + query(o << 1 | 1, mid, r, ql, qr);
        push_up(o);
        return res;
    }

    Info query(int l, int r) {
        return query(1, 0, n, l, r);
    }

    void build(int o, int l, int r) {
        if (r - l == 1) {
            info[o] = Info(0, 1);
            return ;
        }
        int mid = (r - l) / 2 + l;
        build(o << 1, l, mid);
        build(o << 1 | 1, mid, r);
        push_up(o);
    }
};

struct Segment_Tree_60 {
    struct Lazy {
        bool all_0, all_1;
        Lazy(int v = -1) : all_0(v == 0), all_1(v == 1) {}
        void apply(const Lazy &rhs) {
            if (rhs.all_0) { all_0 = 1; all_1 = 0; }
            if (rhs.all_1) { all_0 = 0; all_1 = 1; }
        }
    };

    struct Info {
        bool all_0, all_1;
        Info(int v = 0) {
            if (v == 0) {all_0 = 1; all_1 = 0;}
            else {all_0 = 0; all_1 = 1;}
        };
        Info operator + (const Info &rhs) const {
            Info res;
            res.all_0 = all_0 & rhs.all_0;
            res.all_1 = all_1 & rhs.all_1;
            return res;
        };
        void apply(const struct Lazy &rhs) {
            if (rhs.all_0) { all_0 = 1; all_1 = 0; }
            if (rhs.all_1) { all_0 = 0; all_1 = 1; }
        }
    };

    int n;
    vector<Info> info;
    vector<Lazy> lazy;
    Segment_Tree_60(int n) : n(n) {
        info.assign(n * 4, Info());
        lazy.assign(n * 4, Lazy());
    };

    void apply(int o, const Lazy &x) {
        info[o].apply(x);
        lazy[o].apply(x);
    }

    void push_up(int o) {
        info[o] = info[o << 1] + info[o << 1 | 1];
    }

    void push_down(int o) {
        apply(o << 1, lazy[o]);
        apply(o << 1 | 1, lazy[o]);
        lazy[o] = Lazy();
    }

    void update(int o, int l, int r, int ql, int qr, const Lazy &x, Segment_Tree &seg_t) {
        if (ql >= r || qr <= l) return ;
        if (ql <= l && r <= qr && (info[o].all_0 || info[o].all_1)) {
            if (info[o].all_0 && x.all_1) {
                // 0 -> 1
                seg_t.update(l, r, 1);
            }
            if (info[o].all_1 && x.all_0) {
                // 1 -> 0
                seg_t.update(l, r, -1);
            }
            apply(o, x);
            return ;
        }
        push_down(o);
        int mid = (r - l) / 2 + l;
        update(o << 1, l, mid, ql, qr, x, seg_t);
        update(o << 1 | 1, mid, r, ql, qr, x, seg_t);
        push_up(o);
    }

    void update(int l, int r, const Lazy &x, Segment_Tree &seg_t) {
        update(1, 0, n, l, r, x, seg_t);
    }
};

int main() {
    // freopen ("G.in", "r", stdin);
    // freopen ("G.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, q; cin >> n >> q;
    Segment_Tree seg_t(n); seg_t.build(1, 0, n);
    vector<Segment_Tree_60> seg_t_60(61, Segment_Tree_60(n));

    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int ql, qr, v; cin >> ql >> qr >> v;
            ql--;
            seg_t_60[v].update(ql, qr, Segment_Tree_60::Lazy(1), seg_t);
        }
        if (op == 2) {
            int ql, qr, v; cin >> ql >> qr >> v;
            ql--;
            seg_t_60[v].update(ql, qr, Segment_Tree_60::Lazy(0), seg_t);
        }
        if (op == 3) {
            int ql, qr; cin >> ql >> qr;
            ql--;
            auto res = seg_t.query(ql, qr);
            cout << res.max_val << " " << res.max_num << "\n";
        }
    }

    return 0;
}