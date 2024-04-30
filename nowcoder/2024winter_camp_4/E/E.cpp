#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, k, ans;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen ("E.in","r", stdin);
    cin >> n >> k;
    vector<int> a(n + 1), s(n + 1, 0), dp(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i]; a[i] %= k;
        s[i] = s[i - 1] + a[i]; s[i] %= k;
    }
    map<int, int> mp; mp[0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        if (mp.find(s[i]) != mp.end()) {
            dp[i] = max (dp[i], mp[s[i]] + 1);
        }
        mp[s[i]] = dp[i];
    }
    cout << dp[n] << endl;
    return 0;
}