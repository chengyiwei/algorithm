#include <bits/stdc++.h>
using namespace std;
#define int long long
const int TT = 998244353;
signed main() {
    freopen ("D.in", "r", stdin);
    ios::sync_with_stdio(false);
    int N, K; cin >> N >> K;
    vector<int> huiwen(1 << K, 0);

    auto check = [&] (int x) {
        vector<int> cnt(K, 0);
        for (int i = 0; i < K; i++)
            if (x & (1 << i))
                cnt[i] = 1;
        for (int i = 0; i < K; i++)
            if (cnt[i] != cnt[K - i - 1])
                return 0;
        return 1;
    };

    for (int i = 0; i < (1 << K); i++)
        huiwen[i] = check(i);
    
    vector dp(N + 1, vector<int>(1 << K, 0));
    
    string s; cin >> s;
    vector<int> p;
    dp[0][0] = 1;
    for (int i = 0; i < N; i++) {
        p.clear();
        if (s[i] == 'A') p.push_back(0);
        if (s[i] == 'B') p.push_back(1);
        if (s[i] == '?') p.push_back(0), p.push_back(1);
        for (int j = 0; j < (1 << (K - 1)); j++) {
            for (auto _ : p) {
                if (i + 1 >= K && huiwen[(j << 1) | _] == 1)
                    continue;
                int nxt = ((j << 1) | _) % (1 << K - 1);
                dp[i + 1][nxt] = (dp[i + 1][nxt] + dp[i][j]) % TT;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < (1 << K - 1); i++)
        ans = (ans + dp[N][i]) % TT;
    cout << ans << endl;
    return 0;
}