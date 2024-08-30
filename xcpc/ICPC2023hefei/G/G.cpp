#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 0x3f3f3f3f;
const int MAXN = 2e5 + 5;
int dp[MAXN][6][2];

int main() {
    // freopen ("G.in", "r", stdin);
    ios::sync_with_stdio(false);
    int n, m, k; cin >> n >> m >> k;
    string s; cin >> s; s = " " + s;
    vector<int> pre(n + 1, 0);
    for (int i = 1; i <= n; i++) 
        pre[i] = pre[i - 1] + (s[i] == '0');
    
    int l = 0, r = n + 1;

    auto check = [&] (int x) {
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= k; j++)
                dp[i][j][0] = dp[i][j][1] = INF;

        dp[0][0][0] = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 0; j <= k; j++) {
                if (s[i] == '0') {
                    dp[i][j][0] = min({dp[i][j][0], dp[i - 1][j][0], dp[i - 1][j][1]});
                    dp[i][j][1] = min({dp[i][j][1], dp[i - 1][j][1] + 1});
                }
                else {
                    dp[i][j][0] = min({dp[i][j][0], dp[i - 1][j][0]});
                    dp[i][j][1] = min({dp[i][j][1], dp[i - 1][j][1]});
                }
                if (i >= x && j > 0) 
                    dp[i][j][1] = min({dp[i][j][1], dp[i - x][j - 1][0] + pre[i] - pre[i - x]});
            }
        return min(dp[n][k][0], dp[n][k][1]) <= m;
    };

    while (l + 1 < r) {
        int mid = (l + r) >> 1;
        if (check (mid)) l = mid;
        else r = mid;
    }
    if (l <= 0) cout << -1 << '\n';
    else cout << l << '\n';
    return 0;
}