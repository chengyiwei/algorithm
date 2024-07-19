#include <bits/stdc++.h>
using namespace std;
int main() {
    int P, Q; cin >> P >> Q;
    int n; cin >> n;
    vector<int> dp(n + 2, 0), a(n + 2); // dp[i] 表示到达 i 位置最大的能量
    for (int i = 1; i <= n; i++) cin >> a[i];
    dp[0] = P; dp[1] = a[1] + P - Q;
    for (int i = 2; i <= n + 1; i++) {
        if (dp[i - 1] < Q && dp[i - 2] < Q) return cout << "NO", 0;
        if (dp[i - 1] >= Q) dp[i] = max(dp[i], dp[i - 1] - Q + a[i]);
        if (dp[i - 2] >= Q) dp[i] = max(dp[i], dp[i - 2] - Q + a[i]);
    }
    cout << dp[n + 1] << '\n';
    return 0;
}