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
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i].w >> a[i].l >> a[i].r;
    }

    auto calc = [&] (std::vector<Node> a) {
        sort(a.begin() + 1, a.end());
        ll sum_l = 0, sum_l_ans = 0;
        for (int i = 1; i <= n; i++) {
            sum_l += a[i].l, sum_l_ans += a[i].l * a[i].w;
        }
        ll m_ = m - sum_l;
        ll ret = sum_l_ans;
        for (int i = 1; i <= n; i++) {
            if (m_ > a[i].r - a[i].l) {
                ret += (a[i].r - a[i].l) * a[i].w;
                m_ -= a[i].r - a[i].l;
            }
            else {
                ret += m_ * a[i].w;
                m_ = 0;
                break;
            }
        }
        return ret;
    };

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        auto a_ = a;
        a_[i].l = 0, a_[i].r = m;
        ans = std::max(ans, calc(a_));
    }

    std::cout << ans << "\n";
    return 0;
}