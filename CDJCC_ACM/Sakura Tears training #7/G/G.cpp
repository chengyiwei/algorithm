#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, m, r; cin >> n >> m >> r;
    vector<set<int>> a(n + 1), b(m + 1);
    vector dp(n + 1, vector<vector<int>>(m + 1, vector<int>(r + 10, 0)));

    for (int i = 1; i <= r; i++) {
        int t, op, pos; cin >> t >> op >> pos;
        if (op == 1) a[pos].insert(t);
        if (op == 2) b[pos].insert(t);
    }

    int up = min((a[0].lower_bound(1) == a[0].end() ? r + 1 : *a[0].lower_bound(1)),
                 (b[0].lower_bound(1) == b[0].end() ? r + 1 : *b[0].lower_bound(1)));

    up = min(up, r + 1);
    for (int k = 0; k < up; k++) dp[0][0][k] = 1;

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            for (int k = 0; k <= r; k++) {
                up = min((a[i].lower_bound(i + j + k) == a[i].end() ? r + 1 : *a[i].lower_bound(i + j + k) - i - j),
                         (b[j].lower_bound(i + j + k) == b[j].end() ? r + 1 : *b[j].lower_bound(i + j + k) - i - j));

                if (up == k) continue;
                if (i > 0) dp[i][j][k] |= dp[i - 1][j][k];
                if (j > 0) dp[i][j][k] |= dp[i][j - 1][k];
                if (k > 0) dp[i][j][k] |= dp[i][j][k - 1];
            } 
    
    // for (int i = 0; i <= n; i++) 
    //     for (int j = 0; j <= m; j++)
    //         for (int k = 0; k <= r; k++) {
    //             printf("dp[%d][%d][%d] = %d\n", i, j, k, dp[i][j][k]);    
    //         }

    for (int k = 0; k <= r; k++)
        if (dp[n][m][k]) {
            cout << n + m + k << '\n';
            return ;
        }
    
    cout << -1 << '\n';
    return ;
}

signed main() {
    freopen ("G.in", "r", stdin);
    freopen ("G.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tt; cin >> tt;
    while (tt--) solve();
    return 0;
}