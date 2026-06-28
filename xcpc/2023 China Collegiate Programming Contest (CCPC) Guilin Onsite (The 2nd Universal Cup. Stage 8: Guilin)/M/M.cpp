#include<bits/stdc++.h>

using ll = long long;
constexpr int INF = 0x3f3f3f3f;


int main() {
    freopen ("M.in", "r", stdin);

    int n; std::cin >> n;
    std::vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) std::cin >> a[i] >> b[i];

    auto check = [&] (int mid) -> bool {
        std::vector<int> sa(n + 1, 0), sb(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            sa[i] = sa[i - 1] + (a[i] >= mid ? 1 : -1);
            sb[i] = sb[i - 1] + (b[i] >= mid ? 1 : -1);
        }
        int ans = -INF, pre = 0;
        for (int i = 1; i <= n; i++) {
            if (sa[pre] - sb[pre] < sa[i] - sb[i])
                pre = i;
            ans = std::max(sa[pre] + sb[i] - sb[pre] + sa[n] - sa[i], ans);
        }
        return ans > 0;
    };

    int l = 1, r = 1e9 + 1;
    while (l + 1 < r) {
        int mid = (r - l >> 1) + l;
        if (check(mid)) l = mid;
        else r = mid;
    }
    std::cout << l << "\n";
    return 0;
}