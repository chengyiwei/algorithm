#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e12 + 1;

void solve() {
    vector<ll> a(6); a[0] = 0;
    ll ret = 0, now; 
    for (int i = 1; i <= 5; i++) cin >> a[i];

    auto update = [&] (ll x) {
        for (int i = 1; i <= 5; i++) {
            auto need = min(x, a[i]);
            a[i] -= need; x -= need;
        }
    };

    now = a[3] / 2; a[3] -= now * 2; ret += now;
    now = min(a[2], a[4]); a[2] -= now; a[4] -= now; ret += now;
    
    ll L = 0, R = a[5] + 1;
    while (L + 1 < R) {
        auto check = [&] (ll x) {
            if (x > a[5]) return false;
            vector<ll> b = a;
            b[5] -= x;
            ll sum = b[1] + b[2] + b[3] + b[4] + b[5];
            if (sum < x) return false;
            return true;
        };
        ll mid = (L + R) / 2;
        if (check (mid)) L = mid;
        else R = mid;
    }
    now = L; ret += now; a[5] -= now; update(now);

    L = 0, R = a[4] + 1;
    while (L + 1 < R) {
        auto check = [&] (ll x) {
            if (x > a[4]) return false;
            vector<ll> b = a;
            b[4] -= x;
            ll sum = b[1] + b[2] + b[3] + b[4] + b[5];
            if (sum < x * 2) return false;
            return true;
        };
        ll mid = (L + R) / 2;
        if (check (mid)) L = mid;
        else R = mid;
    }
    now = L; ret += now; a[4] -= now; update(2 * now);

    L = 0, R = min(a[2], a[3]) + 1;
    while (L + 1 < R) {
        auto check = [&] (ll x) {
            if (x > min(a[2], a[3])) return false;
            vector<ll> b = a;
            b[2] -= x; b[3] -= x;
            ll sum = b[1] + b[2] + b[3] + b[4] + b[5];
            if (sum < x) return false;
            return true;
        };
        ll mid = (L + R) / 2;
        if (check (mid)) L = mid;
        else R = mid;
    }
    now = L; ret += now; a[2] -= now; a[3] -= now; update(now);

    now = (a[1] + 2 * a[2] + 3 * a[3]) / 6;
    ret += now;
    cout << ret << '\n';
}


int main() {
    freopen ("B.in", "r", stdin);
    freopen ("B0.out", "w", stdout);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) solve();
    return 0;    
}