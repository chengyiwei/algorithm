#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void calc(vector<ll> &a, vector<vector<ll> > &dp) {
    int n = a.size() - 1;
    vector<vector<ll> > g(n + 1, vector<ll>(n + 1, 0));
    for (int x = 1; x <= n; x++) {
        g[x][0] = a[x];
        for (int j = 1; j <= n; j++) {
            g[x][j] = g[x][j - 1];
            if (x + j <= n) g[x][j] += a[x + j];
        }
        
    }
    for (int s = 1; s <= n; s++)
        for (int j = 1; j <= 2 * n; j++)  {
            dp[s][j] = max(dp[s][j], max(dp[s - 1][j - 1], g[s][min(j, n)]));
        }
}   


int main() {
    freopen ("D.in", "r", stdin);
    freopen ("D.out", "w", stdout);
    int n; cin >> n;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<vector<ll> > dp(n + 1, vector<ll>(2 * n + 1, 0));
    calc(a, dp);
    reverse(a.begin() + 1, a.end());
    reverse(dp.begin() + 1, dp.end());
    calc(a, dp);
    reverse(dp.begin() + 1, dp.end());


    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= 2 * n; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << '\n';
    // }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ll now = 0;
        for (int j = 1; j <= 2 * n; j++) 
            now ^= 1ll * j * dp[i][j];
        ans ^= (now + i);
    }
    cout << ans << '\n';
    return 0;
}