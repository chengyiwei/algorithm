#include <bits/stdc++.h>

using ll = long long;
const ll INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n; std::cin >> n;
    std::vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) std::cin >> a[i];

    if (n == 1) {
        std::cout << 1 << '\n';
        return ;
    }

    ll ans = INF;

    if (n % 2 == 0) {
        ll now = 1;
        for (int i = 1; i + 1 <= n; i += 2) {
            ll d = a[i + 1] - a[i];
            now = std::max(now, d);
        }
        ans = std::min(ans, now);
    }
    else {
        for (int j = 2; j <= n; j++) {
            ll now = 1;
            for (int i = 1; i + 1 <= j - 1; i += 2) 
                now = std::max(now, a[i + 1] - a[i]);
            for (int i = j; i + 1 <= n; i+= 2)
                now = std::max(now, a[i + 1] - a[i]);
                
            ans = std::min(ans, now);
        }
    }
    std::cout << ans << '\n';
}

int main() {
    freopen ("B.in", "r", stdin);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);
    int T; std::cin >> T;
    while (T--) solve();
}