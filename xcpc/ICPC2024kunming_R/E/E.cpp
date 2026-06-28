#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

void solve() {
    ll n, m; cin >> n >> m;
    map<pair<ll,ll>, int> mp;
    queue<pair<ll,ll>> q;
    q.push({n, m}); mp[{n, m}] = 0;
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        if (x == 0 && y == 0) {
            cout << mp[{x, y}] << "\n";
            return;
        }
        ll g = gcd(x, y);
        
        auto in = [&] (ll a, ll b, int c) {
            if (!mp.count({a, b})) {
                mp[{a, b}] = c;
                q.push({a, b});
            }
        };

        int dis = mp[{x, y}] + 1;
        in(x - g, y, dis);
        in(x, y - g, dis);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) solve();
    return 0;
}