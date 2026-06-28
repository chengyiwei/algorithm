#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105;
typedef long long ll;
ll dp[MAXN][MAXN][MAXN];
const int TT = 998244353;

ll get_(int i, int l, int r) {
    if (l > r) return 1ll;
    return dp[i][l][r];
}

int main() {
    freopen ("D.in", "r", stdin);
    ios::sync_with_stdio(false);
    string S, T; cin >> S >> T;
    int n = S.size(), m = T.size();
    S = " " + S; T = " " + T;
    for (int i = 1; i <= n; i++)
        for (int len = 1; len <= m; len++)
            for (int l = 1; l <= m; l++) {
                int r = l + len - 1;
                dp[i][l][r] = (dp[i][l][r] + dp[i - 1][l][r] * 2) % TT;
                for (int k = l; k <= r; k++) {
                    if (T[k] == S[i])
                        dp[i][l][r] = (dp[i][l][r] + get_(i - 1, l, k - 1) * get_(i - 1, k + 1, r)) % TT;
                }
                for (int k = l; k + 1 <= r; k++) {
                    dp[i][l][r] = (dp[i][l][r] + dp[i - 1][l][k] * dp[i - 1][k + 1][r]) % TT;
                }
            }
    cout << dp[n][1][m] << '\n';
    return 0;
}