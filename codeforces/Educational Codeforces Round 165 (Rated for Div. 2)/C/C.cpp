#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

void solve() {
    int n, k; scanf ("%d %d\n", &n, &k);
    vector<vector<ll> > dp (n + 1, vector<ll> (k + 1, INF));
    vector<int> a(n + 1);
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) 
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= k; j++)
            for (int pre = 0; pre + j <= k && pre <= i - 1; pre ++)
                for (int nxt = 0; pre + nxt + j <= k && i + nxt <= n; nxt ++) {
                    dp[i + nxt][j + pre + nxt] = min(dp[i + nxt][j + pre + nxt], dp[i - pre - 1][j] + 1ll * (pre + nxt + 1) * a[i]);
                }
    printf ("%lld\n", *min_element(dp[n].begin(), dp[n].end()));
}

int main() {
    freopen ("C.in", "r", stdin);
    freopen ("C.out", "w", stdout);
    int t; scanf("%d", &t);
    while (t--) solve();
    return 0;
}