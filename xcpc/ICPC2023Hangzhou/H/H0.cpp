#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const ll TT = 1e9 + 7;
const int maxn = 5e5 + 5;
ll Fac[maxn], Inv[maxn];

ll qpow (ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % TT;
        a = a * a % TT;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n; cin >> n;

    for (int i = n - 1; i >= 0; i--) Inv[i] = Inv[i + 1] * (i + 1) % TT;

    vector<vector<int> > g(n + 1);
    vector<int> a(n + 1), b(n + 1), c(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) cin >> c[i];

    queue<pii> q;
    vector<int> vis(n + 1, 0);
    vector<ll> p(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (a[i] >= a[b[i]] + c[b[i]]) continue;  //不可能发生
        if (a[i] < a[b[i]])
            q.push({i, 1ll}), vis[i] = 1;
        else
            g[b[i]].push_back(i);
    }

    while (!q.empty()) {
        int u = q.front().first; int d = q.front().second; q.pop();
        p[u] = Inv[d];
        for (auto v : g[u]) {
            if (vis[v]) continue;
            vis[v] = 1;
            q.push({v, d + 1});
        }
    }

    for (int i = 1; i <= n; i++) {
        ll now = (a[i] + c[i] * p[i]) % TT;
        cout << now << " ";
    }
    cout << '\n';
}

int main() {
    freopen ("H.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    Fac[0] = 1; for (int i = 1; i < maxn; i++) Fac[i] = Fac[i - 1] * i % TT;
    Inv[maxn - 1] = qpow(Fac[maxn - 1], TT - 2);
    for (int i = maxn - 2; i >= 0; i--) Inv[i] = Inv[i + 1] * (i + 1) % TT;
    
    int t; cin >> t;
    while (t--) solve();
    return 0;
}