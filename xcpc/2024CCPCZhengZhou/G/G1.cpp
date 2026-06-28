#include <bits/stdc++.h>

using namespace std;

using u128 = __uint128_t;
using u64 = unsigned long long;
const int N = 200005;
const u64 mod = 1000000000000000009ll, g = 100000000000003ll;
int n, q, a[N];
u64 ig, pw[N], ipw[N];

u64 add(u64 a, u64 b) { return a + b < mod ? a + b : a + b - mod; }
u64 mul(u64 a, u64 b) { return (u128)a * b % mod; }

u64 power(u64 a, u64 n) {
    u64 tp = 1;
    while (n) {
        if (n & 1) {
            tp = mul(tp, a);
        }
        a = mul(a, a), n >>= 1;
    }
    return tp;
}

namespace sgt {
u64 lazy[N << 2], mx[N << 2], mn[N << 2];
u64 s[N << 2], is[N << 2], ls[N << 2], ils[N << 2];

struct node {
    u64 lazy, mx, mn;
    u64 ls, lis, s, is;

    const node operator +(const node &b) const {
        node tp;
        tp.lazy = 0;
        tp.ls = tp.lis = 1;
        tp.s = add(s, b.s);
        tp.is = add(is, b.is);
        tp.mx = max(mx, b.mx);
        tp.mn = min(mn, b.mn);
        return tp;
    }
} f[N << 2];

void cv(int i, u64 x, u64 y, u64 z) {
    f[i].lazy += x;
    f[i].mn += x;
    f[i].mx += x;

    f[i].ls = mul(f[i].ls, y);
    f[i].s = mul(f[i].s, y);

}

void pushdown(int i) {
    if (f[i].lazy != 0) {
        cv(i << 1, f[i].lazy, f[i].ls, f[i].lis);
        cv(i << 1 | 1, f[i].lazy, f[i].ls, f[i].lis);
        f[i].lazy = 0;
        f[i].ls = f[i].lis = 1;
    }
}

void build(int i, int l, int r) {
    if (l == r) {
        f[i].ls = f[i].lis = 1;
        f[i].mx = f[i].mn = a[l];
        f[i].s = pw[a[l]], f[i].is = ipw[a[l]];
        return;
    }

    int mid = (l + r) >> 1;
    build(i << 1, l, mid), build(i << 1 | 1, mid + 1, r);
    f[i] = f[i << 1] + f[i << 1 | 1];
}

void modify(int i, int l, int r, int x, int y, u64 v, u64 sv, u64 siv) {
    if (x <= l && y >= r) {
        cv(i, v, sv, siv);
        return;
    }

    int mid = (l + r) >> 1;
    pushdown(i);
    if (x <= mid) {
        modify(i << 1, l, mid, x, y, v, sv, siv);
    }
    if (y > mid) {
        modify(i << 1 | 1, mid + 1, r, x, y, v, sv, siv);
    }
    f[i] = f[i << 1] + f[i << 1 | 1];
}

node query(int i, int l, int r, int x, int y) {
    if (x <= l && y >= r) {
        return f[i];
    }

    int mid = (l + r) >> 1;
    pushdown(i);
    if (y <= mid) {
        return query(i << 1, l, mid, x, y);
    }
    if (x > mid) {
        return query(i << 1 | 1, mid + 1, r, x, y);
    }

    return query(i << 1, l, mid, x, y) + query(i << 1 | 1, mid + 1, r, x, y);
}
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    ig = power(g, mod - 2);
    pw[0] = ipw[0] = 1;
    for (int i = 1; i <= 200000; i++) {
        pw[i] = mul(pw[i - 1], g);
        ipw[i] = mul(ipw[i - 1], ig);
    }

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sgt::build(1, 1, n);

    while (q--) {
        int op, l, r;
        cin >> op >> l >> r;
        if (op == 1) {
            int v;
            cin >> v;
            sgt::modify(1, 1, n, l, r, v);
        } else {
            sgt::node tp = sgt::query(1, 1, n, l, r);
            u64 mnv = mul(tp.s, power(ig, tp.mn));
            u64 mxv = mul(tp.is, power(g, tp.mx));

            if (mnv == mxv) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
}