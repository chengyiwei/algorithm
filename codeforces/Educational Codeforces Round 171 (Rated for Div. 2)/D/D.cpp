#include <bits/stdc++.h>
#define int long long

using ll = long long;

void solve() {
    int n; std::cin >> n;
    std::vector<int> a(n + 1);
    std::vector<ll> sum(n + 1, 0), ksum(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
        ksum[i] = ksum[i - 1] + a[i] * i;
    }

    auto calc_S = [&] (int i, int j) -> ll {
        ll tmp1 = sum[j] - sum[i - 1];
        ll tmp2 = ksum[j] - ksum[i - 1];
        ll ret = 1ll * (j + 1) * tmp1 - tmp2;
        return ret;
    };

    std::vector<ll> S(n + 1, 0), SS(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        S[i] = calc_S(i, n);
        SS[i] = SS[i - 1] + S[i];
    }

    std::vector<ll> ed(n + 1, 0);
    for (int i = 1; i <= n; i++)
        ed[i] = ed[i - 1] + (n - i + 1);

    auto calc = [&] (int r) {
        if (r == 0) return 0ll;
        int pos = std::lower_bound(ed.begin(), ed.end(), r) - ed.begin();
        pos -= 1; int d = r - ed[pos];
        ll ans_pre = SS[pos];
        ll ans_now = calc_S(pos + 1, pos + 1 + d - 1);
        return ans_pre + ans_now;
    };

    int q; std::cin >> q;
    for (int i = 1; i <= q; i++) {
        int l, r; std::cin >> l >> r;
        ll ans = calc(r) - calc(l - 1);
        std::cout << ans << '\n';
    }
}

signed main() {
    freopen ("D.in", "r", stdin);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int T = 1;
    while (T--) solve();
    return 0;
}