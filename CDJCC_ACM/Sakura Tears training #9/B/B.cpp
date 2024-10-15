#include <bits/stdc++.h>

using ll = long long;

constexpr ll TT = 1e9 + 7;
constexpr int V = 1024;

ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % TT;
        a = a * a % TT;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n; std::cin >> n;
    std::vector<ll> a(n + 1), p(n + 1);
    for (int i = 1; i <= n; i++) std::cin >> a[i];
    for (int i = 1; i <= n; i++) std::cin >> p[i];

    ll Inv = qpow(10000, TT - 2);

    std::vector<std::vector<ll>> dp(2, std::vector<ll>(V, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        fill(dp[i & 1].begin(), dp[i & 1].end(), 0);
        ll now_p = p[i] * Inv % TT, now_q = (1 - now_p + TT) % TT;
        for (int j = 0; j < V; j++) {
            dp[i & 1][j] = (dp[i & 1][j] + dp[1 - i & 1][j] * now_q % TT) % TT;
            dp[i & 1][j] = (dp[i & 1][j] + dp[1 - i & 1][j ^ a[i]] * now_p % TT) % TT;
        }
    }

    ll ans = 0;
    for (int i = 0; i < V; i++) 
        ans = (ans + dp[n & 1][i] * qpow(i, 2) % TT) % TT;

    std::cout << ans << '\n';
}

int main() {
    freopen ("B.in", "r", stdin);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int T; std::cin >> T;
    while (T--) solve();
    return 0;
}