#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int S(ll x) {
    int res = 0;
    while (x) {
        res += x % 10;
        x /= 10;
    }
    return res;
}

map<ll, int> mp;

void solve() {
    ll n ; cin >> n; 
    ll n_ = n;
    if (mp.count(n)) {
        cout << mp[n] << '\n';
        return;
    }
    int siz = 0, tp = 0, t;
    while (n) {
        tp += tp % 10; 
        if (n < 10) t = n; 
        n /= 10; siz += 1; 
    } // siz 表示 n 的位数
    tp = max(tp, (siz - 1) * 9 + t - 1); // tp 表示 n 的各位和
    int ans = 0; n = n_;
    ll l = 1, r = 0;
    set<ll> st;
    while (l <= n) {
        r = n / (n / l);
        ll Up = n / l, Dn = (n - tp + l - 1) / l;
        if (Up >= Dn) {
            for (ll m = Dn; m <= Up; m++) {
                auto Sm = S(m);
                if (Sm < m && (n - Sm) % m == 0) {
                    st.insert(m);
                }
            }
        }
        l = r + 1;
    }
    ans = st.size();
    mp[n_] = ans;
    // cout << n << " ";
    cout << ans << '\n';
}

int main() {
    freopen ("E.in", "r", stdin);
    // freopen ("E.out", "w", stdout);
    // ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) solve();
    // cout << clock() << '\n';
    return 0;
}