#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
const ll TT = 2004;

signed main() {
    int n, L, R; cin >> n >> L >> R;
    ll Fac = 1;
    vector<ll> m(n + 1);
    for (int i = 1; i <= n; i++) cin >> m[i], Fac = Fac * i;

    ll ans = 0;

    auto C = [&] (int n_, int m) {
        ll now_mod = Fac * TT;
        ll res = 1;
        for (int i = n_ - m + 1; i <= n_; i++) {
            res = res * i % now_mod;
        }
        return res / Fac % TT;
    };

    auto dfs = [&](auto &&dfs, int pos, int a, int k, int max_k) -> void {
        if (k > max_k) return ;
        if (pos == n + 1) {
            ans = ((ans + 1ll * a * C(n + max_k - k, n)) + TT) % TT;
            return ;
        }
        dfs(dfs, pos + 1, a, k, max_k);
        dfs(dfs, pos + 1, -a, k + m[pos] + 1, max_k);
    };

    auto calc = [&] (int max_k) -> ll {
        ans = 0;
        dfs(dfs, 1, 1, 0, max_k);
        return (ans % TT + TT) % TT;
    };
    
    cout << ((calc(R) - calc(L - 1)) % TT + TT) % TT << '\n';
    return 0;
}