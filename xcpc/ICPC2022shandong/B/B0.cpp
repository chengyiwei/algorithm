#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
typedef long long ll;
typedef pair<ll, ll> pll;
int main() {
    freopen ("B.in", "r", stdin);
    freopen ("B0.out", "w", stdout);
    int n; cin >> n;
    map<ll, ll> hav;
    for (int i = 1; i <= n; i++) {
        int op, x; cin >> op >> x;
        hav[op] += x;
    }
    int q; cin >> q;
    vector<vector<pll> > c (q + 1);
    vector<vector<pll> > g (q + 1);
    for (int i = 1; i <= q; i++) {
        int m; cin >> m;
        c[i].resize(m);
        for (int j = 0; j < m; j++) {
            cin >> c[i][j].first >> c[i][j].second;
        }
        cin >> m;
        g[i].resize(m);
        for (int j = 0; j < m; j++) {
            cin >> g[i][j].first >> g[i][j].second;
        }
    }
    
    vector<int> vis(q + 1, 0);

    int ans = 0;
    auto get_i = [&] (int i) {
        for (auto [op, x] : c[i]) {
            if (hav[op] < x) return false;
        }
        return true;
    };

    auto get = [&] (){
        for (int i = 1; i <= q; i++) {
            if (vis[i]) continue;
            if (get_i(i)) { // i 
                ans ++;
                vis[i] = 1;
                for (auto [op, x] : g[i]) {
                    hav[op] += x;
                }
                return true;
            }
        }
        return false;
    };

    while (get());
    cout << ans << '\n';
    return 0;
}