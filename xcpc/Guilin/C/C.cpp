#include <bits/stdc++.h>

constexpr int TP = 30;
constexpr int TT = 998244353;

void solve() {
    int n; std::cin >> n;
    std::vector<int> a(n + 1, 0);

    std::vector<int> c(TP, 0), p(TP, 0);
    int cnt = 0;
    auto insert = [&] (int x) -> void {
        for (int i = TP - 1; i >= 0; i--) {
            if (x >> i & 1) {
                if (!p[i]) {p[i] = x; return ;}
            }
            x ^= p[i];
        }
        if (!x) cnt += 1;
    };

    for (int i = 1; i <= n; i++) std::cin >> a[i];
    sort(a.begin() + 1, a.end());

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = (ans + cnt) % TT;
        insert(a[i]);
        ans = (ans + cnt) % TT;
    }
    std::cout << ans << "\n";
}

int main() {
    freopen ("C.in", "r", stdin);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);
    int T; std::cin >> T;
    while (T--) solve();
    return 0;
}