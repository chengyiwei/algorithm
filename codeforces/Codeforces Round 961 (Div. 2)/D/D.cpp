#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

void solve() {
    int N, C, K; cin >> N >> C >> K;
    string s; cin >> s; s = " " + s;
    vector<int> cnt(C, 0), A(1 << C, 0);

    auto add = [&] (void) -> void {
        int res = 0;
        for (int i = 0; i < C; i++)
            if (cnt[i] > 0) res |= (1 << i);
        A[res] = 1;
    };

    auto rev = [&] (int x) -> int {
        int res = 0;
        for (int i = 0; i < C; i++)
            if (((x >> i) & 1) == 0) res |= (1 << i); 
        return res;
    };

    for (int i = 1; i <= K; i++) cnt[s[i] - 'A'] += 1; add();
    for (int i = K + 1; i <= N; i++) {cnt[s[i - K] - 'A'] -= 1; cnt[s[i] - 'A'] += 1; add();}
    A[1 << (s[N] - 'A')] = 1;
    vector<int> dp(1 << C, 0);
    for (int mask = 0; mask < (1 << C); mask++)
        dp[mask] = A[mask];

    for (int i = 0; i < C; i++)
        for (int mask = 0; mask < (1 << C); mask++)
            if ((mask >> i) & 1) dp[mask] |= dp[mask ^ (1 << i)];

    int ans = INF;
    for (int mask = 0; mask < (1 << C); mask++)
        if (dp[mask] == 0) {
            ans = min(ans, C - __builtin_popcount(mask));
        }
    cout << ans << '\n';
    return;
}

int main() {
    freopen ("D.in", "r", stdin);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}