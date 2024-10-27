#include <bits/stdc++.h>

constexpr int N = 1e5 + 5, V = 3e5 + 5;
constexpr int INF = 0x3f3f3f3f;

bool vis[V];

void init() {
    vis[1] = 1;
    for (int i = 2; i < V; i++) {
        for (int j = 2; i * j < V; j++)
            vis[i * j] = 1;
    }
}

bool is_prime(int x) {
    return !vis[x];
}

int dp[N][4];

int main() {
    freopen ("F.in", "r", stdin);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);
    init();

    int n; std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) std::cin >> a[i];

    memset(dp, 0x3f, sizeof dp);
    dp[1][0] = 0; dp[1][1] = 1; dp[1][2] = 1; dp[1][3] = 1;
    for (int i = 2; i <= n; i++) {
        
        int tmp = INF;
        if (is_prime(a[i] + a[i - 1])) tmp = std::min(tmp, dp[i - 1][0]);
        if (a[i] % 2 == 1) tmp = std::min(tmp, dp[i - 1][2]);
        if (a[i] % 2 == 0) tmp = std::min(tmp, dp[i - 1][1]);
        if (is_prime(a[i] + 1)) tmp = std::min(tmp, dp[i - 1][3]);
        dp[i][0] = tmp;

        tmp = INF;
        if (a[i - 1] % 2 == 0) tmp = std::min(tmp, dp[i - 1][0] + 1);
        tmp = std::min(tmp, dp[i - 1][2] + 1);
        dp[i][1] = tmp;

        tmp = INF;
        if (a[i - 1] % 2 == 1) tmp = std::min(tmp, dp[i - 1][0] + 1);
        tmp = std::min(tmp, dp[i - 1][1] + 1);
        tmp = std::min(tmp, dp[i - 1][3] + 1);
        dp[i][2] = tmp;

        tmp = INF;
        if (is_prime(a[i - 1] + 1)) tmp = std::min(tmp, dp[i - 1][0] + 1);
        tmp = std::min(tmp, dp[i - 1][2] + 1);
        tmp = std::min(tmp, dp[i - 1][3] + 1);
        dp[i][3] = tmp;
    }
    int ans = std::min({dp[n][0], dp[n][1], dp[n][2], dp[n][3]});
    std::cout << ans << '\n';
    return 0;
}