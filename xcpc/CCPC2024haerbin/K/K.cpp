#include <bits/stdc++.h>

using ll = long long;

struct Node {
    ll w, l, r;
    bool operator <(const Node B) const {
        return w > B. w;
    }
};

int main() {
    freopen ("K.in", "r", stdin);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    ll n, m; std::cin >> n >> m;
    std::vector<Node> a(n + 1);
    long long sum_l = 0, sum_l_ans = 0;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i].w >> a[i].l >> a[i].r;
        sum_l += a[i].l;
        sum_l_ans += 1ll * a[i].l * a[i].w;
    }

    ll ans = 0;
    ll m_ = m - sum_l;
    sort(a.begin() + 1, a.end());
    std::vector<ll> p = {0}, sum_p = {0};
    for (int i = 1; i <= n; i++) {
        ll now_m = m_ + a[i].l;
        int pos = std::upper_bound(p.begin(), p.end(), now_m) - p.begin(); pos -= 1;
        ll tmp = now_m - p[pos], now_ans;

        if (pos == i - 1)
            now_ans = sum_l_ans - a[i].l * a[i].w + sum_p[pos] + tmp * a[i].w;
        else
            now_ans = sum_l_ans - a[i].l * a[i].w + sum_p[pos] + tmp * a[pos + 1].w;
        
        ans = std::max(ans, now_ans);

        p.push_back(p.back() + a[i].r - a[i].l);
        sum_p.push_back(sum_p.back() + (a[i].r - a[i].l) * a[i].w);
    }

    std::cout << ans << '\n';
    return 0;
}