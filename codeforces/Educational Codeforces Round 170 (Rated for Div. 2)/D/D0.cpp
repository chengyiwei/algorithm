#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> v(n + 2, 0);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    n += 1; m += 1;
    vector<int> p(m + 1, 0), q(m + 1, 0);
    vector<vector<int>> dp(m + 1, vector<int>(m + 1, 0));

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (v[i] > 0) p[v[i]]++;
        else if (v[i] < 0) q[-v[i]]++;
        else {
            for (int j = 1; j <= m; j++) p[j] += p[j - 1], q[j] += q[j - 1];
            cnt += 1;

            for (int x = 0; x <= cnt; x++) {
                int y = cnt - x;
                if (x - 1 >= 0)
                    dp[x][y] = max(dp[x][y], dp[x - 1][y] + p[x - 1] + q[y]);
                if (y - 1 >= 0)
                    dp[x][y] = max(dp[x][y], dp[x][y - 1] + p[x] + q[y - 1]);
            }

            fill(p.begin(), p.end(), 0); fill(q.begin(), q.end(), 0);
        }
    }

    int ans = 0;
    for (int x = 0; x <= cnt; x++) {
        int y = cnt - x;
        ans = max(ans, dp[x][y]);
    }
    cout << ans << '\n';
}

int main() {
    freopen ("D.in", "r", stdin);
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}