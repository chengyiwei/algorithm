#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e17;
const int maxn = 1e3 + 1;

ll maxv[maxn << 2][maxn << 2];

struct Segment_Tree {
    int n;

    void build_y (int u, int rt, int l, int r) {
        maxv[rt][u] = -inf;
        if (l == r) return;
        int mid = (l + r) >> 1;
        build_y(u << 1, rt, l, mid);
        build_y(u << 1 | 1, rt, mid + 1, r);
    }

    void build_x (int u, int l, int r) {
        build_y (1, u, 1, n);
        if (l == r) return;
        int mid = (l + r) >> 1;
        build_x(u << 1, l, mid);
        build_x(u << 1 | 1, mid + 1, r);
    }

    void init(int _n) {
        n = _n;
        build_x(1, 1, n);
    }

    void update_y(int u, int rt, int l, int r, int y, ll val) {
        if (l == r) {
            maxv[rt][u] = max(maxv[rt][u], val);
            return;
        }
        int mid = (l + r) >> 1;
        if (y <= mid) update_y(u << 1, rt, l, mid, y, val);
        else update_y(u << 1 | 1, rt, mid + 1, r, y, val);
        maxv[rt][u] = max(maxv[rt][u << 1], maxv[rt][u << 1 | 1]);
    }
    void update_x(int u, int l, int r, int x, int y, ll val) {
        update_y(1, u, 1, n, y, val);
        if (l == r) return;
        int mid = (l + r) >> 1;
        if (x <= mid) update_x(u << 1, l, mid, x, y, val);
        else update_x(u << 1 | 1, mid + 1, r, x, y, val);
    }
    ll query_y (int u, int rt, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr)
            return maxv[rt][u];
        int mid = (l + r) >> 1;
        ll res = -inf;
        if (ql <= mid)
            res = max(res, query_y(u << 1, rt, l, mid, ql, qr));
        if (qr > mid)
            res = max(res, query_y(u << 1 | 1, rt, mid + 1, r, ql, qr));
        return res;
    }
    ll query_x (int u, int l, int r, int qlx, int qrx, int qly, int qry) {
        if (qlx <= l && r <= qrx)
            return query_y (1, u, 1, n, qly, qry);
        int mid = (l + r) >> 1;
        ll res = -inf;
        if (qlx <= mid)
            res = max(res, query_x(u << 1, l, mid, qlx, qrx, qly, qry));
        if (qrx > mid)
            res = max(res, query_x(u << 1 | 1, mid + 1, r, qlx, qrx, qly, qry));
        return res;
    }
}st;

ll sum[maxn][maxn], a[maxn][maxn];

ll solve (int n, int m, vector<vector<ll> >& mp) {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + mp[i][j]; // 2维前缀和
        
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            if (i < m || j < m) { a[i][j] = -inf; continue; }
            a[i][j] = sum[i][j] - sum[i - m][j] - sum[i][j - m] + sum[i - m][j - m]; // 2维区间和
        }
    
    st.init(n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            st.update_x(1, 1, n, i, j, a[i][j]);
    
    ll ans = -inf, now_1, now_2, now_3;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            if (i >= m && j - i >= m && n - j >= m) {
                now_1 = st.query_x (1, 1, n, 1, n, 1, i);
                now_2 = st.query_x (1, 1, n, 1, n, i + m, j);
                now_3 = st.query_x (1, 1, n, 1, n, j + m, n);
                ans = max(ans, now_1 + now_2 + now_3);
            }

            if (i >= m && j >= m && n - j >= m && n - i >= m) {
                now_1 = st.query_x (1, 1, n, 1, i, 1, n);
                now_2 = st.query_x (1, 1, n, i + m, n, 1, j);
                now_3 = st.query_x (1, 1, n, i + m, n, j + m, n);
                ans = max(ans, now_1 + now_2 + now_3);
            }

            if (i >= m && n - i >= m && j >= m && n - j >= m) {
                now_1 = st.query_x (1, 1, n, i + m, n, 1, n);
                now_2 = st.query_x (1, 1, n, 1, i, 1, j);
                now_3 = st.query_x (1, 1, n, 1, i, j + m, n);
                ans = max(ans, now_1 + now_2 + now_3);
            }
        }
    return ans;
}

inline ll read_ll() {
    ll x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}

inline int read_int() {
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}

int main() {
    freopen ("F.in", "r", stdin);
    freopen ("F.out", "w", stdout);
    int n, m; n = read_int(); m = read_int();
    vector<vector<ll> > mp(n + 1, vector<ll>(n + 1, 0)), sum(n + 1, vector<ll>(n + 1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            mp[i][j] = read_ll();
    
    ll ans = solve(n, m, mp);
    for (int k = 0; k < 1; k++) {
        // rotate 90 degree
        vector<vector<ll> > tmp(n + 1, vector<ll>(n + 1, 0));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                tmp[i][j] = mp[j][n - i + 1];
        mp = tmp;
        ans = max(ans, solve(n, m, mp));
    }
    cout << ans << endl;
    return 0;
}
