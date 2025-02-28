#include <bits/stdc++.h>    
using namespace std;

typedef long long ll;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<ll>> a(n + 1, vector<ll>(m + 1, 0));
    vector<ll> sum1(n + m + 1, 0), sum2(n + m + 1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cin >> a[i][j];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            sum1[i + j] += a[i][j];
            sum2[i - j + m] += a[i][j];
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ans = max(ans, sum1[i + j] + sum2[i - j + m] - a[i][j]);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}