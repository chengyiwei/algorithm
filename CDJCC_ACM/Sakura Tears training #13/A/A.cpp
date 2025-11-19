#include <bits/stdc++.h>
using namespace std;

void solve() {

    int n; cin >> n;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<long long> dp(n + 1, 0x3f3f3f3f3f3f3f3f);
    dp[1] = a[1]; dp[0] = 0;
    for (int i = 2; i <= n; i++) {
        dp[i] = min({
            dp[i - 1] + (a[i] - 1),
            dp[i - 2] + (a[i - 1]) + max((a[i] - (i - 1)), 0ll)
        });
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << i << ':' << dp[i] << ' ';
    // }
    cout << dp[n] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t; cin >> t;
    while (t--)  solve();

    return 0;
}