#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

void solve() {
    int n, k; cin >> n >> k;
    int g = 0;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        g = __gcd(g, x);
    }

    if (n == 1) {
        cout << (k <= g ? k - 1 : k) << '\n';
        return ;
    }

    ll L = -1, R = 1e18;
    
    auto check = [&] (ll x) -> bool {
        ll cnt = 0;
        ll num = x / g + 1;
        cnt = x - min(n, num);
        return cnt >= k - 1;
    };


    while (L + 1 < R) {
        ll mid = (L + R) >> 1;
        if (check(mid)) R = mid;
        else L = mid;
    }
    cout << R << '\n';
}

signed main() {
    freopen ("B.in", "r", stdin);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}