#include <bits/stdc++.h>
using namespace std;
typedef __int128 ll;

const ll inf = 1e18;
const ll INF = inf * inf;
ll read() {
    ll x = 0, f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
    return x * f;
}
void print(ll x) {
    if (x < 0) {putchar('-'); x = -x;}
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');

}
struct Segment_Tree {
    vector<ll> val;
    int n;
    Segment_Tree(int n) : n(n) {val.assign(4 * n, -INF);}
    void push_up(int x) {val[x] = max(val[x << 1], val[x << 1 | 1]);}
    ll query(int x, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return val[x];
        if (ql > qr) return -INF;
        ll res = -INF;
        int mid = (l + r) / 2;
        if (ql <= mid) res = max(res, query(x << 1, l, mid, ql, qr));
        if (qr > mid) res = max(res, query(x << 1 | 1, mid + 1, r, ql, qr));
        return res;
    }
    void update(int x, int l, int r, int pos, ll v) {
        if (l == r) {val[x] = v; return;}
        int mid = (l + r) / 2;
        if (pos <= mid) update(x << 1, l, mid, pos, v);
        else update(x << 1 | 1, mid + 1, r, pos, v);
        push_up(x);
    }
};

int main() {
    // freopen ("F.in", "r", stdin);
    ll ret = 0;
    int n; cin >> n;
    ll C = read(); 
    int m; cin >> m;
    vector<ll> T(m + 1, 0ll), P(m + 1, 0ll);
    for (int i = 1; i <= m; i++)
        T[i] = read(), P[i] = read();
    Segment_Tree up(n + 1), dn(n + 1);
    up.update(1, 1, n, 1, C);
    dn.update(1, 1, n, 1, -C);
    vector<ll> dp(n + 1, -INF); dp[1] = 0;
    for (int i = 1; i <= m; i++) {
        ll ans_l = up.query(1, 1, n, 1, T[i] - 1) - C * T[i] + P[i];
        ll ans_r = dn.query(1, 1, n, T[i] + 1, n) + C * T[i] + P[i];
        ll ans = max(ans_l, ans_r);
        ans = max(ans , dp[T[i]] + P[i]);
        dp[T[i]] = max(dp[T[i]], ans);
        ret = max(ret, ans);
        up.update(1, 1, n, T[i], ans + C * T[i]);
        dn.update(1, 1, n, T[i], ans - C * T[i]);
    }
    print(ret); puts("");
    return 0;
}