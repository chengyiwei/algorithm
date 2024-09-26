#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    freopen ("L.in", "r", stdin);
    freopen ("L0.out", "w", stdout);
    // ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T_; scanf("%d", &T_);
    while (T_--) {
        ll T; scanf("%d", &T);
        ll k = sqrt(2 * T);
        ll ans_up = -1, ans_dn = -1;
        for (ll k_ = max(k - 1, 1ll); k_ <= min(k + 1, T); k_++) {
            ll up = k_ * k_ - k_ + 2 * T;
            ll dn = 2 * k_;
            ll g = __gcd(up, dn); up /= g, dn /= g;
            if (ans_up == -1 || 1.0 * up / dn < 1.0 * ans_up / ans_dn) 
                ans_up = up, ans_dn = dn;
        }
        printf("%lld %lld\n", ans_up, ans_dn);
        // cout << ans_up << ' ' << ans_dn << '\n';
    }
    // cout << clock() << endl;
    return 0;
}