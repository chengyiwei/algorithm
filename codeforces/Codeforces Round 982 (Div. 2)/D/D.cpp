#include <bits/stdc++.h>
using ll = long long ;
constexpr ll INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, m; std::cin >> n >> m;
    std::vector<ll> a(n + 1), b(m + 1), sum(n + 1, 0);
    for (int i = 1; i <= n; i++)
        std::cin >> a[i], sum[i] = sum[i - 1] + a[i];
    for (int i = 1; i <= m; i++)
        std::cin >> b[i];

    std::vector dp(n + 1, std::vector<ll>(m + 1, INF));

    for (int j = 1; j <= m; j++)
        dp[0][j] = 0;

    for (int j = 1; j <= m; j++) {
        int i_ = 0;
        for (int i = 1; i <= n; i++) {
            dp[i][j] = dp[i][j - 1];
            while (i_ < i && sum[i] - sum[i_] > b[j]) i_++;
            if (i_ < i) {
                dp[i][j] = std::min(dp[i][j], dp[i_][j] + m - j);
            }
        }
    }
    ll ans = INF;
    for (int j = 1; j <= m; j++)
        ans = std::min(ans, dp[n][j]);
    std::cout << (ans >= INF? -1ll : ans) << '\n';
}

int main() {
    freopen ("D.in", "r", stdin);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int T; std::cin >> T;
    while (T--) solve();
}