#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    // freopen ("B.in", "r", stdin);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    vector<vector<int>> mp(N + 1, vector<int>(N + 1, 0));
    for (int i = 1; i <= N; i++)
        for (int j = i + 1; j <= N; j++) {
            cin >> mp[i][j];
            mp[j][i] = mp[i][j];
        }

    vector<ll> dp(1 << N, -1);

    auto dfs = [&](auto &&dfs, int S) -> ll {
        if (dp[S] != -1) return dp[S];
        int cnt = 0;
        for (int i = 0; i < N; i++) cnt += (S >> i) & 1;
        if (cnt == 0 || cnt % 2 == 1) return dp[S] = 0;
        ll now = 0;
        for (int i = 0; i < N; i++) if ((S >> i) & 1)
            for (int j = i + 1; j < N; j++) if ((S >> j) & 1) {
                int S_ = S ^ (1 << i) ^ (1 << j);
                now = max(now, dfs(dfs, S_) + mp[i + 1][j + 1]);
            }
        return dp[S] = now;
    };

    ll ans = 0;
    for (int S = 0; S < (1 << N); S += 1) {
        ans = max(ans, dfs(dfs, S));
    }
    cout << ans << endl;
    return 0;
}