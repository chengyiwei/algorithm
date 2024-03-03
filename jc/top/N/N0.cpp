#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 2e5 + 5;

struct Node {
    LL add, cf;
}t[maxn << 2];

int n, a[maxn], q;

void build (int x, int l, int r) {
    if (l == r) { t[x].add = a[l]; t[x].cf = 0; return; }
    int mid = (l + r) >> 1;
    build(x << 1, l, mid); build(x << 1 | 1, mid + 1, r);
}

void update (int x, int l, int r, int ql, int qr, LL K, LL D) {
    if (l >= ql && r <= qr) {
        t[x].add += K + D * (l - ql); t[x].cf += D; return;
    }
    int mid = (l + r) >> 1;
    if (ql <= mid) update(x << 1, l, mid, ql, qr, K, D);
    if (qr > mid) update(x << 1 | 1, mid + 1, r, ql, qr, K, D);
}

LL query (int x, int l, int r, int pos) {
    LL ret = t[x].add + t[x].cf * (pos - l);
    if (l == r) return ret;
    int mid = (l + r) >> 1;
    if (pos <= mid) ret += query(x << 1, l, mid, pos);
    else ret += query(x << 1 | 1, mid + 1, r, pos);
    return ret;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    while (q--) {
        int opt; cin >> opt;
        if (opt == 1) {
            int l, r; LL K, D; cin >> l >> r >> K >> D;
            update(1, 1, n, l, r, K, D);
        }
        else {
            LL pos; cin >> pos;
            cout << query(1, 1, n, pos) << '\n';
        }
    }
    return 0;
}