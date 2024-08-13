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

void solve() {
    ll n; cin >> n;
    int ans = 0;
    for (int m = 1; m <= n; m++) {
        if (n % m == S(m)) {
            // cout << m << ' ';
            ans += 1;
        }
    }
    cout << ans << '\n';
}

int main() {
    freopen ("E.in", "r", stdin);
    freopen ("E0.out", "w", stdout);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}