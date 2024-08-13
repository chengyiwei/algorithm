#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
using namespace std;
typedef long long ll;

int cnt = 0;

unordered_map<ll, ll> mp;
unordered_map<ll, ll> mp2;

inline ll S(ll x) {
    if (mp.count(x)) return mp[x];
    ll res = 0;
    while (x) {
        // cnt += 1;
        res += x % 10;
        x /= 10;
    }
    return mp[x] = res;
}


void solve() {
    ll n; cin >> n;
    if (mp2[n]) {
        cout << mp2[n] << '\n';
        return;
    }
    ll n_ = n;
    int siz = 0, tp = 0, t;
    while (n) {
        tp += tp % 10; 
        if (n < 10) t = n; 
        n /= 10; siz += 1; 
    } // siz 表示 n 的位数
    tp = max(tp, (siz - 1) * 9 + t - 1); // tp 表示 n 的各位和
    int ans = 0; n = n_;
    ll l = 1, r = 0, Up, Dn;
    while (l <= n) {
        r = n / (n / l);
        Up = n / l, Dn = (n - tp + r - 1) / r;
        cnt += 1;
        if (Up >= Dn) {
            for (ll m = Dn; m <= Up; m += 1) {
                ll Sm = S(m);
                if (Sm < m && (n - Sm) % m == 0 && (n - Sm) / m >= l && (n - Sm) / m <= r) {
                    ans += 1;
                }
            }
        }
        l = r + 1;
    }
    mp2[n] = ans;
    cout << ans << '\n';
}

int main() {
    freopen ("E.in", "r", stdin);
    freopen ("E.out", "w", stdout);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) solve();
    cout << clock() << '\n';
    cout << cnt << '\n';
    return 0;
}