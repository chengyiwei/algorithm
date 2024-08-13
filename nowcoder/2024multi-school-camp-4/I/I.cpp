#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

int main() {
    freopen ("I.in", "r", stdin);
    ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    map<pii, int> mp;
    for (int i = 1; i <= m; i++) {
        int x, y; cin >> x >> y;
        mp[{x, y}] = mp[{y, x}] = 1;
    }
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int pre = (i - 1) - dp[i - 1];
        for (int j = i - 1; j >= pre; j--) {
            if (mp[{i, j}] == 1) dp[i] += 1;
            else break;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
        ans += dp[i] + 1;
    cout << ans << '\n';
    return 0;
}