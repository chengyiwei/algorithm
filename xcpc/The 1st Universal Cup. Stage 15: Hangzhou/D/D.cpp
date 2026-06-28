#include <bits/stdc++.h>

using llsi = long long signed int;

constexpr int N = 3;
constexpr llsi MOD = 998244353;

int n;

inline llsi shift (llsi s, int y) {
    s |= s << y | s >> (n - y);
    s &= (1 << n) - 1;
    return s;
}

llsi w[N];
llsi dp[1 << N];

int main() {
    freopen ("D.in", "r", stdin);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);
    std::cin >> n;
    for (int i = 0; i < n; i++) std::cin >> w[i];    
    memset(dp, 0x3f, sizeof dp);
    dp[1] = 0;
    for (int i = 1; i < (1 << n); i++) {
        llsi sta = i;
        for (int j = 1; j < n; j++) {
            llsi nxt = shift(sta, n - j);
            dp[nxt] = std::min(dp[nxt], dp[sta] + w[j]);
        }
    }

    for (int i = (1 << n) - 1; ~i; i--) {
        llsi sta = i;
        for (int j = 0; j < n; j++)
            if (!(sta >> j & 1)) {
                llsi nxt = sta | 1 << j;
                dp[sta] = std::min(dp[nxt], dp[sta]);
            }
    }

    // for (int i = 1; i < (1 << n); i++) {
    //     std::cout << "dp[" << i << "] = " << dp[i] << std::endl;
    // }

    llsi ans = 0;
    for (int i = 1; i < (1 << n); i++) ans = (ans + dp[i] * i) % MOD;
    std::cout << ans << std::endl;
    return 0;
}