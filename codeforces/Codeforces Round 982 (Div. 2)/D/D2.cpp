#include <bits/stdc++.h>
using ll = long long ;
constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll TT = 1e9 + 7;

void solve() {
    int n, m; std::cin >> n >> m;
    std::vector<ll> a(n + 1), b(m + 1), sum(n + 1, 0);
    for (int i = 1; i <= n; i++)
        std::cin >> a[i], sum[i] = sum[i - 1] + a[i];
    for (int i = 1; i <= m; i++)
        std::cin >> b[i];

    std::vector dp(n + 1, std::vector<ll>(m + 1, INF));
    std::vector g(n + 1, std::vector<ll>(m + 1, 0));

    dp[0][0] = 0; g[0][0] = 1;
    for (int j = 1; j <= m; j++) {
        int i_ = 0, i_2 = 0;
        dp[0][j] = dp[0][j - 1]; g[0][j] = 1;
        std::vector<ll> sum_g(n + 1, 0);
        sum_g[0] = 1;
        for (int i = 1; i <= n; i++) {
            ll dp1 = dp[i][j - 1], g1 = (i != n ? g[i][j - 1] : 0 ), dp2 = INF, g2 = 0;
            while (i_ < i && sum[i] - sum[i_] > b[j]) i_++;
            i_2 = std::max(i_2, i_);
            while (i_2 < i && dp[i_][j] == dp[i_2][j]) i_2++; // 和 dp[i'][j] 值相同的
            if (i_ < i) {
                dp2 = dp[i_][j] + m - j;
                g2 = (i_2 - 1 >= 0 ? sum_g[i_2 - 1] : 0) - (i_ - 1 >= 0 ? sum_g[i_ - 1] : 0);
                g2 = (g2 % TT + TT) % TT;
            }

            if (dp1 < dp2) 
                dp[i][j] = dp1, g[i][j] = g1;
            else if (dp1 > dp2)
                dp[i][j] = dp2, g[i][j] = g2;
            else
                dp[i][j] = dp1, g[i][j] = g1 + g2;

            sum_g[i] = (sum_g[i - 1] + g[i][j]) % TT;
        }
    }

    ll ans = INF, ans_g = 0;

    for (int j = 1; j <= m; j++) {
        if (dp[n][j] < ans) {
            ans = dp[n][j];
            ans_g = g[n][j];
        } else if (dp[n][j] == ans) {
            ans_g = (ans_g + g[n][j]) % TT;
        }
    }

    if (ans >= INF)
        std::cout << -1 << "\n";
    else 
        std::cout << ans << " " << ans_g << "\n";
}

int main() {
    freopen ("D.in", "r", stdin);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int T; std::cin >> T;
    while (T--) solve();
}