#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 5e5 + 5;
ll c[maxn];

void add_x(int x, ll v) {
    for (; x < maxn; x += x & -x)
        c[x] += v;
}
ll query_x(int x) {
    ll res = 0;
    for (; x; x -= x & -x)
        res += c[x];
    return res;
}

int main() {
    freopen ("A.in", "r", stdin);
    int n, m; cin >> n >> m;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        add_x(i, a[i]); add_x(i + 1, -a[i]);
    }
    while (m--) {
        int op; cin >> op;
        if (op == 1) {
            int l, r; ll x; cin >> l >> r >> x;
            add_x(l, x); add_x(r + 1, -x);
        }
        else {
            int p; cin >> p;
            cout << query_x(p) << endl;
        }
    }
    return 0;
}