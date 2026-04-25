#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 1e3 + 5;
ll Tex, f[(1 << 12) + 2][MAXN], n, q, vis[(1 << 12) + 2];
vector<ll> mp[(1 << 12) + 2];
void init_set(ll fa[]) {
    for (int i = 0; i <= n; i ++) {
        fa[i] = i;
    }
}
ll find_set(ll fa[], ll x) {
    return fa[x] = fa[x] == x ? fa[x] : find_set(fa, fa[x]);
}
void union_set(ll fa[], ll x, ll y) {
    x = find_set(fa, x);
    y = find_set(fa, y);
    if (x == y) return;
    fa[x] = y;
}
void dfs(ll val, ll x, ll y) {
    x = find_set(f[val], x);
    y = find_set(f[val], y);
    if (x == y) return;
    union_set (f[val], x, y);
    for (auto it : mp[val]) {
        dfs (it, x, y);
    }
}
void AC() {
    cin >> n >> q;
    for (int i = 0; i < (1 << 12); i ++) {
        init_set(f[i]);
    }
    ll ans = 0;
    while (q --) {
        char ch;
        ll x, y, w;
        cin >> ch >> x >> y;
        if (ch == '+') {
            cin >> w;
            dfs(w, x, y);
        }
        else {
            ll dq = 0;
            for (int i = 11; i >= 0; i --) {
                ll xx = find_set (f[dq | (1 << i)], x);
                ll yy = find_set (f[dq | (1 << i)], y);
                if (xx == yy) dq |= (1 << i);
            }
            if (find_set(f[0], x) != find_set(f[0], y)) dq = -1;
            ans += dq;
        }
        // cout << q << "\n";
    }
    cout << ans << "\n";
}
void calc(ll x) {
    vis[x] = 1;
    // cout << x << "\n";
    for (int i = 0; i < 12; i ++) {
        if ((x >> i) & 1) {
            ll xx = x - (1 << i);
            mp[x].push_back(xx);
            if (vis[xx]) continue;
            calc(xx);
        }
    }
}
int main() {
    // freopen("F.in", "r", stdin);
    // freopen("F.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    calc((1 << 12) - 1);
    cin >> Tex;
    while (Tex --) AC();
    return 0;
}