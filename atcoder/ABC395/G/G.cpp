#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 0x3f3f3f3f3f3f3f3f;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


    int N, K; cin >> N >> K;
    vector<vector<int>> g(N + 1, vector<int>(N + 1, INF));
    vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(N + 1, vector<int>(1 << (K + 1), INF)));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> g[i][j];
        }
    }
    for (int i = 1; i <= N; i++) g[i][i] = 0;
    
    for (int k = 1; k <= N; k++) 
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K; j++)
            dp[i][j][1 << (j - 1)] = 0;
        dp[i][i][1 << K] = 0;
    }
    
    for (int S = 0; S < (1 << (K + 1)); S++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                for (int S_ = S; S_; S_ = (S_ - 1) & S) {
                    dp[i][j][S] = min(dp[i][j][S], dp[i][j][S_] + dp[i][j][S ^ S_]);
                }
            }

            for (int j = 1; j <= N; j++)
                for (int k = 1; k <= N; k++) {
                    dp[i][j][S] = min(dp[i][j][S], dp[i][k][S] + g[k][j]);
                }
        }
    }

    int Q; cin >> Q;
    while (Q--) {
        int S, T; cin >> S >> T;
        int ans = dp[S][T][(1 << (K + 1)) - 1];
        cout << ans << '\n';
    }
    return 0;
}