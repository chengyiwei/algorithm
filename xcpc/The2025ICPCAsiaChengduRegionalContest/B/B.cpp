#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int INF = 0x3f3f3f3f;

ll dp[65][65][30];
ll g[2][65][65];

void solve() {
    int n, m, k, R; cin >> n >> m >> k >> R;
    vector<int> a(n + 1), c(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i] >> c[i];

    for (int S1 = 0; S1 < (1 << n); S1++)
        for (int S2 = 0; S2 < (1 << n); S2++)
            for (int j = 0; j < 30; j++)
                dp[S1][S2][j] = -INF;
    

    for (int S1 = 0; S1 < (1 << n); S1++)
        for (int S2 = 0; S2 < (1 << n); S2++) {
            ll sum_cost = 0, val = 0;
            for (int i = 1; i <= n; i++) {
                ll cost = c[i] + ((S1 >> ((i - 1))) & 1 ? k : 0);
                if ((S2 >> (i - 1)) & 1) {
                    sum_cost += cost;
                    val += a[i];
                }
            }
            if (sum_cost <= m) dp[S1][S2][0] = val;
        }



    for (int j = 1; j < 30; j++) {
        for (int S1 = 0; S1 < (1 << n); S1++)
            for (int S2 = 0; S2 < (1 << n); S2++) {
                for (int S_ = 0; S_ < (1 << n); S_++) {
                    ll val = dp[S1][S_][j - 1] + dp[S_][S2][j - 1];
                    dp[S1][S2][j] = max(dp[S1][S2][j], val);
                }
            }
    }

    // for (int j = 0; j < 30; j++) {
    //     cout << "j = " << j << ":\n";
    //     for (int S1 = 0; S1 < (1 << n); S1++) {
    //         for (int S2 = 0; S2 < (1 << n); S2++) {
    //             cout << "dp[" << S1 << "][" << S2 << "][" << j << "] = " << dp[S1][S2][j] << " ";
    //         }
    //         cout << "\n";
    //     }
    // }


    for (int S1 = 0; S1 < (1 << n); S1++)
        for (int S2 = 0; S2 < (1 << n); S2++)
            g[1][S1][S2] = g[0][S1][S2] = -INF;
    g[0][0][0] = 0;
    int now = 0, nxt = 1;
    for (int j = 30 - 1; j >= 0; j--) if ((R >> j) & 1) {
        for (int S1 = 0; S1 < (1 << n); S1++)
            for (int S2 = 0; S2 < (1 << n); S2++) {
                for (int S_ = 0; S_ < (1 << n); S_++) {
                    ll val = g[now][S1][S_] + dp[S_][S2][j];
                    g[nxt][S1][S2] = max(g[nxt][S1][S2], val);
                }
            }
        swap(now, nxt);
        for (int S1 = 0; S1 < (1 << n); S1++)
            for (int S2 = 0; S2 < (1 << n); S2++)
                g[nxt][S1][S2] = -INF;
    }
    ll ans = 0;
    for (int S2 = 0; S2 < (1 << n); S2++) {
        ans = max(ans, g[now][0][S2]);
    }
    cout << ans << '\n';
}

int main() {
    // freopen ("B.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}