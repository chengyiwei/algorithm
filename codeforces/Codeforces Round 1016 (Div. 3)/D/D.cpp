#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll F[61];

ll query_1 (ll x, ll y, ll n) {
    if (n == 0) return 1;
    ll L = 1ll << n, cnt = L * L / 4;
    if (x <= L / 2 && y <= L / 2)
        return query_1(x, y, n - 1);
    if (x > L / 2 && y > L / 2)
        return query_1(x - L / 2, y - L / 2, n - 1) + cnt;
    if (x > L / 2 && y <= L / 2)
        return query_1(x - L / 2, y, n - 1) + cnt * 2;
    if (x <= L / 2 && y > L / 2)
        return query_1(x, y - L / 2, n - 1) + cnt * 3;
    assert(0);
}

pair<ll, ll> query_2 (ll d, ll n) {
    if (n == 0) return {1, 1};
    ll L = 1ll << n, cnt = L * L / 4;
    if (d <= cnt) {
        auto [x, y] = query_2(d, n - 1);
        return {x, y};
    }
    if (d <= cnt * 2) {
        auto [x, y] = query_2(d - cnt, n - 1);
        return {x + L / 2, y + L / 2};
    }
    if (d <= cnt * 3) {
        auto [x, y] = query_2(d - cnt * 2, n - 1);
        return {x + L / 2, y};
    }
    if (d <= cnt * 4) {
        auto [x, y] = query_2(d - cnt * 3, n - 1);
        return {x, y + L / 2};
    }
    assert(0);
}

void solve() {
    ll n; int q; cin >> n >> q;
    while (q--) {
        string op; cin >> op;
        if (op == "->") {
            ll x, y; cin >> x >> y;
            cout << query_1(x, y, n) << '\n';
        }
        else {
            ll d; cin >> d;
            auto [x, y] = query_2(d, n);
            cout << x << ' ' << y << '\n';
        }
    }
}

int main() {
    freopen ("D.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    for (int i = 0; i < 61; i++) {
        F[i] = (1LL << i);
    }

    int T; cin >> T;
    while (T--) solve();
    return 0;
}