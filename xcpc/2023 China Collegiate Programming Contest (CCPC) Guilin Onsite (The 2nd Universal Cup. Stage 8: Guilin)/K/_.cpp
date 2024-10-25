#include<bits/stdc++.h>

using ll = long long;

const ll INF = 1e16;

int main() {
    freopen ("M.in", "r", stdin);

    ll ans  = -INF;

    for (int n = 1; n <= 180; n++) {
        int m = 180 / n;
        ll Fac = 1;
        for (int i = 1; i <= m; i++) {
            Fac = Fac * i;
            if (Fac > INF) break;;
        }
        ll Mi = 1;
        for (int i = 1; i <= n; i++) {
            Mi = Mi << 1;
            if (Mi > INF) break;
        }
        ans = std::max(std::min(Mi , Fac), ans);
    }
    std::cout << ans ;
    return 0;
}