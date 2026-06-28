#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int V[17] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 5, 10, 50, 100, 500, 1000};

void solve() {
    string s; cin >> s; int n = s.size(); reverse(s.begin(), s.end());
    array<int, 17> cost;
    for (int i = 0; i < 17; i++) cin >> cost[i];
    vector dp(n + 1, vector<int>(112, inf));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        int now = s[i] - '0';
        for (int k = 0; k <= 111; k++) {
            for (int j = 0; j < 17; j++) {
                if ((k + V[j]) % 10 == now) {
                    int nxt = (k + V[j]) / 10;
                    if (nxt > 111) continue;
                    dp[i + 1][nxt] = min(dp[i + 1][nxt], dp[i][k] + cost[j]);
                }
            }
        }
    }
    int ans = dp[n][0];
    if (n - 1 > 0)
        ans = min(ans, dp[n - 1][s[n - 1] - '0']);
    if (n - 2 > 0) {
        int x = (s[n - 1] - '0') * 10 + s[n - 2] - '0';
        if (x <= 111)
            ans = min(ans, dp[n - 2][x]);
    }
    if (n - 3 > 0) {
        int x = (s[n - 1] - '0') * 100 + (s[n - 2] - '0') * 10 + s[n - 3] - '0';
        if (x <= 111)
            ans = min(ans, dp[n - 3][x]);
    }
    cout << ans << '\n';
}

int main() {
    freopen ("J.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}