#include <bits/stdc++.h>
#define int long long
using namespace std;
const int TT = 998244353;
signed main() {
    freopen ("B.in", "r", stdin);
    ios::sync_with_stdio(false);
    int n, cnt = 0; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<array<int, 3>> dp(4, {0, 0, 0});
    for (int i = 1; i <= n; i++) {
        if (a[i] % 2) {
            dp[3] = {(dp[3][0] + dp[3][2] + dp[2][2]) % TT, (dp[3][1] + dp[3][0] + dp[2][0]) % TT, dp[3][2]};
            dp[2][0] = (dp[2][0] + dp[1][2]) % TT; dp[2][1] = (dp[2][1] + dp[1][0]) % TT;
            dp[1][0] = (dp[1][0] + 1) % TT; dp[1][1] = (dp[1][1] + 1) % TT;
        }
        else {
            cnt += 1;
            dp[3][2] = (dp[3][2] + dp[3][1] + dp[2][1]) % TT;
            dp[2][2] = (dp[2][2] + dp[1][1]) % TT;
            dp[1][2] = (dp[1][2] + 1) % TT;
        }
    }
    int ans1 = (dp[3][0] + dp[3][1] + dp[3][2]) % TT;
    int ans2 = 1;
    for (int i = 1; i <= cnt; i++) 
        ans2 = (ans2 * 2) % TT;
    ans2 = ((ans2 - cnt - 1 - 1ll * cnt * (cnt - 1) / 2) % TT + TT) % TT;
    cout << (ans1 + ans2) % TT << '\n';
    return 0;
}