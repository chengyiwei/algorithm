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
                ll tmp = 0;
                for (int k = l; k <= r; k++) {
                    if (T[k] == S[i])
                        tmp = (tmp + 1ll * get_(i, l, k - 1) * get_(i, k + 1, r)) % TT;
                }
                dp[i][l][r] = tmp;
            }
    cout << dp[n][1][m] << '\n';
    return 0;
}