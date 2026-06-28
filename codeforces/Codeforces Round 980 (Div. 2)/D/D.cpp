#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;


void solve() {
    int n; cin >> n;
    vector<ll> w(n + 1, 0);
    vector<int> b(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    vector<ll> c(n + 1, INF);
    auto add = [&] (int x, ll val) {
        for (int i = x; i <= n; i += i & -i)
            c[i] = min(c[i], val);
    };

    auto get = [&] (int x) {
        ll ret = INF;
        for (int i = x; i ; i -= i & -i) 
            ret = min(ret, c[i]);
        return ret;
    };

    vector<ll> dis(n + 1, INF);
    add(n, 0);
    for (int i = 1; i <= n; i++) {

        int pos = n - i + 1;
        dis[i] = get(pos);
        if (b[i] <= i) continue;
        int pos_ = n - b[i] + 1;
        add(pos_, dis[i] + w[i]);
    }
    ll pre = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        pre += w[i];
        ans = max(ans, pre - dis[i]);
    }
    cout << ans << '\n';
}

int main() {
    freopen ("D.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int T; cin >> T;
    while (T--) solve();
    return 0;
}